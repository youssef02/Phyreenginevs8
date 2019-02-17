/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_HIERARCHY_NODE_H
#define PHYRE_ANIMATION_HIERARCHY_NODE_H

namespace Phyre
{
	namespace PAnimation
	{
		class PAnimationHierarchyNode;
		class PTimeController;
		class PAnimationDataSource;

		// Description:
		// Provides a context base for visiting animation hierarchy nodes. Override the visit() and postVisit() methods with behavior specific
		// to your application.
		class PAnimationHierarchyVisitContext
		{
		public:
			virtual ~PAnimationHierarchyVisitContext();

			virtual bool visit(PTimeController &timeController, PAnimationHierarchyNode *parent);
			virtual bool visit(PAnimationDataSource &animDataSource, PAnimationHierarchyNode *parent);
			virtual void postVisit(PTimeController &timeController, PAnimationHierarchyNode *parent);
			virtual void postVisit(PAnimationDataSource &animDataSource, PAnimationHierarchyNode *parent);
		};

		// Description:
		// Provides enumeration functionality. The virtual method is implemented and calls back to an enumerator object that implements node visit behavior.
		class PAnimationHierarchyNode : public PBase
		{
		public:
			PUInt32 m_visitAge;								// Visit age used to detect loops in hierarchies.

			PHYRE_BIND_DECLARE_CLASS_ABSTRACT(PAnimationHierarchyNode, PBase);

		public:
			PAnimationHierarchyNode();
			virtual ~PAnimationHierarchyNode();

			virtual PUInt32 getSourceCount() const;
			virtual PAnimationDataSource *getSource(PUInt32 index) const;

			// Description:
			// Calls the visit() and postVisit() methods defined on context, and then recurses with
			// dependencies. Traverses the animation hierarchy. Virtual method defined on derived classes.
			// Arguments:
			// context :  Context to visit with this node.
			// parent :   Parent pointer (this pointer from caller).
			// Return Value List:
			// true : Continue the visitation traversal.
			// false : Terminate the visitation traversal.
			virtual bool traverseHierarchy(PAnimationHierarchyVisitContext &context, PAnimationHierarchyNode *parent = NULL) = 0;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_HIERARCHY_NODE_H
