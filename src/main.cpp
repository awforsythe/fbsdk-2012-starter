#include <fbsdk/fbsdk.h>
#include <windows.h>

FBLibraryDeclare(PluginName)
{
	FBLibraryRegister(PluginNameExampleBox);
	FBLibraryRegister(PluginNameExampleTool);
}
FBLibraryDeclareEnd;

bool FBLibrary::LibInit() { return true; }
bool FBLibrary::LibOpen() { return true; }
bool FBLibrary::LibReady() { return true; }
bool FBLibrary::LibClose() { return true; }
bool FBLibrary::LibRelease() { return true; }
