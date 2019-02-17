/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_HIERARCHY_COUNT_NODES_INL
#define PHYRE_ANIMATION_HIERARCHY_COUNT_NODES_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationHierarchyCountNodes class.
		PAnimationHierarchyCountNodes::PAnimationHierarchyCountNodes()
			: m_timeControllerCount(0)
			, m_animationDataSourceCount(0)
		{
			// Nothing here
		}

		// Gets m_timeControllerCount.
		PUInt32 PAnimationHierarchyCountNodes::getTimeControllerCount()
		{
			return m_timeControllerCount;
		}

		// Gets m_animationDataSourceCount.
		PUInt32 PAnimationHierarchyCountNodes::getAnimationDataSourceCount() const
		{
			return m_animationDataSourceCount;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_HIERARCHY_COUNT_NODES_INL
