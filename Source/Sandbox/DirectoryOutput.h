// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DirectoryOutput.generated.h"

UCLASS()
class SANDBOX_API ADirectoryOutput : public AActor
{
	GENERATED_BODY()
	
private:
	//How long, in seconds, the countdown will run
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	int32 CountdownTime;

public:	
	// Sets default values for this actor's properties
	ADirectoryOutput();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	////How long, in seconds, the countdown will run
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	//int32 CountdownTime;

	UTextRenderComponent* CountdownText;

	void UpdateTimerDisplay();

	void AdvanceTimer();

	void CountdownHasFinished();

	FTimerHandle CountdownTimerHandle;
	
};
