// Fill out your copyright notice in the Description page of Project Settings.


#include "door.h"

// Sets default values
Adoor::Adoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Adoor::BeginPlay()
{
	Super::BeginPlay();
	
	if (doorCanEndPointer != nullptr)
	{
		doorCanEndPointer->canEndRoundDelegate.AddDynamic(this, &Adoor::checkCanEnd);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(7, 5.0f, FColor::Green, FString::Printf(TEXT("Another Pointer Created")));
		}
	}

}

// Called every frame
void Adoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Adoor::checkCanEnd(bool canEnd)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 5.0f, FColor::Green, FString::Printf(TEXT("I WORK!!!!!!")));
	}
}