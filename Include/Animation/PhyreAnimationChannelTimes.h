/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TIMES_H
#define PHYRE_ANIMATION_CHANNEL_TIMES_H

namespace Phyre
{
	namespace PAnimation
	{
		// Description:
		// The class for combining key time and key value data. When combined with a target node index in an animation, they form part of an entire animation.
		// The channels target one attribute of a node (for example, rotation, translation, scale, and so forth).
		class PAnimationChannelTimes : public PBase
		{
		protected:
			PUInt32 m_keyCount;											// The number of keys.
			PArray<float> m_timeKeys;									// The time key data.

			PHYRE_BIND_DECLARE_CLASS(PAnimationChannelTimes, PBase);

		public:
			PAnimationChannelTimes();
			~PAnimationChannelTimes();

			PResult setKeyCount(PUInt32 keyCount);

			inline float *getTimeKeys();
			inline const float *getTimeKeys() const;
			inline PUInt32 getKeyCount() const;

			PUInt32 findKeyIndexForTime(float time, float &t) const;
			PUInt32 findKeyIndexForTime(float time, PUInt32 key, float &t) const;
			PResult getTimeExtents(float &minTime, float &maxTime) const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TIMES_H
