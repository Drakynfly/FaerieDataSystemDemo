// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

using UnrealBuildTool;

public class FDS_DEV : ModuleRules
{
	public FDS_DEV(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		// Engine dependencies
		PublicDependencyModuleNames.AddRange(new []
		{
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"GameplayTags",
			"StructUtils",
			"UMG",
			"SlateCore"
		});

		// Plugin dependencies
		PublicDependencyModuleNames.AddRange(new []
		{
			"FaerieInventory",
			"Squirrel",
			"FaerieItemData"
		});
	}
}