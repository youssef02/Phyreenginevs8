/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SET_H
#define PHYRE_ANIMATION_SET_H

namespace Phyre
{
	namespace PAnimation
	{
		//! Forward declarations:
		class PAnimationClip;
		class PAnimationSlotListIndex;

		// Description:
		// Animation sets are a collection of animations. The PAnimationSet object also contains the list of node names that channels are targeted at.
		// The introspection API is necessary here for editing.
		class PAnimationSet : public PBase
		{
		protected:
			PSharray<PAnimationClip *> m_animationClips;							// Array of animations in this animation set.

			// This is the mapping from named nodes to slot IDs.  This forms the initial mapping from animations to slot lists.  The unmapping from slot lists to nodes is
			// described in the animation network instance.
			PArray<PAnimationChannelTarget> m_targets;								// Targets for all nodes.

			PArray<PAnimationSlotListIndex> m_slotArrayIndices;						// Indices of slot array entries.

			PResult setAnimationClipCount(PUInt32 animationClipCount);
			PResult updateSlotArraySize();

			PHYRE_BIND_DECLARE_CLASS(PAnimationSet, PBase);

		public:
			PAnimationSet();
			~PAnimationSet();

			//! Animation clips
			inline PUInt32 getAnimationClipCount() const;
			inline PAnimationClip *getAnimationClip(PUInt32 index) const;
			PResult removeAnimationClip(PAnimationClip *animation);
			PResult setAnimationClip(PUInt32 index, PAnimationClip *animation);

			PResult compile(PCluster &cluster);

			PAnimationClip *findAnimationClip(PAnimationClip &animation) const;
			PResult appendAnimation(PAnimationClip *animation);

			//! Slot array
			inline PUInt32 getSlotArraySize() const;
			inline const PAnimationSlotListIndex *getSlotArrayIndices() const;
			PInt32 findSlotArrayIndex(const PAnimationSlotListIndex &listIndex) const;

			//! Targeting
			inline PUInt32 getTargetCount() const;
			inline const PAnimationChannelTarget *getTarget(PUInt32 index) const;
			PInt32 findTargetIndex(const PAnimationChannelTarget &target) const;

			PAnimationClip *findAnimationClipByName(const PChar *name);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SET_H
