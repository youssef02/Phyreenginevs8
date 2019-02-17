/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CLIP_INL
#define PHYRE_ANIMATION_CLIP_INL

namespace Phyre
{
	namespace PAnimation
	{
		// Sets m_name.
		void PAnimationClip::setName(const PChar *name)
		{
			m_name = name;
		}

		// Gets m_name.
		const PString &PAnimationClip::getName() const
		{ 
			return m_name;
		}

		// Gets m_binding.
		const PAnimationClipBinding *PAnimationClip::getBinding() const
		{
			return m_binding;
		}

		// Description:
		// Gets the number of animation channels in this animation.
		// Returns:
		// The number of animation channels.
		PUInt32 PAnimationClip::getAnimationChannelCount() const
		{
			return m_channels.getCount();
		}

		// Description:
		// Gets a pointer to the animation channel/node pairs.
		// Returns:
		// A pointer to the animation channel node pair array.
		PAnimationChannel *const *PAnimationClip::getAnimationChannels() const
		{
			return m_channels.getArray();
		}

		// Description:
		// Gets a pointer to the specified animation channel.
		// Arguments:
		// index :  The index of an animation channel to get the pointer to.
		// Returns:
		// A pointer to the channel.
		PAnimationChannel *PAnimationClip::getAnimationChannel(PUInt32 index)
		{
			PHYRE_ASSERTMSG(index<m_channels.getCount(), "PAnimationClip::getAnimationChannel : Channel index specified was out of range");
			return m_channels[index];
		}

		// Description:
		// Gets a pointer to the specified animation channel.
		// Arguments:
		// index :  The index of animation channel to get the pointer to.
		// Returns:
		// A pointer to the channel.
		const PAnimationChannel *PAnimationClip::getAnimationChannel(PUInt32 index) const
		{
			PHYRE_ASSERTMSG(index<m_channels.getCount(), "PAnimationClip::getAnimationChannel : Channel index specified was out of range");
			return m_channels[index];
		}

		// Description:
		// Gets the number of constant channels in this animation.
		// Returns:
		// The number of constant channels.
		PUInt32 PAnimationClip::getAnimationConstantChannelCount() const
		{
			return m_constantChannels.getCount();
		}

		// Description:
		// Gets the array of constant channels in this animation.
		// Returns:
		// A pointer to the array of constant channels.
		const PAnimationConstantChannel *PAnimationClip::getAnimationConstantChannels() const
		{
			return m_constantChannels.getArray();
		}

		// Description:
		// Gets the array of constant channels in this animation.
		// Arguments:
		// index : The index of the constant animation channel to get the pointer to.
		// Returns:
		// A pointer to the array of constant channels.
		PAnimationConstantChannel *PAnimationClip::getAnimationConstantChannel(PUInt32 index)
		{
			PHYRE_ASSERTMSG(index<m_constantChannels.getCount(), "PAnimationClip::getAnimationConstantChannel : Channel index specified was out of range");
			return &m_constantChannels[index];
		}

		// Description:
		// Gets the array of constant channels in this animation.
		// Arguments:
		// index : The index of the constant animation channel to get the pointer to.
		// Returns:
		// A pointer to the array of constant channels.
		const PAnimationConstantChannel *PAnimationClip::getAnimationConstantChannel(PUInt32 index) const
		{
			PHYRE_ASSERTMSG(index<m_constantChannels.getCount(), "PAnimationClip::getAnimationConstantChannel : Channel index specified was out of range");
			return &m_constantChannels[index];
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CLIP_INL
