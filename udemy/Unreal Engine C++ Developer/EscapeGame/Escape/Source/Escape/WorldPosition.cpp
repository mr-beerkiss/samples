// Copyright Darren Beukes 2020

#include "WorldPosition.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UWorldPosition::UWorldPosition() {
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You
  // can turn these features off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;

  // ...
}

// Called when the game starts
void UWorldPosition::BeginPlay() {
  Super::BeginPlay();

  auto Owner = GetOwner();

  UE_LOG(LogTemp, Warning, TEXT("This component is attached to %s"), *Owner->GetName());

  auto Location = Owner->GetActorLocation().ToString();

  UE_LOG(LogTemp, Warning, TEXT("Actor location is %s"), *Location);

  FVector LocationVec = Owner->GetTransform().GetLocation();

  UE_LOG(LogTemp, Warning, TEXT("This object's transform's location: X: %.5f, Y: %.5f, Z: %.5f"),
         LocationVec.X, LocationVec.Y, LocationVec.Z);

  FVector TranslationVec = Owner->GetTransform().GetTranslation();

  UE_LOG(LogTemp, Warning, TEXT("This object's transform's translation: X: %.5f, Y: %.5f, Z: %.5f"),
         TranslationVec.X, TranslationVec.Y, TranslationVec.Z);
}

// Called every frame
void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType,
                                   FActorComponentTickFunction* ThisTickFunction) {
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

  // ...
}
