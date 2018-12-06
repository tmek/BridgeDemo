/*
#pragma once

#include "GameFramework/Actor.h"
#include "NetflixWindow.h"
#include "WindowCapture.h"

#include "NetflixCapture.generated.h"

#define WINDOW_CAPTURE_RATE 30


UCLASS()
class ANetflixCapture : public AActor
{
public:
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UTextureRenderTarget2D* RenderTarget;

	// don't remove UPROPERTY or you'll get TARRAY crashes. (UPROPERTY is probably preventing it from being gc'd or something.)
	// perhaps transient isn't the right kind of texture.  or perphas create it every update.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UTexture2D* CaptureTexture;

	virtual void Tick(float DeltaTime) override;

	void UpdateRenderTarget();

	WindowCapture* WinCapture;
	NetflixWindow* NetflixWin;

	float totalViewScreenDeltaTime = 0;
	float minViewScreenDeltaTime = 1.0f / WINDOW_CAPTURE_RATE;
};

*/