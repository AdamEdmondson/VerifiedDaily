// Fill out your copyright notice in the Description page of Project Settings.

#include "gameManager.h"
#include "Engine/Engine.h"

UgameManager::UgameManager()
{
	//init setup at start of the game
	taskArraySetReset();
	completitionCheck();
}


//set or reset the task array
void UgameManager::taskArraySetReset()
{
	taskList.Init(false, taskQuantity);
	tasksCompleted = false;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, FString::Printf(TEXT("%d Tasks Created, Array has been reset"), taskList.Num()));
	}
}

//checks whether all tasks have been completed
void UgameManager::completitionCheck()
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
void UgameManager::taskStatusUpdater(int32 taskIndexNum)
{
	taskList[taskIndexNum] = true;
	completitionCheck();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::White, FString::Printf(TEXT("Task %d is now %s"), taskList[taskIndexNum], taskList[taskIndexNum] ? TEXT("True") : TEXT("False")));
	}
}