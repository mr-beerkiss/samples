// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString &Input) override;
	void InitGame();
	void EndGame(const bool Winner);
	static bool IsIsogram(const FString &Word);
	TArray<FString> AnalyseWord(const FString &Word);

	// Your declarations go below!
private:
	FString SecretWord;
	TMap<char, int32> LettersAndIndexes;
	int32 Lives;
	bool GameOver;
};
