/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_TIME_CONTROLLER_INL
#define PHYRE_TIME_CONTROLLER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Gets s_globalTime.
		float PTimeController::GetGlobalTime()
		{
			return s_globalTime;
		}

		// Description:
		// Resets global time to zero.
		void PTimeController::ResetGlobalTime()
		{
			s_globalTime = 0.0f;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_TIME_CONTROLLER_INL
