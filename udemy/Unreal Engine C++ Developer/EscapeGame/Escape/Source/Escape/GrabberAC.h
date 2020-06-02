// Copyright Darren Beukes 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/PlayerController.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "GrabberAC.generated.h"

#define OUT

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_API UGrabberAC : public UActorComponent
{
  GENERATED_BODY()

public:
  // Sets default values for this component's properties
  UGrabberAC();

private:
  float Reach;

    UPhysicsHandleComponent* PhysicsHandle = nullptr;
  
  
protected:
  // Called when the game starts
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void TickComponent(float DeltaTime, ELevelTick TickType,
                             FActorComponentTickFunction* ThisTickFunction) override;
};
