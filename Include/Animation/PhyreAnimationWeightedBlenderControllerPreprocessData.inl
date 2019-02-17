/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_WEIGHTED_BLENDER_CONTROLLER_PREPROCESS_DATA_INL
#define PHYRE_ANIMATION_WEIGHTED_BLENDER_CONTROLLER_PREPROCESS_DATA_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the size of the preprocess data block for a specified slot array count.
		// Arguments:
		// slotArrayCount - The number of slot arrays to blend.
		// Returns:
		// The size of the preprocess data block for the specified number of slot arrays.
		PUInt32 PAnimationWeightedBlenderControllerPreprocessData::Size(PUInt32 slotArrayCount)
		{
			return sizeof(PAnimationWeightedBlenderControllerPreprocessData) + (slotArrayCount-1) * sizeof(float);
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_WEIGHTED_BLENDER_CONTROLLER_PREPROCESS_DATA_INL
