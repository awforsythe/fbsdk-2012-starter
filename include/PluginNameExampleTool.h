#pragma once
/** \class PluginNameExampleTool
	
	A simple tool which demonstrates how to implement a custom FBTool. This
	tool will show up in the OpenReality -> Tools menu. It contains a single
	button that creates a cube and prints a message to the console.
*/

#include <fbsdk/fbsdk.h>

class PluginNameExampleTool : public FBTool
{
	FBToolDeclare(PluginNameExampleTool, FBTool);

public:

	/** Called when the tool is first created. Allows us to set up the UI. */
	virtual bool FBCreate();

	/** Called when the tool is deleted (typically on exit, and not when the tool window is simply closed). */
	virtual void FBDestroy();

private:

	/** Callback invoked when the test button is clicked. Creates a cube. */
	void OnButtonTestClick(HISender pSender, HKEvent pEvent);

protected:
	/** UI Components */
	FBButton mButtonTest;
};
