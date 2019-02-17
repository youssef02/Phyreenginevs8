/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_BIND_DATA_MEMBER_INL
#define PHYRE_ANIMATION_CHANNEL_TARGET_BIND_DATA_MEMBER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// A constructor for the PAnimationChannelTargetBindDataMember class for binding to a specific object.
		// Arguments:
		// bindClassDescriptor - The class descriptor of the object to bind to.
		// bindTarget - The object to bind to.
		PAnimationChannelTargetBindDataMember::PAnimationChannelTargetBindDataMember(const PClassDescriptor &bindClassDescriptor, PBase &bindTarget)
			: m_bindClassDescriptor(bindClassDescriptor)
			, m_bindTarget(&bindTarget)
		{
		}

		// Description:
		// A constructor for the PAnimationChannelTargetBindDataMember class that binds targeted animation channels using the channel target object.
		// Arguments:
		// bindClassDescriptor - The class descriptor of the object to bind to.
		PAnimationChannelTargetBindDataMember::PAnimationChannelTargetBindDataMember(const PClassDescriptor &bindClassDescriptor)
			: m_bindClassDescriptor(bindClassDescriptor)
			, m_bindTarget(NULL)
		{
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_BIND_DATA_MEMBER_INL
