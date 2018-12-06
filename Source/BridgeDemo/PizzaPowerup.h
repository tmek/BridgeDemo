// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "PizzaPowerup.generated.h"

class AStaticMeshActor;
class AAmbientSound;

UCLASS()
class APizzaPowerup : public AActor
{
public:
	GENERATED_BODY()

	APizzaPowerup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	AStaticMeshActor* ViewScreen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UMaterialInterface* StarsMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UMaterialInterface* NetflixMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	TArray<AAmbientSound*> Sounds;

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void ToggleViewScreen();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	bool ViewScreenOn;

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void BeginDestroy() override;

};