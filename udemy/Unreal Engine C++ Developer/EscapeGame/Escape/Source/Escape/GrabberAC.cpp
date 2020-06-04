// Copyright Darren Beukes 2020

#include "GrabberAC.h"

#include "DrawDebugHelpers.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UGrabberAC::UGrabberAC()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You
  // can turn these features off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;
}

void UGrabberAC::FindPhysicsHandle()
{
  // check for the physics handle component
  PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

  if (!PhysicsHandle)
  {
    UE_LOG(LogTemp, Error, TEXT("%s is missing an attached physics handle component"),
           *GetOwner()->GetName());
  }
}

void UGrabberAC::SetupInputComponent()
{
  // check for the input component
  // InputComponent = GetOwner()->InputComponent;
  InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

  if (!InputComponent)
  {
    UE_LOG(LogTemp, Error, TEXT("%s is missing an input component"), *GetOwner()->GetName());
  }
  else
  {
    InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabberAC::Grab);
    InputComponent->BindAction("Grab", IE_Released, this, &UGrabberAC::Release);
  }
}

// Called when the game starts
void UGrabberAC::BeginPlay()
{
  Super::BeginPlay();

  Reach = 100.f;

  FindPhysicsHandle();

  SetupInputComponent();
}

void UGrabberAC::Grab()
{
  if (PhysicsHandle->GrabbedComponent)
  {
    PhysicsHandle->ReleaseComponent();
    UE_LOG(LogTemp, Warning, TEXT("DROP IT!"));
    return;
  }

  UE_LOG(LogTemp, Warning, TEXT("Grabber engaged"));
  FHitResult Hit = GetFirstPhysicsBodyInReach();

  FVector PlayerViewPointLocation;
  FVector LineTraceEnd;

  GetPlayerReach(&PlayerViewPointLocation, &LineTraceEnd);

  if (Hit.GetActor())
  {
    UE_LOG(LogTemp, Warning, TEXT("Grabbed component %s"), *Hit.GetActor()->GetName());
    UPrimitiveComponent* ComponentToGrab = Hit.GetComponent();
    PhysicsHandle->GrabComponentAtLocation(ComponentToGrab, NAME_None, LineTraceEnd);
  }
}

void UGrabberAC::Release()
{
  UE_LOG(LogTemp, Warning, TEXT("Grabber disengaged"));
  // if (PhysicsHandle->GrabbedComponent)
  // {
  //   PhysicsHandle->ReleaseComponent();
  // }
}

// Called every frame
void UGrabberAC::TickComponent(float DeltaTime, ELevelTick TickType,
                               FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  if (PhysicsHandle->GrabbedComponent)
  {
    FVector PlayerViewPointLocation;
    FVector LineTraceEnd;

    GetPlayerReach(&PlayerViewPointLocation, &LineTraceEnd);

    PhysicsHandle->SetTargetLocation(LineTraceEnd);
  }

  if (bShowReach)
  {
    FVector PlayerViewPointLocation;
    FVector LineTraceEnd;

    GetPlayerReach(&PlayerViewPointLocation, &LineTraceEnd);

    DrawDebugLine(GetWorld(), PlayerViewPointLocation, LineTraceEnd, FColor(0, 255, 0), false, 0.f,
                  0, 5);
  }
}

void UGrabberAC::GetPlayerReach(FVector* out_ReachStart, FVector* out_ReachEnd) const
{
  FVector PlayerViewPointLocation;
  FRotator PlayerViewPointRotation;

  // Get Players viewpoint
  GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation,
                                                             OUT PlayerViewPointRotation);

  *out_ReachStart = PlayerViewPointLocation;
  *out_ReachEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}

FHitResult UGrabberAC::GetFirstPhysicsBodyInReach() const
{
  FVector PlayerViewPointLocation;
  FVector LineTraceEnd;

  GetPlayerReach(&PlayerViewPointLocation, &LineTraceEnd);

  FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());

  FHitResult Hit;
  // Ray-cast out to a certain distance (reach)
  bool bHitFound = GetWorld()->LineTraceSingleByObjectType(
      OUT Hit, PlayerViewPointLocation, LineTraceEnd,
      FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

  if (bHitFound)
  {
    UE_LOG(LogTemp, Warning, TEXT("%s collided with %s"), *GetOwner()->GetName(),
           *Hit.GetActor()->GetName());
  }

  return Hit;
}