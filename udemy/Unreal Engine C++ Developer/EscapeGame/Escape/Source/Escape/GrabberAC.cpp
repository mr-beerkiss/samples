// Copyright Darren Beukes 2020

#include "Engine/World.h"
#include "DrawDebugHelpers.h"

#include "GrabberAC.h"

#include "MeshPassProcessor.h"


// Sets default values for this component's properties
UGrabberAC::UGrabberAC()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
  // off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabberAC::BeginPlay()
{
  Super::BeginPlay();

  Reach = 100.f;

  // check for the physics handle component
  PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

  if (!PhysicsHandle)
  {
    UE_LOG(LogTemp, Error, TEXT("%s is missing an attached physics handle conponent"),
           *GetOwner()->GetName());
  }
}


// Called every frame
void UGrabberAC::TickComponent(float DeltaTime, ELevelTick TickType,
                               FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  FVector PlayerViewPointLocation;
  FRotator PlayerViewPointRotation;

  // Get Players viewpoint
  GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
      OUT PlayerViewPointLocation,
      OUT PlayerViewPointRotation
      );

  // UE_LOG(
  //     LogTemp, Warning,
  //     TEXT("Player Viewpoint; Location = %s, Rotation = %s"),
  //     *Location.ToString(), *Rotation.ToString()
  //     );

  // Draw a line from player showing the reach
  FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

  DrawDebugLine(
      GetWorld(),
      PlayerViewPointLocation,
      LineTraceEnd,
      FColor(0, 255, 0),
      false,
      0.f,
      0,
      5
      );

  FCollisionQueryParams TraceParams(
      FName(TEXT("")),
      false,
      GetOwner()
      );

  FHitResult Hit;
  // Ray-cast out to a certain distance (reach)
  bool bHitFound = GetWorld()->LineTraceSingleByObjectType(
      OUT Hit,
      PlayerViewPointLocation,
      LineTraceEnd,
      FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
      TraceParams
      );

  if (bHitFound)
  {
    UE_LOG(LogTemp, Warning,
           TEXT("%s collided with %s"),
           *GetOwner()->GetName(),
           *Hit.GetActor()->GetName()
        );
  }
}
