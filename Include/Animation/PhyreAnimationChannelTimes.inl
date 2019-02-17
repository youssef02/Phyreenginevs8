/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TIMES_INL
#define PHYRE_ANIMATION_CHANNEL_TIMES_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the time data for this data block.
		// Returns:
		// The time data for this data block.
		float *PAnimationChannelTimes::getTimeKeys()
		{
			return m_timeKeys.getArray();
		}

		// Description:
		// Gets the time data for this data block.
		// Returns:
		// A const pointer to the time data for this data block.
		const float *PAnimationChannelTimes::getTimeKeys() const
		{
			return m_timeKeys.getArray();
		}

		// Gets m_keyCount.
		PUInt32 PAnimationChannelTimes::getKeyCount() const
		{
			return m_keyCount;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TIMES_INL
