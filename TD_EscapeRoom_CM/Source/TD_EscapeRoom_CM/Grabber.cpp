// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_EscapeRoom_CM.h"
#include "Grabber.h"

#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;



	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Get player view point this tick
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
		);
		// TODO Log out to test
		UE_LOG(LogTemp, Warning, TEXT("Location: %s, Rotation: %s"),
			*PlayerViewPointLocation.ToString(),
			*PlayerViewPointRotation.ToString()
			)

	// TODO Tracer une ligne pointant les �l�ments de la sc�ne, utilisant DrawDebugLine
	// TODO retourner le nom de l'�l�ment

			FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

		// Draw a red trace in the world to visualise
			DrawDebugLine(GetWorld(), PlayerViewPointLocation, LineTraceEnd, FColor(255, 0, 0),	false, 0.f, 0.f, 10.f);
}

