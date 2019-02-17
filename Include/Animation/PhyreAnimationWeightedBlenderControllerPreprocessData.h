/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_WEIGHTED_BLENDER_CONTROLLER_PREPROCESS_DATA_H
#define PHYRE_ANIMATION_WEIGHTED_BLENDER_CONTROLLER_PREPROCESS_DATA_H

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Encapsulates the preprocess data for a PAnimationWeightedBlenderController.
		class PAnimationWeightedBlenderControllerPreprocessData
		{
		public:
			float					m_weights[1];									// Weights to use to combine slot arrays.

			inline static PUInt32 Size(PUInt32 slotArrayCount);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_WEIGHTED_BLENDER_CONTROLLER_PREPROCESS_DATA_H
