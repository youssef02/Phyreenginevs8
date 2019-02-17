/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SET_TARGET_LOOKUP_INL
#define PHYRE_ANIMATION_SET_TARGET_LOOKUP_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationSetTargetLookupKey class.
		PAnimationSetTargetLookupKey::PAnimationSetTargetLookupKey()
			: m_hash(0)
			, m_token(NULL)
		{
		}

		// Description:
		// The compare function for the two red black tree keys.
		// Arguments:
		// key1 :  The node in the tree to compare.
		// key2 :  The key value to compare.
		// Return Value List:
		// positive :  The key value for key1 is greater than key2.
		// zero :      The key value for key1 is equal to key2.
		// negative :  The key value for key1 is less than key2.
		PInt32 PAnimationSetTargetLookupKey::Compare(const PAnimationSetTargetLookupKey &key1, const PAnimationSetTargetLookupKey &key2)
		{
			PInt32 result;

			if (key1.m_hash > key2.m_hash)
				result = 1;
			else if (key1.m_hash < key2.m_hash)
				result = -1;
			else
				result = strcmp(key2.m_token, key1.m_token);

			return result;
		}

		// Description:
		// Initializes the key for the specified animation channel target.
		// Arguments:
		// target - The animation channel target to initialize for.
		void PAnimationSetTargetLookupKey::initKey(const PAnimationChannelTarget &target)
		{
			const PChar *name = target.getTargetName();
			if (!name)
				name = "Un-named";

			m_token = name;
			m_hash = PAnimationSetTargetLookupTree::Hash(target);
		}

		// Description:
		// Hashes the channel target to a 32 bit value.
		// Arguments:
		// target - The target to hash.
		// Returns:
		// The hash value for the animation channel target.
		PUInt32 PAnimationSetTargetLookupTree::Hash(const PAnimationChannelTarget &target)
		{
			const PChar *name = target.getTargetName();
			if (!name)
				name = "Un-named";

			PUInt32 hash = PHashTableTree::Hash((const PUInt8 *)name);					// Hash string.
			hash = hash ^ target.getTargetType();										// Hash target type.
			hash = hash ^ (PUInt32)PHYRE_PTR_TO_UINT(&target.getTargetObjectType());	// Hash instance object type.
			hash = hash ^ (PUInt32)PHYRE_PTR_TO_UINT(target.getTargetObject());			// Hash instance object.
			hash = hash ^ (PUInt32)PHYRE_PTR_TO_UINT(target.getTargetBaseObjectType());	// Hash base object type.
			hash = hash ^ (PUInt32)PHYRE_PTR_TO_UINT(target.getTargetBaseObject());		// Hash base object.
			hash = hash ^ target.getTargetIndex();										// Hash target index.

			return hash;
		}

		// Description:
		// Finds the animation set target that matches the specified animation channel target.
		// Arguments:
		// target - The target to look for.
		// Returns:
		// A pointer to the found node, or NULL if the target was not found.
		const PAnimationSetTargetLookupEntry *PAnimationSetTargetLookupTree::find(const PAnimationChannelTarget &target) const
		{
			PAnimationSetTargetLookupKey	key;

			key.initKey(target);

			return findKey<PAnimationSetTargetLookupEntry>(key);
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SET_TARGET_LOOKUP_INL
