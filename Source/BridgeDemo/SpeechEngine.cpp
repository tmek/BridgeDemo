/*

#include "SpeechEngine.h"
#include "BridgeDemo.h"

SpeechAPI* g_Speech;

void OnSpeechRecognized(const wchar_t* text, const wchar_t* grammarName) {
	g_SpeechText = FString(text).ToUpper();
	g_SpeechQueuedGrammar = FString(grammarName);
	g_SpeechQueuedText = FString(text);
}
void OnSpeechRejected(const wchar_t* text, const wchar_t* grammarName) {
	g_SpeechText = FString(text).ToUpper();
}
void OnSpeechHypothesized(const wchar_t* text, const wchar_t* grammarName) {
	g_SpeechText = FString(text).ToUpper();
}
void OnAudioLevelUpdated(int audioLevel) {
	g_AudioLevel = audioLevel;
}

ASpeechEngine::ASpeechEngine(const class FObjectInitializer& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
}


void ASpeechEngine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (g_SpeechQueuedGrammar.Compare("Query", ESearchCase::IgnoreCase) == 0) {
		//TODO: wolfram alpha call.

		// Process(args.Result.Text.Replace("Computer ", ""));
		g_SpeechQueuedText.RemoveFromStart("computer ", ESearchCase::IgnoreCase);

		//if (input == "stop")
		if (g_SpeechQueuedText.Compare("stop", ESearchCase::IgnoreCase) == 0) {
			g_Speech->StopSpeaking();
		}
		else 
		{
			//GetWolframAlphaResponse(g_SpeechQueuedText.);
			g_Speech->Speak((wchar_t *)(*g_SpeechQueuedText));
		}

		g_SpeechQueuedGrammar = "";
	}

	if (g_SpeechQueuedGrammar.Compare("Command", ESearchCase::IgnoreCase) == 0) {
		APlayerController* controller = GEngine->GetFirstLocalPlayerController(GWorld);

		// "Fire", "Fire Torpedo", "Fire Torpedoes",
		if (g_SpeechQueuedText.Compare("fire", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Fire Torpedo\""), true);
		}
		if (g_SpeechQueuedText.Compare("fire torpedo", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Fire Torpedo\""), true);
		}
		if (g_SpeechQueuedText.Compare("fire torpedoes", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Fire Torpedoes\""), true);
		}

		// "Fire Photon Torpedo", "Fire Photon Torpedoes", "Fire Photon Torpedoes Full Spread",
		if (g_SpeechQueuedText.Compare("fire photon torpedo", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Fire Torpedo\""), true);
		}
		if (g_SpeechQueuedText.Compare("fire photon torpedoes", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Fire Torpedoes\""), true);
		}
		if (g_SpeechQueuedText.Compare("Fire Photon Torpedoes Full Spread", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Fire Torpedoes\""), true);
		}

		// "Photon Torpedo", "Photon Torpedoes", "Photon Torpedoes Full Spread", "Fire Everything",
		if (g_SpeechQueuedText.Compare("photon torpedo", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Fire Torpedo\""), true);
		}
		if (g_SpeechQueuedText.Compare("photon torpedoes", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Fire Torpedoes\""), true);
		}
		if (g_SpeechQueuedText.Compare("Photon Torpedoes Full Spread", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Fire Torpedoes\""), true);
		}
		if (g_SpeechQueuedText.Compare("fire everything", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Fire Torpedoes\""), true);
		}

		// "On Screen", "Viewer Off", "Off Screen",
		if (g_SpeechQueuedText.Compare("on screen", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Voice Toggle Screen\""), true);
		}
		if (g_SpeechQueuedText.Compare("viewer off", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Voice Toggle Screen\""), true);
		}
		if (g_SpeechQueuedText.Compare("off screen", ESearchCase::IgnoreCase) == 0) {
			controller->ConsoleCommand(TEXT("CE \"Voice Toggle Screen\""), true);
		}
		g_SpeechQueuedText = "";
		g_SpeechQueuedGrammar = "";
	}

}


void ASpeechEngine::BeginPlay() {

	g_Speech = GetSpeechAPI();
	g_Speech->SpeechRecognized = OnSpeechRecognized;
	g_Speech->SpeechRejected = OnSpeechRejected;
	g_Speech->SpeechHypothesized = OnSpeechHypothesized;
	g_Speech->AudioLevelUpdated = OnAudioLevelUpdated;
	g_Speech->Initialize();
}

*/