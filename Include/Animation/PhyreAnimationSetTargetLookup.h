/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SET_TARGET_LOOKUP_H
#define PHYRE_ANIMATION_SET_TARGET_LOOKUP_H

namespace Phyre
{
	namespace PAnimation
	{
		class PAnimationSet;
		class PAnimationChannelTarget;

		// Description:
		// An encapsulation of the key used to sort the tree. The token is stored as a const pointer.
		class PAnimationSetTargetLookupKey
		{
		public:
			PUInt32			m_hash;		// The hash of the token stored.
			const PChar		*m_token;	// The hashed token for the hash entry.

			inline PAnimationSetTargetLookupKey();
			static inline PInt32 Compare(const PAnimationSetTargetLookupKey &key1, const PAnimationSetTargetLookupKey &key2);

			inline void initKey(const PAnimationChannelTarget &target);
		};

		// Description:
		// The class for an entry in a red-black tree used to store a unique name. The token is stored as a const pointer.
		class PAnimationSetTargetLookupEntry : public PRedBlackTreeNode, public PAnimationSetTargetLookupKey
		{
		};

		// Description:
		// Represents a hash-table tree for efficiently storing and looking up unique names.
		class PAnimationSetTargetLookupTree : public PRedBlackTree
		{
		public:
			static inline PUInt32 Hash(const PAnimationChannelTarget &target);
			inline const PAnimationSetTargetLookupEntry *find(const PAnimationChannelTarget &target) const;
		};

		// Description:
		// The class used to accelerate the lookup of node names in an animation set. This uses a hash tree to lookup faster.
		class PAnimationSetTargetLookup
		{
			PHYRE_PRIVATE_ASSIGNMENT_OPERATOR(PAnimationSetTargetLookup);

		protected:
			const PAnimationSet &m_animSet;							// The animation set whose name lookups are being accelerated.
			PAnimationSetTargetLookupEntry *m_hashEntries;			// The hash entries for the node names.
			PAnimationSetTargetLookupTree m_hashTree;				// The hash tree that contains the hash entries.

		public:
			PAnimationSetTargetLookup(const PAnimationSet &animSet);
			~PAnimationSetTargetLookup();

			PInt32 getTargetIndex(const PAnimationChannelTarget &target) const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SET_TARGET_LOOKUP_H
