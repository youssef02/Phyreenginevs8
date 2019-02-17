/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SET_INL
#define PHYRE_ANIMATION_SET_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the number of animations in this animation set.
		// Returns:
		// Number of animations.
		PUInt32 PAnimationSet::getAnimationClipCount() const
		{
			return m_animationClips.getCount();
		}

		// Description:
		// Gets the number of target nodes in the animation set.
		// Returns:
		// Number of nodes.
		PUInt32 PAnimationSet::getTargetCount() const
		{
			return m_targets.getCount();
		}

		// Description:
		// Gets a specific animation from this animation set.
		// Arguments:
		// index :  Index of animation to obtain.
		// Returns:
		// A pointer to animation, or NULL if the specified index is out of range.
		PAnimationClip *PAnimationSet::getAnimationClip(PUInt32 index) const
		{
			return (index < m_animationClips.getCount()) ? m_animationClips[index] : NULL;
		}

		// Description:
		// Gets the specified target.
		// Arguments:
		// index :  Index of the target to get.
		// Returns:
		// The requested target, or NULL if the specified index is out of range.
		const PAnimationChannelTarget *PAnimationSet::getTarget(PUInt32 index) const
		{
			return (index < m_targets.getCount()) ? &m_targets[index] : NULL;
		}

		// Description:
		// Gets the maximum size of a slot array needed for this animation set. This is the size of the union set of all slot array indices, and differs from the
		// node count due to the different types of keys involved.
		// Returns:
		// Size of slot array needed to accommodate any combination of animations from this animation set.
		PUInt32 PAnimationSet::getSlotArraySize() const
		{
			return m_slotArrayIndices.getCount();
		}

		// Description:
		// Accessor for the array of slot list indices that describe what each entry in the slot array represents.
		// Returns:
		// A pointer to array of PAnimationSlotListIndex objects that describe each entry in the slot array.
		const PAnimationSlotListIndex *PAnimationSet::getSlotArrayIndices() const
		{
			return m_slotArrayIndices.getArray();
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SET_INL
