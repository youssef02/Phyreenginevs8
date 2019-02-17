/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_BIND_H
#define PHYRE_ANIMATION_CHANNEL_TARGET_BIND_H

namespace Phyre
{
	namespace PAnimation
	{
		//! Forward declarations
		class PAnimationNetworkInstanceTarget;

		// Description:
		// The base class for binding animation channel targets to instantiated objects.
		class PAnimationChannelTargetBind
		{
		public:
			virtual ~PAnimationChannelTargetBind();

			// Description:
			// Attempts to locate named members for a given target object and type.
			// Arguments:
			// instanceTargets - The array of bound targets to be populated by the bind operation.
			// targets :    The array of targets to bind.
			// targetCount :   The number of targets to bind.
			// Return Value List:
			// PE_RESULT_NULL_POINTER_ARGUMENT : The instanceTargets or targets parameter was NULL.
			// PE_RESULT_NO_ERROR :            All nodes were found successfully.
			virtual PResult bindTargets(PAnimationNetworkInstanceTarget *instanceTargets, const PAnimationChannelTarget *targets, PUInt32 targetCount) = 0;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_BIND_H
