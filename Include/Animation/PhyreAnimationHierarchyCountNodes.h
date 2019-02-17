/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_HIERARCHY_COUNT_NODES_H
#define PHYRE_ANIMATION_HIERARCHY_COUNT_NODES_H

namespace Phyre
{
	namespace PAnimation
	{

		//! Forward declarations:
		class PTimeController;
		class PAnimationDataSource;
		class PAnimationHierarchyNode;

		// Description:
		// An implementation of the hierarchy visit context that counts the time controllers and animation data sources within a network.
		class PAnimationHierarchyCountNodes : public PAnimationHierarchyVisitContext
		{
		protected:
			PUInt32 m_timeControllerCount;					// Number of time controllers found.
			PUInt32 m_animationDataSourceCount;				// Number of animation data sources found.

		public:
			inline PAnimationHierarchyCountNodes();

			virtual bool visit(PTimeController &timeController, PAnimationHierarchyNode *parent);
			virtual bool visit(PAnimationDataSource &animDataSource, PAnimationHierarchyNode *parent);

			inline PUInt32 getTimeControllerCount();
			inline virtual PUInt32 getAnimationDataSourceCount() const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_HIERARCHY_COUNT_NODES_H
