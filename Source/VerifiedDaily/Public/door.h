// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <gameTaskManager.h>
#include "door.generated.h"

UCLASS()
class VERIFIEDDAILY_API Adoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Adoor();

	UFUNCTION(BlueprintCallable)
	void checkCanEnd(bool canEnd);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	AgameTaskManager* doorCanEndPointer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
