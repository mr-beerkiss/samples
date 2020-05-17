// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    // NOTE: _ALL_ string literals should be wrapped in the `TEXT` macro... not just assignments
    // to `FString`
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the Bull Cows!"));
    PrintLine(TEXT("Bull is right letter in the right place."));
    PrintLine(TEXT("Cow is right letter in the wrong place."));
    PrintLine(TEXT("Press enter to continue"));
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    // FString literals are usually encoded as ANSI and need to re-encoded to TChar strings which
    // are platform specific unicode strings.
    // Use the `TEXT` macro instead of assign string literals
    FString HiddenWord = TEXT("candor");
    ClearScreen();
}