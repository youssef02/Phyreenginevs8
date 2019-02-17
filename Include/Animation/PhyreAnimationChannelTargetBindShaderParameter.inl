/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SHADER_PARAMETER_INL
#define PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SHADER_PARAMETER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationChannelTargetBindShaderParameter class to bind to the runtime specified material.
		// Arguments:
		// bindTarget - The parameter buffer to bind to.
		PAnimationChannelTargetBindShaderParameter::PAnimationChannelTargetBindShaderParameter(PRendering::PParameterBuffer &bindTarget)
			: m_bindTarget(&bindTarget)
		{
		}

		// Description:
		// The constructor for the PAnimationChannelTargetBindShaderParameter class to bind to the animation specified material.
		PAnimationChannelTargetBindShaderParameter::PAnimationChannelTargetBindShaderParameter()
			: m_bindTarget(NULL)
		{
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SHADER_PARAMETER_INL
