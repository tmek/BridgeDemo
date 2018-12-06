// Copyright 2014. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BridgeDemoTarget : TargetRules
{
	public BridgeDemoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

        ExtraModuleNames.AddRange(new string[] { "BridgeDemo" });
    }
}
