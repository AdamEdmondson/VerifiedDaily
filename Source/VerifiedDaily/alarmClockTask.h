// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "alarmClockTask.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTaskStatusUpdateSignature, int32, TaskIndex);

UCLASS()
class VERIFIEDDAILY_API AalarmClockTask : public AActor
{
	GENERATED_BODY()
	
public:		
	// Sets default values for this actor's properties
	AalarmClockTask();

	UPROPERTY(BlueprintAssignable)
	FTaskStatusUpdateSignature TaskStatusUpdateDelegate;

	UFUNCTION(BlueprintCallable)
	void completedTask();

	UFUNCTION(BlueprintCallable)
	void newDay();

	UPROPERTY(BlueprintReadWrite)
	bool isAlarmTaskComplete = false;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class AgameTaskManager* taskResetPointer;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
