#pragma once
/** \class PluginNameExampleBox

	A simple box which demonstrates how to implement a custom FBBox subclass.
	This box simply adds two floating-point numbers together.
*/

#include <fbsdk/fbsdk.h>

class PluginNameExampleBox : public FBBox
{
	FBBoxDeclare(PluginNameExampleBox, FBBox);

public:

	/** Called by MotionBuilder when the box is created. Initializes nodes. */
	virtual bool FBCreate();

	/** Called by MotionBuilder when the box is deleted. Allows cleanup. */
	virtual void FBDestroy();

	/** Called by MotionBuilder on every frame that data is requested from the box. */
	virtual bool AnimationNodeNotify(HFBAnimationNode pAnimationNode, HFBEvaluateInfo pEvaluateInfo);

protected:
	/** Input animation nodes. */
	HFBAnimationNode mInNodeOperandA;
	HFBAnimationNode mInNodeOperandB;

	/** Output animation nodes. */
	HFBAnimationNode mOutNodeResult;
};
