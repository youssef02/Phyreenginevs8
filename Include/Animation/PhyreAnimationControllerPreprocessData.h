/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CONTROLLER_PREPROCESS_DATA_H
#define PHYRE_ANIMATION_CONTROLLER_PREPROCESS_DATA_H

namespace Phyre
{
	namespace PAnimation
	{

		//! Forward declarations.
		class PAnimationSet;
		class PAnimationClip;

		// Description:
		// Size of time key data to prefetch in an SPU animation controller.
		#define PD_ANIM_NETWORK_FETCHTIMESIZE	(3 * 16)

		// Description:
		// Size of value key data to prefetch in an SPU animation controller.
		#define PD_ANIM_NETWORK_FETCHVALUESIZE	(8 * 16)

		// Description:
		// Encapsulates the preprocess data for a PAnimationController.
		class PAnimationControllerPreprocessData
		{
		public:
			// Description:
			// Encapsulates the preprocess data for a channel to be processed by a PAnimationController.
			class PChannel
			{
			public:
				PUInt16	m_keyOffsetFetched;					// Index of key fetched.  8 keys will be fetched surrounding the current one.
				PUInt16	m_numKeysInChannel;					// Number of keys in this channel.
				PUInt16	m_keyWidth;							// Width of keys in this channel.
			};

			float		m_time;								// Current time value of animation controller.
			PUInt16		m_channelCount;						// Number of channels.
			PUInt16		m_constantChannelCount;				// Number of constant channels.
			PChannel	m_channel[1];						// Channel preprocess data info.

			inline static PUInt32 Size(PUInt32 channelCount);
		};

		// Description:
		// Holds per-instance cached data for one animation channel. This is used to exploit inter-frame coherence to speed up key searches.
		class PAnimationControllerPersistentData
		{
		public:
			PInt32 m_key;									// The key index for the animation channel.
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CONTROLLER_PREPROCESS_DATA_H
