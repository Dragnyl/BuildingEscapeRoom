// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_EscapeRoom_CM.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	OpenAngle = -60.0f;
	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	// Find the owning Actor
	AActor* Owner = GetOwner();
	
	// Create a rotator
	FRotator Rotation = FRotator(0.f, OpenAngle, 0.f);
	
	// Set the door rotation
	Owner->SetActorRotation(Rotation);

	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

