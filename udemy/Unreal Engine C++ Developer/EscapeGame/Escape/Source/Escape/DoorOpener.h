// Copyright Darren Beukes 2020

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "DoorOpener.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPE_API UDoorOpener : public UActorComponent
{
  GENERATED_BODY()

public:
  // Sets default values for this component's properties
  UDoorOpener();

protected:
  // Called when the game starts
  virtual void BeginPlay() override;

private:
  UPROPERTY(EditAnywhere)
  float OpenAngle = -90.f;

  float InitialYaw;
  float CurrentYaw;

  UPROPERTY(EditAnywhere)
  float CloseDelay = 0.f;

  UPROPERTY(EditAnywhere)
  float ClosingSpeed = 1.f;

  UPROPERTY(EditAnywhere)
  float OpeningSpeed = 1.f;
  
  float LastTimeInTriggerVolume;

  UPROPERTY(EditAnywhere)
  ATriggerVolume* PressurePlate;

  AActor* ActorThatOpens;

public:
  // Called every frame
  virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                             FActorComponentTickFunction* ThisTickFunction) override;

  // opens the door
  void OpenDoor(float DeltaTime);

  // closes the door
  void CloseDoor(const float DeltaTime);
};
