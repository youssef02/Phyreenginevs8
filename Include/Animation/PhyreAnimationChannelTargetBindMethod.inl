/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_BIND_METHOD_INL
#define PHYRE_ANIMATION_CHANNEL_TARGET_BIND_METHOD_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationChannelTargetBindMethod class for binding to an application specified target.
		// Arguments:
		// bindClassDescriptor - The class descriptor of the object to bind to.
		// bindTarget - The object to bind to.
		PAnimationChannelTargetBindMethod::PAnimationChannelTargetBindMethod(const PClassDescriptor &bindClassDescriptor, PBase &bindTarget)
			: m_bindClassDescriptor(bindClassDescriptor)
			, m_bindTarget(&bindTarget)
		{
		}

		// Description:
		// The constructor for the PAnimationChannelTargetBindMethod class for binding to an animation specific target.
		// Arguments:
		// bindClassDescriptor - The class descriptor of the object to bind to.
		PAnimationChannelTargetBindMethod::PAnimationChannelTargetBindMethod(const PClassDescriptor &bindClassDescriptor)
			: m_bindClassDescriptor(bindClassDescriptor)
			, m_bindTarget(NULL)
		{
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_BIND_METHOD_INL
