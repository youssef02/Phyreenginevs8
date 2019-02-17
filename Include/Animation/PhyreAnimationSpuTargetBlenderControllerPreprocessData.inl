/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_PREPROCESS_DATA_INL
#define PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_PREPROCESS_DATA_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the size of the preprocess data block for a specified slot array size.
		// Arguments:
		// slotArraySize - The size of the slot array to process.
		// Returns:
		// The size of the preprocess data block for the specified slot array size.
		PUInt32 PAnimationSpuTargetBlenderControllerPreprocessData::Size(PUInt32 slotArraySize)
		{
			return sizeof(PAnimationSpuTargetBlenderControllerPreprocessData) + (slotArraySize-1) * sizeof(PSpu::PAddr);
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_PREPROCESS_DATA_INL
