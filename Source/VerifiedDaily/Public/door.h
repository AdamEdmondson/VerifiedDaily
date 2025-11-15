// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "door.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FdoorOpenedSignature);

UCLASS()
class VERIFIEDDAILY_API Adoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Adoor();

	UPROPERTY(BlueprintAssignable)
	FdoorOpenedSignature doorOpenedDelegate;

	UFUNCTION(BlueprintCallable)
	void openDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
