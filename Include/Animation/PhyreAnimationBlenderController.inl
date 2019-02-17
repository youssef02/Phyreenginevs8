/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_BLENDER_CONTROLLER_INL
#define PHYRE_ANIMATION_BLENDER_CONTROLLER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the number of data sources for this blender controller
		// Returns:
		// Number of blender controller sources.
		PUInt32 PAnimationBlenderController::getSourceCount() const
		{
			return m_sources.getCount();
		}

		// Description:
		// Gets a specific source of the blender controller.
		// Arguments:
		// index :  Index of the source to get.
		// Returns:
		// A pointer to the specified animation data source, or NULL if index is out of range or no source has been set.
		PAnimationDataSource *PAnimationBlenderController::getSource(PUInt32 index) const
		{
			return (index < m_sources.getCount()) ? m_sources[index] : NULL;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_BLENDER_CONTROLLER_INL
