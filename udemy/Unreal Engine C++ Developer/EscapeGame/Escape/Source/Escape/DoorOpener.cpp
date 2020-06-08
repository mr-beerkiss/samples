// Copyright Darren Beukes 2020

#include "DoorOpener.h"

// Sets default values for this component's properties
UDoorOpener::UDoorOpener()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You
  // can turn these features off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;
}

void UDoorOpener::OpenDoor(const float DeltaTime)
{
  if (!bDoorOpening)
  {
    if (Sound)
    {
      Sound->Play(0.f);
    }
    bDoorOpening = true;
  }
  CurrentYaw = FMath::FInterpTo(CurrentYaw, OpenAngle, DeltaTime, OpeningSpeed);
  FRotator DoorRotation{0.f, CurrentYaw, 0.f};
  GetOwner()->SetActorRotation(DoorRotation);
}

void UDoorOpener::CloseDoor(const float DeltaTime)
{
  CurrentYaw = FMath::FInterpConstantTo(CurrentYaw, InitialYaw, DeltaTime, ClosingSpeed);

  if (bDoorOpening && FMath::Abs(CurrentYaw) <= 1.f )
  {
    if (Sound)
    {
      Sound->Play(0.f);
    }
    bDoorOpening = false;
  }
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

  Sound = GetOwner()->FindComponentByClass<UAudioComponent>();
  bDoorOpening = false;

  if (!Sound)
  {
    UE_LOG(LogTemp, Error, TEXT("%s does not gave a sound component attached"),
           *GetOwner()->GetName());
  }

  if (!PressurePlate)
  {
    UE_LOG(
        LogTemp, Error,
        TEXT(
            "%s uses the DoorOpener component but has not assigned a trigger volume PressurePlate"),
        *GetOwner()->GetName());
  }
}

float UDoorOpener::TotalMassOfActors() const
{

  float TotalMass = 0.f;

  if (!PressurePlate)
  {
    UE_LOG(
        LogTemp, Error,
        TEXT(
            "%s uses the DoorOpener component but has not assigned a trigger volume PressurePlate"),
        *GetOwner()->GetName());
    return 0.f;
  }

  TArray<AActor*> OverlappingActors;
  PressurePlate->GetOverlappingActors(OUT OverlappingActors);

  for (const auto* Actor : OverlappingActors)
  {
    float ActorMass = Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
    TotalMass += ActorMass;
  }

  return TotalMass;
}

// Called every frame
void UDoorOpener::TickComponent(float DeltaTime, ELevelTick TickType,
                                FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  if (PressurePlate)
  {
    if (TotalMassOfActors() > MassRequiredToOpen)
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