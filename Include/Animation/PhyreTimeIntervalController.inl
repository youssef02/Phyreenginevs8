/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_TIME_INTERVAL_CONTROLLER_INL
#define PHYRE_TIME_INTERVAL_CONTROLLER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Gets m_parent.
		PTimeController *PTimeIntervalController::getParent() const
		{
			return m_parent;
		}

		// Gets m_localBase.
		float PTimeIntervalController::getLocalBase() const
		{
			return m_localBase;
		}

		// Gets m_localRange.
		float PTimeIntervalController::getLocalRange() const
		{
			return m_localRange;
		}

		// Gets m_parentBase.
		float PTimeIntervalController::getParentBase() const
		{
			return m_parentBase;
		}

		// Sets m_parentBase.
		void PTimeIntervalController::setParentBase(float parentBase)
		{
			m_parentBase = parentBase;
		}

		// Sets m_localBase.
		void PTimeIntervalController::setLocalBase(float localBase)
		{
			m_localBase = localBase;
		}

		// Sets m_localRange.
		void PTimeIntervalController::setLocalRange(float localRange)
		{
			m_localRange = localRange;
		}

		// Sets m_parent.
		void PTimeIntervalController::setParent(PTimeController &parent)
		{
			m_parent = &parent;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_TIME_INTERVAL_CONTROLLER_INL
