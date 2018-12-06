/*
#include "NetflixCapture.h"
#include "BridgeDemo.h"

#include "AllowWindowsPlatformTypes.h"

ANetflixCapture::ANetflixCapture(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;

	WinCapture = NULL;
	NetflixWin = new NetflixWindow();

	// reset capture frame rate delta time
	totalViewScreenDeltaTime = 0;

	if (!CaptureTexture) {
		CaptureTexture = UTexture2D::CreateTransient(CAPTURE_SIZE, CAPTURE_SIZE, EPixelFormat::PF_B8G8R8A8);  // BGRA 32-bit pixel format by default
	}
}


void ANetflixCapture::UpdateRenderTarget() {

	if (!NetflixWin->CaptureHWND) {
		// attempt to aquire and retry next update.
		NetflixWin->AquireNetflixWindow();
		return;
	}

	if (!WinCapture)
	{
		WinCapture = new WindowCapture(NetflixWin->CaptureHWND, CAPTURE_SIZE, CAPTURE_SIZE);
	}

	// capture image.
	int byteCount = CAPTURE_SIZE * CAPTURE_SIZE * 4;
	if (!WinCapture->CaptureToBuffer())
	{
		// if we fail to capture this frame, reset and retry next frame.
		delete WinCapture;
		delete NetflixWin;
		WinCapture = NULL;
		NetflixWin = new NetflixWindow();
		return;
	}

	// lock, copy to texture and unlock
	if (!CaptureTexture) {
		CaptureTexture = UTexture2D::CreateTransient(CAPTURE_SIZE, CAPTURE_SIZE, EPixelFormat::PF_B8G8R8A8);  // BGRA 32-bit pixel format by default
	}

	uint32* TextureBuffer = (uint32*)CaptureTexture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(TextureBuffer, WinCapture->ImageBuffer, byteCount);
	CaptureTexture->PlatformData->Mips[0].BulkData.Unlock();
	CaptureTexture->UpdateResource();

	// setup tile item
	FVector2D pos(0, 1024);
	FVector2D size(1024, -1024); // 512 source texture to 1024 render target flipped vertically
	FCanvasTileItem TileItem(pos, CaptureTexture->Resource, size, FLinearColor::White);

	// Create a Canvas and assign the render texture resource to it.
	FTextureRenderTarget2DResource* RenderTextureResource = (FTextureRenderTarget2DResource*)RenderTarget->Resource;
	FCanvas Canvas(RenderTextureResource, NULL, 0, 0, 0, ERHIFeatureLevel::SM5);
	Canvas.Clear(RenderTarget->ClearColor);
	Canvas.DrawItem(TileItem);
	Canvas.Flush_GameThread(false);
}

void ANetflixCapture::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// limit capture rate 
	if (g_ViewScreenOn) {
		totalViewScreenDeltaTime += DeltaTime;
		if (totalViewScreenDeltaTime >= minViewScreenDeltaTime) {
			totalViewScreenDeltaTime -= minViewScreenDeltaTime;
			UpdateRenderTarget();
		}
	}
}

#include "HideWindowsPlatformTypes.h"
*/