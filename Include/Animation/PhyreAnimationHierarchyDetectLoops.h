/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_HIERARCHY_DETECT_LOOPS_H
#define PHYRE_ANIMATION_HIERARCHY_DETECT_LOOPS_H

namespace Phyre
{
	namespace PAnimation
	{
		//! Forward declarations:
		class PTimeController;
		class PAnimationDataSource;
		class PAnimationHierarchyNode;

		// Description:
		// An implementation of the hierarchy visit context that detects cycles within the animation network. It uses the early-out mechanism of the visit
		// function to abort traversal if a loop is found.
		class PAnimationHierarchyDetectLoops : public PAnimationHierarchyVisitContext
		{
		protected:
			static PUInt32		s_visitAge;

			PUInt32				m_visitAge;				// The visit age for this context.

		public:
			PAnimationHierarchyDetectLoops();

			virtual bool visit(PTimeController &timeController, PAnimationHierarchyNode *parent);
			virtual void postVisit(PTimeController &timeController, PAnimationHierarchyNode *parent);

			virtual bool visit(PAnimationDataSource &animDataSource, PAnimationHierarchyNode *parent);
			virtual void postVisit(PAnimationDataSource &animDataSource, PAnimationHierarchyNode *parent);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_HIERARCHY_DETECT_LOOPS_H
