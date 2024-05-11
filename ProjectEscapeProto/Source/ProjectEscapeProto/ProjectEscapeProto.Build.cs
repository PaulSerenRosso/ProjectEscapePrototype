// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ProjectEscapeProto : ModuleRules
{
	public ProjectEscapeProto(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
