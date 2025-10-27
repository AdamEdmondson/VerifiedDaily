// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "meshAdder.generated.h"

UCLASS()
class VERIFIEDDAILY_API AmeshAdder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AmeshAdder();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* meshExample;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};