// Copyright Darren Beukes 2020

#include "DoorOpener.h"

// Sets default values for this component's properties
UDoorOpener::UDoorOpener()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You
  // can turn these features off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;

  // ...
}

void UDoorOpener::OpenDoor(const float DeltaTime)
{
  CurrentYaw = FMath::FInterpTo(CurrentYaw, OpenAngle, DeltaTime, OpeningSpeed);
  FRotator DoorRotation{0.f, CurrentYaw, 0.f};
  GetOwner()->SetActorRotation(DoorRotation);
}

void UDoorOpener::CloseDoor(const float DeltaTime)
{
  // CurrentYaw = FMath::FInterpConstantTo(CurrentYaw, InitialYaw, DeltaTime, 5);
  CurrentYaw = FMath::FInterpTo(CurrentYaw, InitialYaw, DeltaTime, ClosingSpeed);
  FRotator DoorRotation{0.f, CurrentYaw, 0.f};
  GetOwner()->SetActorRotation(DoorRotation);
}

// Called when the game starts
void UDoorOpener::BeginPlay()
{
  Super::BeginPlay();
  InitialYaw = GetOwner()->GetActorRotation().Yaw;
  CurrentYaw = InitialYaw;
  OpenAngle += InitialYaw;
 
  ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
  
  if (!PressurePlate)
  {
    UE_LOG(LogTemp, Error,
      TEXT("%s uses the DoorOpener component but has not assigned a trigger volume PressurePlate"),
      *GetOwner()->GetName());
  }
}

// Called every frame
void UDoorOpener::TickComponent(float DeltaTime, ELevelTick TickType,
                                FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  if (PressurePlate)
  {
    if (PressurePlate->IsOverlappingActor(ActorThatOpens))
    {
      LastTimeInTriggerVolume = GetWorld()->GetTimeSeconds();
      OpenDoor(DeltaTime);
    }
    else
    {     
      if (GetWorld()->GetTimeSeconds() - LastTimeInTriggerVolume > CloseDelay)
      {
        CloseDoor(DeltaTime);  
      }
    }
      
  }
}