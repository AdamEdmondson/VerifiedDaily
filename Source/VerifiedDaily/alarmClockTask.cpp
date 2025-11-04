// Fill out your copyright notice in the Description page of Project Settings.

#include "alarmClockTask.h"

// Sets default values
AalarmClockTask::AalarmClockTask()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AalarmClockTask::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AalarmClockTask::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Broadcast to gameTaskManger for Array Update
void AalarmClockTask::CompletedTask()
{
	isAlarmTaskComplete = true;
	TaskStatusUpdateDelegate.Broadcast(0);
}
