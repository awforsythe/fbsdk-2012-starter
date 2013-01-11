#include "PluginNameExampleBox.h"

FBBoxImplementation(PluginNameExampleBox);
FBRegisterBox("PluginNameExampleBox", PluginNameExampleBox, "PluginName", "PluginName Example Box", "", FB_DEFAULT_SDK_ICON);

/* FBCreate */
bool PluginNameExampleBox::FBCreate()
{
	if (ParentClass::FBCreate())
	{
		// Create input animation nodes
		mInNodeOperandA = AnimationNodeInCreate(0, "A", ANIMATIONNODE_TYPE_NUMBER);
		mInNodeOperandB = AnimationNodeInCreate(0, "B", ANIMATIONNODE_TYPE_NUMBER);

		// Create output animation nodes
		mOutNodeResult = AnimationNodeOutCreate(0, "Result", ANIMATIONNODE_TYPE_NUMBER);

		return true;
	}
	return false;
}

/* FBDestroy */
void PluginNameExampleBox::FBDestroy()
{
	ParentClass::FBDestroy();
}

/* AnimationNodeNotify */
bool PluginNameExampleBox::AnimationNodeNotify(HFBAnimationNode pAnimationNode, HFBEvaluateInfo pEvaluateInfo)
{
	double inDataOperandA, inDataOperandB;
	double outDataResult;

	// Read data from the input nodes
	if (mInNodeOperandA->ReadData(&inDataOperandA, pEvaluateInfo)
		&& mInNodeOperandB->ReadData(&inDataOperandB, pEvaluateInfo))
	{
		// Perform our calculation using that data
		outDataResult = inDataOperandA + inDataOperandB;
		
		// Write data to the output node
		mOutNodeResult->WriteData(&outDataResult, pEvaluateInfo);
		return true;
	}

	// The return value indicates whether data was written successfully
	return false;
}
