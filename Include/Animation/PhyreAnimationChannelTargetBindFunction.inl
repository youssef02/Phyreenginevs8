/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_BIND_FUNCTION_INL
#define PHYRE_ANIMATION_CHANNEL_TARGET_BIND_FUNCTION_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationChannelTargetBindFunction class.
		// Arguments:
		// bindClassDescriptor - The class descriptor of the object to bind to.
		PAnimationChannelTargetBindFunction::PAnimationChannelTargetBindFunction(const PClassDescriptor &bindClassDescriptor)
			: m_bindClassDescriptor(bindClassDescriptor)
		{
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_BIND_FUNCTION_INL
