/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_EVENT_LIST_INL
#define PHYRE_ANIMATION_EVENT_LIST_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Gets the number of events in this event list.
		// Returns:
		// Number of events in this event list.
		PUInt32 PAnimationEventList::getEventCount() const
		{
			return m_events.getCount();
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_EVENT_LIST_INL
