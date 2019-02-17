/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_PREPROCESS_DATA_H
#define PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_PREPROCESS_DATA_H

namespace Phyre
{
	namespace PAnimation
	{

		//! Forward declarations.
		class PAnimationKeyDataType;

		// Description:
		// Encapsulates the preprocess data for a PAnimationSpuTargetBlenderController.
		class PAnimationSpuTargetBlenderControllerPreprocessData
		{
		public:
			const PAnimationKeyDataType	*m_rotationKeyType;		// Key type ID for rotations.
			const PAnimationKeyDataType	*m_scaleKeyType;		// Key type ID for scales.
			const PAnimationKeyDataType	*m_translationKeyType;	// Key type ID for translations.

			PSpu::PAddr			m_targetMatrix[1];				// Variable size array of matrix targets for slot array elements.

			inline static PUInt32 Size(PUInt32 slotArraySize);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_PREPROCESS_DATA_H
