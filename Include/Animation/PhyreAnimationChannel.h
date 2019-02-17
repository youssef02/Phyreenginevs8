/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_H
#define PHYRE_ANIMATION_CHANNEL_H

namespace Phyre
{
	namespace PAnimation
	{
		class PAnimationKeyDataType;

		// Description:
		// The class for combining key time and key value data. When combined with a target node index in an animation, they form part of an entire animation.
		// Channels target one attribute of a node (for example, rotation, translation, scale, and so forth).
		class PAnimationChannel : public PAnimationChannelBase
		{
		protected:
			PAnimationChannelTimes *m_times;							// Time data.
			PArray<float> m_valueKeys;									// Value key data.
			PUInt32 m_keyCount;											// Number of keys.

			PHYRE_BIND_DECLARE_CLASS(PAnimationChannel, PAnimationChannelBase);

		public:
			PAnimationChannel();
			~PAnimationChannel();

			PResult setKeyTypeAndCount(const PAnimationKeyDataType *keyType, PUInt32 keyCount);
			PResult setTimes(PAnimationChannelTimes *times);

			inline float *getValueKeys();
			inline const float *getValueKeys() const;
			inline PAnimationChannelTimes *getTimes() const;
			inline PUInt32 getKeyCount() const;

			const float *getKey(PUInt32 index) const;
			PResult interpKey(PUInt32 key, float t, float *PHYRE_RESTRICT result) const;
			PResult getLerpKey(float time, float *PHYRE_RESTRICT result) const;
			PResult getLerpKey(float time, float *PHYRE_RESTRICT result, PInt32 &key) const;

			inline PResult getTimeExtents(float &minTime, float &maxTime) const;

			PUInt32 getBatchSortKey() const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_H
