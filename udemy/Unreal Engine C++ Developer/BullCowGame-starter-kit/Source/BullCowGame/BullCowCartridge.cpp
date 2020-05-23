// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
  Super::BeginPlay();

  // https://community.gamedev.tv/t/slow-compile-times-after-adding-word-list-on-bullcowgame/118958/2
  // include the words list at Runtime instead of using a massive array baked into a header file
  TArray<FString> Words;
  const FString WordListPath = FPaths::ProjectContentDir() / TEXT("Words/en.txt");

  // TODO: It may be even more efficient to using something like readline to process the file
  // directly instead of creating an intermediate TArray
  FFileHelper::LoadFileToStringArray(Words, *WordListPath);

  for (const auto Word : Words)
    if (Word.Len() >= 4 && Word.Len() <= 8 && IsIsogram(Word) && Word != "hint")
      SecretWordList.Emplace(Word);

  SecretWordListSize = SecretWordList.Num();

  InitGame();
}

void UBullCowCartridge::InitGame() {
  GameOver = false;
  SecretWord = SecretWordList[FMath::RandRange(0, SecretWordListSize - 1)];
  HintsShown.Empty();
  LettersAndIndexes.Empty();
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

void UBullCowCartridge::EndGame(const bool Winner) {
  if (Winner) {
    PrintLine(TEXT("Well done! %s is the secret word"), *SecretWord);
  } else {
    PrintLine(TEXT("You Lost. Game Over!"));
    PrintLine(TEXT("The word was: %s"), *SecretWord);
  }

  PrintLine(TEXT("Press enter to play again!"));
  GameOver = true;
}

bool UBullCowCartridge::IsIsogram(const FString& Word) {
  TSet<char> LetterSet;

  for (auto Letter : Word) {
    if (LetterSet.Contains(Letter))
      return false;
    else
      LetterSet.Add(Letter);
  }

  return true;
}

void UBullCowCartridge::PrintHint() {
  if (Hints == 0) {
    PrintLine(TEXT("You have no hints left!"));
    return;
  }

  int HintCharIndex = FMath::RandRange(0, SecretWord.Len() - 1);

  while (HintsShown.Contains(HintCharIndex))
    HintCharIndex = FMath::RandRange(0, SecretWord.Len() - 1);

  HintsShown.Add(HintCharIndex);

  FString HintCharAtString;
  switch (HintCharIndex + 1) {
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

void UBullCowCartridge::AnalyseWord(const FString& Word, int32& Bulls, int32& Cows) const {
  int32 Index = 0;
  // TODO: According to lecture, out params should be initialised in function to prevent 
  // junk being returned. Is that true?
  Bulls = 0;
  Cows = 0;
  for (auto Letter : Word) {
    // Interestingly TArray::Find returns a pointer, and as a result the pointer
    // must also be declared const in order to satisify the const constraint of
    // the function Note this is point not to const int, not a const pointer to
    // an int (I think that's the right way around)
    const int* LetterIndex = LettersAndIndexes.Find(Letter);

    if (LetterIndex != nullptr) {
      if (*LetterIndex == Index)
        Bulls++;
      else
        Cows++;
    }

    Index += 1;
  }
}

// `const` functions are functions/methods that do no change member variables
TArray<FString> UBullCowCartridge::AnalyseWord(const FString& Word) const {
  TArray<FString> results;

  int32 Index = 0;
  for (auto Letter : Word) {
    // Interestingly TArray::Find returns a pointer, and as a result the pointer
    // must also be declared const in order to satisify the const constraint of
    // the function Note this is point not to const int, not a const pointer to
    // an int (I think that's the right way around)
    const int* LetterIndex = LettersAndIndexes.Find(Letter);

    if (LetterIndex != nullptr) {
      // Note: Using Emplace will use the String literal to directly to create
      // the element whereas Add/Push will copy or move the value into the
      // TArray. The former is the preferred method for non-trivial allocations
      // like FString
      if (*LetterIndex == Index)
        results.Emplace(TEXT("BULL"));
      else
        results.Emplace(TEXT("COW"));
    }

    Index += 1;
  }

  return results;
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
{
  if (GameOver) {
    ClearScreen();
    InitGame();
    return;
  }

  if (PlayerInput == "hint") {
    PrintHint();
    return;
  }

  ClearScreen();

  PrintLine(TEXT("You entered: %s"), *PlayerInput);

  if (PlayerInput.Len() != SecretWord.Len()) {
    PrintLine(TEXT("Not the right number of letters!"));
    Lives -= 1;
    return;
  }

  if (!UBullCowCartridge::IsIsogram(PlayerInput)) {
    PrintLine(TEXT("%s is not an isogram!"), *PlayerInput);
    Lives -= 1;
    return;
  }

  if (PlayerInput.Equals(SecretWord, ESearchCase::IgnoreCase)) {
    EndGame(true);
    return;
  }

  int32 Bulls, Cows;
  AnalyseWord(PlayerInput, Bulls, Cows);

  

  PrintLine(TEXT("You have %i BULLS and %i COWS"), Bulls, Cows);

  Lives -= 1;
  if (Lives == 0) {
    EndGame(false);
    return;
  }

  // FString ResultStr;

  // for (int32 Index = 0; Index != Bulls; Index++) {
  //   ResultStr += TEXT("BULL ");
  // }

  // for (int32 Index = 0; Index != Cows; Index++) {
  //   ResultStr += TEXT("COW ");
  // }

  // if (ResultStr.Len() != 0) {
  //   PrintLine(ResultStr);
  // } else {
  //   PrintLine(TEXT("WHOOPS! No correct letters"));
  // }

  // auto Results = AnalyseWord(PlayerInput);
  // FString ResultStr;

  // for (int32 Index = 0; Index != Results.Num(); ++Index) {
  //   ResultStr += Results[Index];
  //   ResultStr += TEXT(" ");
  // }

  // if (ResultStr.Len() != 0) {
  //   PrintLine(ResultStr);
  // } else {
  //   PrintLine(TEXT("WHOOPS! No correct letters"));
  // }
  // Lives -= 1;

  // if (Lives == 0) {
  //   EndGame(false);
  //   return;
  // }

  PrintLine(TEXT("You have %d lives remaining"), Lives);
}