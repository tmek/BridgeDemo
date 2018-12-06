// Copyright 2014. All Rights Reserved.

#include "BridgeDemo.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, BridgeDemo, "BridgeDemo" );

bool g_ViewScreenOn = false;

FString g_SpeechText = ""; 
int g_AudioLevel = 0; 

FString g_SpeechQueuedText = ""; // TODO: global variable. sloppy.
FString g_SpeechQueuedGrammar = ""; // TODO: global variable. sloppy.
