// Fill out your copyright notice in the Description page of Project Settings.

#include "Sandbox.h"
#include "DirectoryOutput.h"

#include <direct.h>

// Sets default values
// Testing repo status
ADirectoryOutput::ADirectoryOutput()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	CountdownText->SetWorldSize(150.0f);
	RootComponent = CountdownText;

	CountdownTime = 3;
}

// Called when the game starts or when spawned
void ADirectoryOutput::BeginPlay()
{
	Super::BeginPlay();
	
	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ADirectoryOutput::AdvanceTimer, 1.0f, true);
}

// Called every frame
void ADirectoryOutput::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ADirectoryOutput::UpdateTimerDisplay()
{
	CountdownText->SetText(FString::FromInt(FMath::Max(CountdownTime, 0)));
}

void ADirectoryOutput::AdvanceTimer()
{
	--CountdownTime;
	UpdateTimerDisplay();
	if (CountdownTime < 1)
	{
		// We're done counting down, so stop running the timer.
		GetWorldTimerManager().ClearTimer(CountdownTimerHandle);
		//Perform any special actions we want to do when the timer ends.
		CountdownHasFinished();
	}
}

void ADirectoryOutput::CountdownHasFinished()
{
	char directoryBuffer[FILENAME_MAX];

	//Change to a special readout
	CountdownText->SetText(_getcwd(directoryBuffer, sizeof(directoryBuffer)));
}
