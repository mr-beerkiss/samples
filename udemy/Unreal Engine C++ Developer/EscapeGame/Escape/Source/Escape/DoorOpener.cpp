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
  CurrentYaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, 2);
  FRotator DoorRotation{0.f, CurrentYaw, 0.f};
  GetOwner()->SetActorRotation(DoorRotation);
}

// Called when the game starts
void UDoorOpener::BeginPlay()
{
  Super::BeginPlay();
  InitialYaw = GetOwner()->GetActorRotation().Yaw;
  CurrentYaw = InitialYaw;
  // TargetYaw = InitialYaw + TargetYaw;
  TargetYaw += InitialYaw;
}

// Called every frame
void UDoorOpener::TickComponent(float DeltaTime, ELevelTick TickType,
                                FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  if (PressurePlate->IsOverlappingActor(ActorThatOpens))
  {
    OpenDoor(DeltaTime);  
  }
}