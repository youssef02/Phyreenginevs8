/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_VISITOR_FIND_NAMED_NODES_H
#define PHYRE_VISITOR_FIND_NAMED_NODES_H

namespace Phyre
{
	namespace PScene
	{
		class PNode;
	} //! End of PScene namespace

	namespace PAnimation
	{
		// Description:
		// A visitor class to search a hierarchy for a list of nodes with specific nicknames.
		class PVisitorFindNicknamedNodes
		{
			PHYRE_PRIVATE_ASSIGNMENT_OPERATOR(PVisitorFindNicknamedNodes);

		protected:
			// Description:
			// Encapsulation of key used to sort tree. The token is stored as a non const pointer.
			class PTreeNodeKey
			{
			public:
				PUInt32	m_hash;			// Hash of token stored.
				PUInt32	m_compareLen;	// Length of string compare.
				const PChar	*m_token;	// Hashed token for the hash entry.

				inline static PInt32 Compare(const PTreeNodeKey &key1, const PTreeNodeKey &key2);
			};

			// Description:
			// Class for an entry in a red-black tree to store a nickname being searched for.
			class PTreeNode : public PRedBlackTreeNode, public PTreeNodeKey
			{
			};

			PScene::PNode &m_rootOfSearch;								// Root of scene graph tree to search.
			PScene::PNode **m_nodesFound;								// Nodes we are searching for (if found).
			PTreeNode *m_treeNodes;										// Array of nodes in the tree.
			PRedBlackTree m_tree;										// Tree containing the hashed nicknames to find.

		public:
			// Description:
			// The constructor for the PVisitorFindNicknamedNodes class.
			// Arguments:
			// rootOfSearch :  Root node of tree to search.
			inline PVisitorFindNicknamedNodes(PScene::PNode &rootOfSearch);

			PResult visit(PScene::PNode &node);
			void findNodes(const PChar *const *nicknames, PScene::PNode **nodes, PUInt32 numNicknames);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_VISITOR_FIND_NAMED_NODES_H
