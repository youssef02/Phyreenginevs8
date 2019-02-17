/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_WEIGHTED_BLENDER_CONTROLLER_INL
#define PHYRE_ANIMATION_WEIGHTED_BLENDER_CONTROLLER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the blend weight of a specific source.
		// Arguments:
		// index :  Index of the source weight to get.
		// Returns:
		// The blend weight of the source (or 0 if the index was out of range).
		float PAnimationWeightedBlenderController::getWeight(PUInt32 index) const
		{
			return (index < m_sourceWeights.getCount()) ? m_sourceWeights[index] : 0.0f;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_WEIGHTED_BLENDER_CONTROLLER_INL
