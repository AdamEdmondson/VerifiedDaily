// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "gameManager.generated.h"


UCLASS()
class VERIFIEDDAILY_API UgameManager : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UgameManager();

	UPROPERTY(VisibleAnywhere)
	TArray<bool> taskList;

	bool tasksCompleted = false;
	int32 taskQuantity = 8;

	void taskArraySetReset();
	void completitionCheck();
	void taskStatusUpdater(int32 taskIndexNum);
};