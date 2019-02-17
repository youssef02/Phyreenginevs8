/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SHADER_PARAMETER_H
#define PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SHADER_PARAMETER_H

namespace Phyre
{
	namespace PRendering
	{
		class PParameterBuffer;
	} //! End of PRendering namespace

	namespace PAnimation
	{

		// Description:
		// The class for binding the animation channel targets to named shader parameters in a parameter buffer.
		class PAnimationChannelTargetBindShaderParameter : public PAnimationChannelTargetBind
		{
			PHYRE_PRIVATE_ASSIGNMENT_OPERATOR(PAnimationChannelTargetBindShaderParameter);

		protected:
			PRendering::PParameterBuffer *m_bindTarget;			// The target parameter buffer to bind to.

		public:
			inline PAnimationChannelTargetBindShaderParameter(PRendering::PParameterBuffer &bindTarget);
			inline PAnimationChannelTargetBindShaderParameter();

			virtual PResult bindTargets(PAnimationNetworkInstanceTarget *instanceTargets, const PAnimationChannelTarget *targets, PUInt32 targetCount);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SHADER_PARAMETER_H
