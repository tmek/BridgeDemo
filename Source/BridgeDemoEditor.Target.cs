// Copyright 2014. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BridgeDemoEditorTarget : TargetRules
{
	public BridgeDemoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

        ExtraModuleNames.AddRange(new string[] { "BridgeDemo" });
    }
}
