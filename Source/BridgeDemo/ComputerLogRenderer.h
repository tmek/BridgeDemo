

#pragma once

#include "GameFramework/Actor.h"
#include "ComputerLogRenderer.generated.h"

#define UPDATE_RATE_FPS 30

/**
 * 
 */
UCLASS()
class AComputerLogRenderer : public AActor
{
	GENERATED_BODY()

public:
	AComputerLogRenderer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UTextureRenderTarget2D* RenderTarget;

	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UFont* ConsoleFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FColor  LabelColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FColor  TextColor;

	void UpdateRenderTarget(float DeltaTime);

	float updateDeltaTime = 0;
	float minUpdateDeltaTime = 1.0f / UPDATE_RATE_FPS;

	float fontHeight;
	int labelWidth, labelHeight;
	FString label = "VOCAL ANALYSIS ";

};
