/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_BASE_INL
#define PHYRE_ANIMATION_CHANNEL_BASE_INL

namespace Phyre
{
	namespace PAnimation
	{
		// Sets m_keyType.
		void PAnimationChannelBase::setKeyType(const PAnimationKeyDataType *keyType)
		{
			m_keyType = keyType;
		}

		// Sets m_interp.
		void PAnimationChannelBase::setInterpolation(PAnimationInterpolationType interp)
		{
			m_interp = interp;
		}

		// Gets m_keyType.
		const PAnimationKeyDataType *PAnimationChannelBase::getKeyType() const
		{
			return m_keyType;
		}

		// Gets m_interp.
		PAnimationInterpolationType PAnimationChannelBase::getInterpolation() const
		{
			return m_interp;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_BASE_INL
