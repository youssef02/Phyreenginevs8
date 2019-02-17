/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SLOT_FILTER_PREPROCESS_DATA_INL
#define PHYRE_ANIMATION_SLOT_FILTER_PREPROCESS_DATA_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the size of the preprocess data block for the specified slot block count.
		// Arguments:
		// slotBlockCount - The number of blocked slots.
		// Returns:
		// The size of the preprocess data block for the specified number of blocked slots.
		PUInt32 PAnimationSlotFilterPreprocessData::Size(PUInt32 slotBlockCount)
		{
			return sizeof(PAnimationSlotFilterPreprocessData) + (slotBlockCount-1) * sizeof(PUInt32);
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SLOT_FILTER_PREPROCESS_DATA_INL
