/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_VISITOR_FIND_NAMED_NODES_INL
#define PHYRE_VISITOR_FIND_NAMED_NODES_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PVisitorFindNicknamedNodes class.
		// Arguments:
		// rootOfSearch :  Root node of tree to search.
		PVisitorFindNicknamedNodes::PVisitorFindNicknamedNodes(PScene::PNode &rootOfSearch) 
			: m_rootOfSearch(rootOfSearch)
			, m_nodesFound(NULL)
			, m_treeNodes(NULL)
		{
			// Nothing here
		}

		// Description:
		// Compare function for two red black tree keys.
		// Arguments:
		// key1 :  Node in the tree to compare.
		// key2 :  Key value to compare.
		// Return Value List:
		// positive :  The key value for key1 is greater than key2.
		// zero :      The key value for key1 is equal to key2.
		// negative :  The key value for key1 is less than key2.
		PInt32 PVisitorFindNicknamedNodes::PTreeNodeKey::Compare(const PTreeNodeKey &key1, const PTreeNodeKey &key2)
		{
			PInt32 result;

			if (key1.m_hash > key2.m_hash)
				result = 1;
			else if (key1.m_hash < key2.m_hash)
				result = -1;
			else if (key1.m_compareLen > key2.m_compareLen)
				result = 1;
			else if (key1.m_compareLen < key2.m_compareLen)
				result = -1;
			else
				result = memcmp(key2.m_token, key1.m_token, key1.m_compareLen);

			return result;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_VISITOR_FIND_NAMED_NODES_INL
