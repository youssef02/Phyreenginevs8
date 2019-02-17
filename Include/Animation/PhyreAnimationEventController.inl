/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_EVENT_CONTROLLER_INL
#define PHYRE_ANIMATION_EVENT_CONTROLLER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Gets m_animationEventList.
		PAnimationEventList *PAnimationEventController::getAnimationEventList() const
		{
			return m_animationEventList;
		}

		// Gets m_timeController.
		PTimeController *PAnimationEventController::getTimeController() const
		{
			return m_timeController;
		}

		// Sets m_animationEventList.
		void PAnimationEventController::setAnimationEventList(PAnimationEventList &animationEventList)
		{
			m_animationEventList = &animationEventList;
		}

		// Sets m_timeController.
		void PAnimationEventController::setTimeController(PTimeController &timeController)
		{
			m_timeController = &timeController;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_EVENT_CONTROLLER_INL
