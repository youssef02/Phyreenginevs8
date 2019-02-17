/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_BIND_DATA_MEMBER_H
#define PHYRE_ANIMATION_CHANNEL_TARGET_BIND_DATA_MEMBER_H

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The class for binding the animation channel targets to named data members.
		class PAnimationChannelTargetBindDataMember : public PAnimationChannelTargetBind
		{
			PHYRE_PRIVATE_ASSIGNMENT_OPERATOR(PAnimationChannelTargetBindDataMember);

		protected:
			const PClassDescriptor &m_bindClassDescriptor;			// The class descriptor for the bind target.
			PBase *m_bindTarget;									// The target object to bind to. Set to NULL to use the channel specific target.

		public:
			inline PAnimationChannelTargetBindDataMember(const PClassDescriptor &bindClassDescriptor, PBase &bindTarget);
			inline PAnimationChannelTargetBindDataMember(const PClassDescriptor &bindClassDescriptor);

			virtual PResult bindTargets(PAnimationNetworkInstanceTarget *instanceTargets, const PAnimationChannelTarget *targets, PUInt32 targetCount);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_BIND_DATA_MEMBER_H
