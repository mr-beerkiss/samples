// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Console/Cartridge.h"
#include "CoreMinimal.h"
#include "FileHelper.h"
#include "Paths.h"

#include "BullCowCartridge.generated.h"

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge {
  GENERATED_BODY()

public:
  virtual void BeginPlay() override;
  virtual void OnInput(const FString& Input) override;
  void InitGame();
  void PrintHint();
  void EndGame(const bool Winner);
  static bool IsIsogram(const FString& Word);
	FBullCowCount AnalyseWord(const FString& Word) const;

  // Your declarations go below!
private:
  FString SecretWord;
  TMap<char, int32> LettersAndIndexes;
  TArray<FString> SecretWordList;
	TArray<int32> HintsShown;
  int32 SecretWordListSize;
  int32 Lives;
  int32 Hints;
  bool GameOver;
};
