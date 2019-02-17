/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CONTROLLER_INL
#define PHYRE_ANIMATION_CONTROLLER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Gets m_animationClip.
		PAnimationClip *PAnimationController::getAnimationClip() const
		{
			return m_animationClip;
		}

		// Gets m_timeController.
		PTimeController *PAnimationController::getTimeController() const
		{
			return m_timeController;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CONTROLLER_INL
