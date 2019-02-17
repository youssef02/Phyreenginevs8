/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_HIERARCHY_POPULATE_ARRAYS_INL
#define PHYRE_ANIMATION_HIERARCHY_POPULATE_ARRAYS_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationHierarchyPopulateArrays class.
		// Arguments:
		// animationDataSources :  Pointer to array of animation data source pointers to populate.
		PAnimationHierarchyPopulateArrays::PAnimationHierarchyPopulateArrays(PAnimationDataSourceListEntry *animationDataSources)
			: m_animationDataSources(animationDataSources)
			, m_animationDataSourceCount(0)
		{
			// Nothing here
		}

		// Gets m_animationDataSourceCount.
		PUInt32 PAnimationHierarchyPopulateArrays::getAnimationDataSourceCount() const
		{
			return m_animationDataSourceCount;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_HIERARCHY_POPULATE_ARRAYS_INL
