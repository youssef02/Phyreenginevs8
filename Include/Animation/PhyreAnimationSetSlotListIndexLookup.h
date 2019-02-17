/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SET_SLOT_LIST_INDEX_LOOKUP_H
#define PHYRE_ANIMATION_SET_SLOT_LIST_INDEX_LOOKUP_H

namespace Phyre
{
	namespace PAnimation
	{
		class PAnimationSet;
		class PAnimationSlotListIndex;

		// Description:
		// Class used to acclerate the lookup of slot array indices in the animation set
		class PAnimationSetSlotListIndexLookup
		{
			PHYRE_PRIVATE_ASSIGNMENT_OPERATOR(PAnimationSetSlotListIndexLookup);

		protected:
			// Description:
			// Encapsulation of key used to sort tree. The token is stored as a non const pointer.
			class PTreeNodeKey
			{
			public:
				PUInt32 m_hash;	// Hash for this key.

				inline static PInt32 Compare(const PTreeNodeKey &key1, const PTreeNodeKey &key2);
			};

			// Description:
			// Class for an entry in a red-black tree to store a slot list index being searched for.
			class PTreeNode : public PRedBlackTreeNode, public PTreeNodeKey
			{
			};

			const PAnimationSet &m_animSet;						// The animation set whose slot list lookups are being accelerated.
			PTreeNode *m_treeNodes;								// The entries for slot list indices.
			PRedBlackTree m_tree;								// The tree that contains the tree nodes.

		public:
			PAnimationSetSlotListIndexLookup(const PAnimationSet &animSet);
			~PAnimationSetSlotListIndexLookup();

			PInt32 findSlotArrayIndex(const PAnimationSlotListIndex &listIndex);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SET_SLOT_LIST_INDEX_LOOKUP_H
