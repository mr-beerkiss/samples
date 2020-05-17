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
    // SecretWord = "canopy";
    Lives = SecretWord.Len();

    PrintLine(TEXT("Welcome to Bull Cow!"));
    PrintLine(FString::Printf(TEXT("Guees the %d letter word"), Lives));
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
    else
    {
        if (Input.Equals(SecretWord, ESearchCase::IgnoreCase))
        {
            EndGame(true);
            return;
        }
    }

    if (Lives == 0)
    {
        EndGame(false);
        return;
    }

    PrintLine(FString::Printf(TEXT("You have %d lives remaining"), Lives));
}