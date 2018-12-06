
#include "ComputerLogRenderer.h"
#include "BridgeDemo.h"
#include "Engine/Font.h"
#include "CanvasItem.h"
#include "TextureResource.h"
#include "Engine/TextureRenderTarget2D.h"
#include "CanvasTypes.h"


AComputerLogRenderer::AComputerLogRenderer()
{
	PrimaryActorTick.bCanEverTick = true;
}


float renderAudioLevel;

void AComputerLogRenderer::BeginPlay() 
{
	fontHeight = ConsoleFont->GetMaxCharHeight();
	ConsoleFont->GetStringHeightAndWidth(label, labelHeight, labelWidth);
}


void AComputerLogRenderer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	updateDeltaTime += DeltaTime;
	if (updateDeltaTime >= minUpdateDeltaTime)
	{
		updateDeltaTime -= minUpdateDeltaTime;
		UpdateRenderTarget(DeltaTime);
	}
}


void AComputerLogRenderer::UpdateRenderTarget(float DeltaTime)
{
	renderAudioLevel = FMath::FInterpTo(renderAudioLevel, g_AudioLevel, DeltaTime, 30);

	FVector2D position(60 / 2, 50 / 2);
	//	float fontHeight = ConsoleFont->GetMaxCharHeight();

	FCanvasTextItem TextItem(FVector2D::ZeroVector, FText::GetEmpty(), ConsoleFont, TextColor);

	// int labelWidth, labelHeight;

	// Create a Canvas and assign the render texture resource to it.
	FTextureRenderTarget2DResource* RenderTextureResource = (FTextureRenderTarget2DResource*)RenderTarget->Resource;
	FCanvas Canvas(RenderTextureResource, NULL, 0, 0, 0, ERHIFeatureLevel::SM5);

	// 0067AEFF
	Canvas.Clear(FLinearColor::Black);


	TextItem.Scale = FVector2D(.5, .5);
	TextItem.Text = FText::FromString(label);
	TextItem.SetColor(LabelColor);
	Canvas.DrawItem(TextItem, position);

	position.X += labelWidth / 2.0f;

	TextItem.Scale = FVector2D(0.5f, 0.5f);
	TextItem.Text = FText::FromString(g_SpeechText);
	TextItem.SetColor(TextColor);
	Canvas.DrawItem(TextItem, position);

	FVector2D start(400 / 2, 180 / 2);

	FVector2D end((renderAudioLevel / 100.0f * 370) / 2, 0);

	FCanvasBoxItem BoxItem(start, end);
	BoxItem.SetColor(LabelColor);
	BoxItem.LineThickness = 20;
	Canvas.DrawItem(BoxItem);
	Canvas.Flush_GameThread(false);

	// RenderTarget->UpdateResourceImmediate();
}


