// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWords.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    for (const auto Word : Words)
        if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word) && Word != "hint")
            SecretWordList.Emplace(Word);

    SecretWordListSize = SecretWordList.Num();

    InitGame();
}

void UBullCowCartridge::InitGame()
{
    GameOver = false;
    SecretWord = SecretWordList[FMath::RandRange(0, SecretWordListSize - 1)];
    // always useful to know how to log
    // https://subscription.packtpub.com/book/game_development/9781785885549/1/ch01lvl1sec20/ue4-logging-with-ue-log
    UE_LOG(LogTemp, Warning, TEXT("Hidden word is: %s"), *SecretWord);
    int32 Index = 0;

    for (auto Letter : SecretWord)
        LettersAndIndexes.Add(Letter, Index++);

    Lives = SecretWord.Len();
    Hints = 1 + Lives / 2;

    // NOTE: Use %i instead of %d
    // TODO: Why?

    PrintLine(TEXT("Welcome to Bull Cow!"));
    PrintLine(TEXT("There are %i possible words."), SecretWordListSize);
    PrintLine(TEXT("Guess the %i letter word."), Lives);
    PrintLine(TEXT("If you need help, enter: hint"));
    PrintLine(TEXT("You have %i lives remaining"), Lives);
    PrintLine(TEXT("You have %i hints remaining"), Hints);
}

void UBullCowCartridge::EndGame(const bool Winner)
{
    if (Winner)
    {
        PrintLine(TEXT("Well done! %s is the secret word"), *SecretWord);
    }
    else
    {
        PrintLine(TEXT("You Lost. Game Over!"));
        PrintLine(TEXT("The word was: %s"), *SecretWord);
    }

    PrintLine(TEXT("Press enter to play again!"));
    GameOver = true;
}

bool UBullCowCartridge::IsIsogram(const FString &Word)
{
    TSet<char> LetterSet;

    for (auto Letter : Word)
    {
        if (LetterSet.Contains(Letter))
            return false;
        else
            LetterSet.Add(Letter);
    }

    return true;
}

void UBullCowCartridge::PrintHint()
{
    if (Hints == 0)
    {
        PrintLine(TEXT("You have no hints left!"));
        return;
    }

    int HintCharIndex = FMath::RandRange(0, SecretWord.Len() - 1);
    FString HintCharAtString;
    switch (HintCharIndex + 1)
    {
    case 1:
        HintCharAtString = TEXT("1st");
        break;
    case 2:
        HintCharAtString = TEXT("2nd");
        break;
    case 3:
        HintCharAtString = TEXT("3rd");
        break;
    default:
        HintCharAtString = FString::Printf(TEXT("%dth"), HintCharIndex + 1);
    }

    PrintLine(TEXT("The %s letter is %c"), *HintCharAtString, SecretWord[HintCharIndex]);
    PrintLine(TEXT("You have %d hints left"), --Hints);
}

// `const` functions are functions/methods that do no change member variables
TArray<FString> UBullCowCartridge::AnalyseWord(const FString &Word) const
{
    TArray<FString> results;

    int32 Index = 0;
    for (auto Letter : Word)
    {
        // Interestingly TArray::Find returns a pointer, and as a result the pointer must also
        // be declared const in order to satisify the const constraint of the function
        // Note this is point not to const int, not a const pointer to an int (I think that's the
        // right way around)
        const int *LetterIndex = LettersAndIndexes.Find(Letter);

        if (LetterIndex != nullptr)
        {
            // Note: Using Emplace will use the String literal to directly to create the element
            // whereas Add/Push will copy or move the value into the TArray.
            // The former is the preferred method for non-trivial allocations like FString
            if (*LetterIndex == Index)
                results.Emplace(TEXT("BULL"));
            else
                results.Emplace(TEXT("COW"));
        }

        Index += 1;
    }

    return results;
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (GameOver)
    {
        InitGame();
        return;
    }

    if (Input == "hint")
    {
        PrintHint();
        return;
    }

    ClearScreen();

    PrintLine(TEXT("You entered: %s"), *Input);

    if (Input.Len() != SecretWord.Len())
    {
        PrintLine(TEXT("Not the right number of letters!"));
        Lives -= 1;
        return;
    }

    if (!UBullCowCartridge::IsIsogram(Input))
    {
        PrintLine(TEXT("%s is not an isogram!"), *Input);
        Lives -= 1;
        return;
    }

    if (Input.Equals(SecretWord, ESearchCase::IgnoreCase))
    {
        EndGame(true);
        return;
    }

    auto Results = AnalyseWord(Input);
    FString ResultStr;

    for (int32 Index = 0; Index != Results.Num(); ++Index)
    {
        ResultStr += Results[Index];
        ResultStr += TEXT(" ");
    }

    if (ResultStr.Len() != 0)
    {
        PrintLine(ResultStr);
    }
    else
    {
        PrintLine(TEXT("WHOOPS! No correct letters"));
    }
    Lives -= 1;

    if (Lives == 0)
    {
        EndGame(false);
        return;
    }

    PrintLine(TEXT("You have %d lives remaining"), Lives);
}