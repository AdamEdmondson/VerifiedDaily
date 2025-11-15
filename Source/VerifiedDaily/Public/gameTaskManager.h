// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "gameTaskManager.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FcanEndRoundSignature, bool, canEnd);

UCLASS()
class VERIFIEDDAILY_API AgameTaskManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AgameTaskManager();

	UPROPERTY(BlueprintAssignable)
	FcanEndRoundSignature canEndRoundDelegate;

	UPROPERTY(VisibleAnywhere)
	TArray<bool> taskList;

	bool tasksCompleted = false;
	int32 taskQuantity = 1;

	UFUNCTION(BlueprintCallable)
	void taskArraySetReset();

	UFUNCTION(BlueprintCallable)
	void completitionCheck();

	UFUNCTION(BlueprintCallable)
	void taskStatusUpdater(int32 taskIndexNum);

	UFUNCTION(BlueprintCallable)
	void dayEnd();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class AalarmClockTask* alarmClockTaskPointer;

	UPROPERTY(EditAnywhere)
	class Adoor* doorOpenedPointer;

	UPROPERTY(EditAnywhere)
	int day;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};