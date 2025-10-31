// Fill out your copyright notice in the Description page of Project Settings.


#include "gameTaskManager.h"
#include "alarmClockTask.h"
#include "Engine/Engine.h"

// Sets default values
AgameTaskManager::AgameTaskManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AgameTaskManager::BeginPlay()
{
	Super::BeginPlay();
	

	//init setup at start of the game
	taskArraySetReset();
	completitionCheck();

	if (alarmClockTaskPointer != nullptr)
	{
		alarmClockTaskPointer->TaskStatusUpdateDelegate.AddDynamic(this, &AgameTaskManager::taskStatusUpdater);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(6, 5.0f, FColor::Green, FString::Printf(TEXT("Pointer Created")));
		}
	}
}

// Called every frame
void AgameTaskManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//set or reset the task array
void AgameTaskManager::taskArraySetReset()
{
	taskList.Init(false, taskQuantity);
	tasksCompleted = false;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(3, 5.0f, FColor::White, FString::Printf(TEXT("%d Tasks Created, Array has been reset"), taskList.Num()));
	}
}

//checks whether all tasks have been completed
void AgameTaskManager::completitionCheck()
{
	if (taskList.Contains(bool(false)))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Red, FString::Printf(TEXT("Tasks Not Completed")));
		}
	}
	else
	{
		tasksCompleted = true;

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Green, FString::Printf(TEXT("Tasks All Completed")));
		}
	}
}

//marks a specific task as completed by changing an element from false to true, 0 is task 1
void AgameTaskManager::taskStatusUpdater(int32 taskIndexNum)
{

	if (taskList.IsValidIndex(taskIndexNum))
	{
		taskList[taskIndexNum] = true;
		completitionCheck();

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::White, FString::Printf(TEXT("Task %d is now %s"), taskList[taskIndexNum], taskList[taskIndexNum] ? TEXT("True") : TEXT("False")));
		}
	}
	else if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::Red, FString::Printf(TEXT("%d is not valid"), taskIndexNum));
	}

}

