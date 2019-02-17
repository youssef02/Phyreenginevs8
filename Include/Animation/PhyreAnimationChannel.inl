/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_INL
#define PHYRE_ANIMATION_CHANNEL_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the key data for this data block.
		// Returns:
		// The key data for this data block.
		float *PAnimationChannel::getValueKeys()
		{
			return m_valueKeys.getArray();
		}

		// Description:
		// Gets the key data for this data block.
		// Returns:
		// The key data for this data block.
		const float *PAnimationChannel::getValueKeys() const
		{
			return m_valueKeys.getArray();
		}

		// Gets m_times.
		PAnimationChannelTimes *PAnimationChannel::getTimes() const
		{
			return m_times;
		}

		// Gets m_keyCount.
		PUInt32 PAnimationChannel::getKeyCount() const
		{
			return m_keyCount;
		}

		// Description:
		// Gets the time extents of the animation channel.
		// Arguments:
		// minTime :  Pointer to float to receive the minimum time value.
		// maxTime :  Pointer to float to receive the maximum time value.
		// Return Value List:
		// PE_RESULT_NO_ERROR :                  The operation was completed successfully.
		// PE_RESULT_INSUFFICIENT_INFORMATION :  The animation channel had no time keys.
		PResult PAnimationChannel::getTimeExtents(float &minTime, float &maxTime) const
		{
			if (!m_times)
				return PE_RESULT_INSUFFICIENT_INFORMATION;

			return m_times->getTimeExtents(minTime, maxTime);
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_INL
