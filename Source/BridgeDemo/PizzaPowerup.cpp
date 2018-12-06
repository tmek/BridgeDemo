// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "PizzaPowerup.h"
#include "BridgeDemo.h"
#include "Engine/StaticMeshActor.h"
#include "Sound/AmbientSound.h"
#include "Components/AudioComponent.h"


APizzaPowerup::APizzaPowerup()
{
	PrimaryActorTick.bCanEverTick = true;
}


void APizzaPowerup::ToggleViewScreen()
{
	ViewScreenOn = !ViewScreenOn;
	g_ViewScreenOn = ViewScreenOn;

	if (ViewScreenOn)
	{
		// show Netflix capture
		ViewScreen->GetStaticMeshComponent()->SetMaterial(0, NetflixMaterial);

		// stop any sounds currently playing 
		for (int i = 0; i < Sounds.Num(); i++) {
			Sounds[i]->GetAudioComponent()->Stop();
		}

	}
	else
	{
		// show stars
		ViewScreen->GetStaticMeshComponent()->SetMaterial(0, StarsMaterial);
	}
}


void APizzaPowerup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void APizzaPowerup::BeginPlay()
{
	Super::BeginPlay();
}


void APizzaPowerup::BeginDestroy()
{
	Super::BeginDestroy();
}

