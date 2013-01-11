#include "PluginNameExampleTool.h"

#include <iostream>

FBToolImplementation(PluginNameExampleTool);
FBRegisterTool(PluginNameExampleTool, "PluginName Example Tool", "", FB_DEFAULT_SDK_ICON);

using std::cout;
using std::endl;

/* FBCreate */
bool PluginNameExampleTool::FBCreate()
{
	if (ParentClass::FBCreate())
	{
		// Set the initial size and minimum size of the tool window
		StartSize[0] = 192;
		StartSize[1] = 96;

		MinSize[0] = 64;
		MinSize[1] = 32;

		// Create a region and assign our button to it
		AddRegion("ButtonTest", "ButtonTest",
			4,  kFBAttachLeft,   "", 1.0,
			4,  kFBAttachTop,    "", 1.0,
			-4, kFBAttachRight,  "", 1.0,
			-4, kFBAttachBottom, "", 1.0);
		SetControl("ButtonTest", mButtonTest);

		// Configure the button, setting its caption and adding a click callback
		mButtonTest.Caption = "Test";
		mButtonTest.OnClick.Add(this, (FBCallback)&PluginNameExampleTool::OnButtonTestClick);

		return true;
	}
	return false;
}

/* FBDestroy */
void PluginNameExampleTool::FBDestroy()
{
	ParentClass::FBDestroy();
}

/* OnButtonTestClick */
void PluginNameExampleTool::OnButtonTestClick(HISender pSender, HKEvent pEvent)
{
	// Create a new cube and show it
	HFBModelCube testCube = new FBModelCube("PluginName:Cube");
	testCube->FBCreate();
	testCube->Show = true;

	// Print a message to stdout (motionbuilder.exe -console)
	cout << "Test cube created: " << testCube->LongName << endl;
}
