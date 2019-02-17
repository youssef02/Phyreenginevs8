/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_ADDITIVE_BLENDER_CONTROLLER_PREPROCESS_DATA_H
#define PHYRE_ANIMATION_ADDITIVE_BLENDER_CONTROLLER_PREPROCESS_DATA_H

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Encapsulates the preprocess data for a PAnimationAdditiveBlenderController.
		class PAnimationAdditiveBlenderControllerPreprocessData
		{
		public:
			float					m_weights[1];									// The weights to use when combining the slot arrays.

			static inline PUInt32 Size(PUInt32 slotArrayCount);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_ADDITIVE_BLENDER_CONTROLLER_PREPROCESS_DATA_H
