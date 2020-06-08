// Copyright Darren Beukes 2020

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "GrabberAC.generated.h"

#define OUT

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPE_API UGrabberAC : public UActorComponent
{
  GENERATED_BODY()

public:
  // Called every frame
  virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                             FActorComponentTickFunction* ThisTickFunction) override;
  // Called when the game starts
  virtual void BeginPlay() override;

protected:
  // Sets default values for this component's properties
  UGrabberAC();

private:
  UPROPERTY(EditAnywhere)
  float Reach = 100.f;

  UPROPERTY(EditAnywhere)
  bool bShowReach = true;

  UPROPERTY()
  UPhysicsHandleComponent* PhysicsHandle = nullptr;

  UPROPERTY()
  UInputComponent* InputComponent = nullptr;

  void Grab();
  void Release();

  void FindPhysicsHandle();
  void SetupInputComponent();

  FHitResult GetFirstPhysicsBodyInReach() const;
  void GetPlayerReach(FVector* out_ReachStart, FVector* out_ReachEnd) const;
};
