// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
// generated header file must always be at the bottom
#include "WorldPosition.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPE_API UWorldPosition : public UActorComponent {
  GENERATED_BODY()

public:
  // Sets default values for this component's properties
  UWorldPosition();

protected:
  // Called when the game starts
  virtual void BeginPlay() override;
  // FString name;

public:
  // Called every frame
  virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                             FActorComponentTickFunction* ThisTickFunction) override;
};
