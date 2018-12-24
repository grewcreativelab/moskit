// Some copyright should be here...

using UnrealBuildTool;

public class Moskit : ModuleRules
{
	public Moskit(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"Moskit/Public",
				// ... add public include paths required here ...
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
				"Moskit/Private",
				// ... add other private include paths required here ...
			}
			);


        PublicDependencyModuleNames.AddRange(
                new string[]
                {
                "Core",
                "CoreUObject",
                "Engine",
                "Sockets","Networking",
                    // ... add other public dependencies that you statically link with here ...
                }
                );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Slate",
                "SlateCore",
                "HeadMountedDisplay",
                "SteamVR",
                "libprotobuf",
                "InputCore",
                "Http",  "Json",  "JsonUtilities",
				// ... add private dependencies that you statically link with here ...	
			}
            );

        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );
    }
}
