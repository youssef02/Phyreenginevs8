/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_HIERARCHY_POPULATE_ARRAYS_H
#define PHYRE_ANIMATION_HIERARCHY_POPULATE_ARRAYS_H

namespace Phyre
{
	namespace PAnimation
	{

		class PTimeController;
		class PAnimationDataSourceListEntry;
		class PAnimationDataSource;

		// Description:
		// An implementation of the hierarchy visit context that populates arrays with animation data sources. Duplicates are not entered into the array.
		class PAnimationHierarchyPopulateArrays : public PAnimationHierarchyVisitContext
		{
		protected:
			PAnimationDataSourceListEntry *m_animationDataSources;	// A pointer to an array of animation data source pointers.
			PUInt32 m_animationDataSourceCount;						// The number of animation data sources found.

		public:
			inline PAnimationHierarchyPopulateArrays(PAnimationDataSourceListEntry *animationDataSources);

			virtual bool visit(PTimeController &timeController, PAnimationHierarchyNode *parent);
			virtual bool visit(PAnimationDataSource &animDataSource, PAnimationHierarchyNode *parent);

			inline PUInt32 getAnimationDataSourceCount() const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_HIERARCHY_POPULATE_ARRAYS_H
