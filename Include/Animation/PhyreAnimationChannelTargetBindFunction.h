/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_BIND_FUNCTION_H
#define PHYRE_ANIMATION_CHANNEL_TARGET_BIND_FUNCTION_H

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The class for binding animation channel targets to named functions.
		class PAnimationChannelTargetBindFunction : public PAnimationChannelTargetBind
		{
			PHYRE_PRIVATE_ASSIGNMENT_OPERATOR(PAnimationChannelTargetBindFunction);

		protected:
			const PClassDescriptor &m_bindClassDescriptor;			// The class descriptor for the bind target.

		public:
			inline PAnimationChannelTargetBindFunction(const PClassDescriptor &bindClassDescriptor);

			virtual PResult bindTargets(PAnimationNetworkInstanceTarget *instanceTargets, const PAnimationChannelTarget *targets, PUInt32 targetCount);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_BIND_FUNCTION_H
