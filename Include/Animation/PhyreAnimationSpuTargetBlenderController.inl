/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_INL
#define PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the number of animation data sources processed by this animation network instance.
		// Returns:
		// Number of animation data sources that this animation network instance processes.
		PUInt32 PAnimationSpuTargetBlenderController::getSourceCount() const
		{
			return 1;
		}

		// Gets m_animDataSource.
		PAnimationDataSource *PAnimationSpuTargetBlenderController::getSource() const
		{
			return m_animDataSource;
		}

		// Description:
		// Gets a specific source of the blender controller.
		// Arguments:
		// index :  Index of the source to get.
		// Returns:
		// A pointer to the specified animation data source, or NULL if index is out of range or no source has been set.
		PAnimationDataSource *PAnimationSpuTargetBlenderController::getSource(PUInt32 index) const
		{
			return (index == 0) ? m_animDataSource : NULL;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_INL
