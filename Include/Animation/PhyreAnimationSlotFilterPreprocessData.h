/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SLOT_FILTER_PREPROCESS_DATA_H
#define PHYRE_ANIMATION_SLOT_FILTER_PREPROCESS_DATA_H

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Encapsulates the preprocess data for a PAnimationSlotFilter.
		class PAnimationSlotFilterPreprocessData
		{
		public:
			PUInt32		m_slotBlockCount;									// Number of blocked slots
			PUInt32		m_slotBlockList[1];									// Variable size array of blocked slots.

			inline static PUInt32 Size(PUInt32 slotBlockCount);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SLOT_FILTER_PREPROCESS_DATA_H
