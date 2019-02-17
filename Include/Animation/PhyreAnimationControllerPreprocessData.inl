/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CONTROLLER_PREPROCESS_DATA_INL
#define PHYRE_ANIMATION_CONTROLLER_PREPROCESS_DATA_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the size of the preprocess data block for the specified channel count.
		// Arguments:
		// channelCount : The number of animation channels.
		// Returns:
		// The size of the preprocess data block for the specified channel count.
		PUInt32 PAnimationControllerPreprocessData::Size(PUInt32 channelCount)
		{
			return sizeof(PAnimationControllerPreprocessData) + ((channelCount - 1) * sizeof(PChannel));
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CONTROLLER_PREPROCESS_DATA_INL
