/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CONSTANT_CHANNEL_INL
#define PHYRE_ANIMATION_CONSTANT_CHANNEL_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationConstantChannel class.
		PAnimationConstantChannel::PAnimationConstantChannel()
		{
			m_value[0] = m_value[1] = m_value[2] = m_value[3] = 0.0f;
		}

		// Description:
		// Gets the value for this constant channel.
		// Returns:
		// A pointer to the constant value for this constant channel.
		const float *PAnimationConstantChannel::getValue() const
		{
			return m_value;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CONSTANT_CHANNEL_INL
