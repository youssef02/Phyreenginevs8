/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_INL
#define PHYRE_ANIMATION_CHANNEL_TARGET_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationChannelTarget class.
		PAnimationChannelTarget::PAnimationChannelTarget()
			: m_instanceObjectType(PBase::GetClassDescriptor())
			, m_instanceObject(NULL)
			, m_baseObjectType(NULL)
			, m_baseObject(NULL)
			, m_type(PE_TARGETTYPE_NONE)
			, m_index(0)
		{
		}

		// Description:
		// The destructor for the PAnimationChannelTarget class.
		PAnimationChannelTarget::~PAnimationChannelTarget()
		{
		}

		// Description:
		// Gets m_type.
		PAnimationChannelTarget::PTargetType PAnimationChannelTarget::getTargetType() const
		{
			return m_type;
		}

		// Description:
		// Gets m_instanceObjectType.
		const PClassDescriptor &PAnimationChannelTarget::getTargetObjectType() const
		{
			return m_instanceObjectType;
		}

		// Description:
		// Gets m_instanceObject.
		PBase *PAnimationChannelTarget::getTargetObject() const
		{
			return m_instanceObject;
		}

		// Description:
		// Gets m_baseObjectType.
		const PClassDescriptor *PAnimationChannelTarget::getTargetBaseObjectType() const
		{
			return m_baseObjectType;
		}

		// Description:
		// Gets m_baseObject.
		const PBase *PAnimationChannelTarget::getTargetBaseObject() const
		{
			return m_baseObject;
		}

		// Description:
		// Gets the target name for the animation channel target.
		// Returns:
		// The target name.
		const PChar *PAnimationChannelTarget::getTargetName() const
		{
			return m_name.c_str();
		}

		// Gets m_index.
		PUInt32 PAnimationChannelTarget::getTargetIndex() const
		{
			return m_index;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_INL
