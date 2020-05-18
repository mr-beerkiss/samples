// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    InitGame();
}

void UBullCowCartridge::InitGame()
{
    GameOver = false;
    SecretWord = "lip";
    // Call them isograms
    // SecretWord = "candor";
    SecretWord = "canopy";

    int32 Index = 0;

    for (auto Letter : SecretWord)
        LettersAndIndexes.Add(Letter, Index++);

    Lives = SecretWord.Len();

    PrintLine(TEXT("Welcome to Bull Cow!"));
    PrintLine(FString::Printf(TEXT("Guess the %d letter word"), Lives));
    PrintLine(FString::Printf(TEXT("You have %d lives remaining"), Lives));
}

void UBullCowCartridge::EndGame(bool Winner)
{
    if (Winner)
    {
        PrintLine(FString::Printf(TEXT("Well done! %s is the secret word"), *SecretWord));
    }
    else
    {
        PrintLine(TEXT("You Lost. Game Over!"));
        PrintLine(FString::Printf(TEXT("The word was: %s"), *SecretWord));
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

TArray<FString> UBullCowCartridge::AnalyseWord(const FString &Word)
{
    TArray<FString> results;

    int32 Index = 0;
    for (auto c : Word)
    {
        int *LetterIndex = LettersAndIndexes.Find(c);

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
    ClearScreen();

    if (GameOver)
    {
        InitGame();
        return;
    }

    PrintLine(FString::Printf(TEXT("You entered: %s"), *Input));

    if (Input.Len() != SecretWord.Len())
    {
        PrintLine(TEXT("Not the right number of letters!"));
        Lives -= 1;
    }
    else if (!UBullCowCartridge::IsIsogram(Input))
    {
        PrintLine(FString::Printf(TEXT("%s is not an isogram!"), *Input));
        Lives -= 1;
    }
    else
    {
        if (Input.Equals(SecretWord, ESearchCase::IgnoreCase))
        {
            EndGame(true);
            return;
        }
        else
        {
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
        }
    }

    if (Lives == 0)
    {
        EndGame(false);
        return;
    }

    PrintLine(FString::Printf(TEXT("You have %d lives remaining"), Lives));
}