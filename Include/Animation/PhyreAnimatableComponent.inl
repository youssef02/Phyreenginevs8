/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATABLE_COMPONENT_INL
#define PHYRE_ANIMATABLE_COMPONENT_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Sets the animation set and configures the animation network suitably.
		// Arguments:
		// animationSet - The animation set to set.
		// Return Value List:
		// PE_RESULT_NO_ERROR - The animation set was set successfully.
		// PE_RESULT_INSUFFICIENT_INFORMATION - The animation set has no clips to play.
		// Other - The return value from configureAnimationDataSources().
		PResult PAnimatableComponent::setAnimationSet(PAnimationSet *animationSet)
		{
			PResult result = PE_RESULT_NO_ERROR;

			if (m_animationSet != animationSet)
			{
				if (animationSet->getAnimationClipCount() < 1)
					result = PHYRE_SET_LAST_ERROR(PE_RESULT_INSUFFICIENT_INFORMATION, "Animation set has no clips");
				else
				{
					m_animationSet = animationSet;
					m_animationClip = NULL;
					result = configureAnimationDataSources();
				}
			}

			return result;
		}

		// Description:
		// Sets the animation clip and stops the animation.
		// Arguments:
		// animationClip - The animation clip to set.
		// Return Value List:
		// PE_RESULT_NO_ERROR - The animation clip was set successfully.
		PResult PAnimatableComponent::setAnimationClip(PAnimationClip *animationClip)
		{
			PResult result = PE_RESULT_NO_ERROR;

			m_animationClip = animationClip;

			return result;
		}

		// Gets m_animationSet.
		PAnimationSet *PAnimatableComponent::getAnimationSet() const
		{
			return m_animationSet;
		}

		// Gets m_animationClip.
		PAnimationClip *PAnimatableComponent::getAnimationClip() const
		{
			return m_animationClip;
		}

		// Gets m_speed.
		float PAnimatableComponent::getSpeed() const
		{
			return m_speed;
		}

		// Gets m_animationNetworkInstance.
		PAnimationNetworkInstance &PAnimatableComponent::getAnimationNetworkInstance()
		{
			return m_animationNetworkInstance;
		}

		// Gets m_animationNetworkInstance.
		const PAnimationNetworkInstance &PAnimatableComponent::getAnimationNetworkInstance() const
		{
			return m_animationNetworkInstance;
		}

	} //! End of PAnimation namespace.

} //! End of Phyre namespace.

#endif //! PHYRE_ANIMATABLE_COMPONENT_INL
