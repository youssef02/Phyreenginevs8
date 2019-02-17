/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SET_SLOT_LIST_INDEX_LOOKUP_INL
#define PHYRE_ANIMATION_SET_SLOT_LIST_INDEX_LOOKUP_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Compare function for two red black tree keys.
		// Arguments:
		// key1 :  Node in the tree to compare.
		// key2 :  Key value to compare.
		// Return Value List:
		// positive :  The key value for key1 is greater than key2.
		// zero :      The key value for key1 is equal to key2.
		// negative :  The key value for key1 is less than key2.
		PInt32 PAnimationSetSlotListIndexLookup::PTreeNodeKey::Compare(const PTreeNodeKey &key1, const PTreeNodeKey &key2)
		{
			PInt32 result;

			if (key1.m_hash > key2.m_hash)
				result = 1;
			else if (key1.m_hash < key2.m_hash)
				result = -1;
			else
				result = 0;

			return result;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SET_SLOT_LIST_INDEX_LOOKUP_INL
