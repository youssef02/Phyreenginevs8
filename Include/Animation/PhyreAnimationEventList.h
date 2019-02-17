/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_EVENT_LIST_H
#define PHYRE_ANIMATION_EVENT_LIST_H

namespace Phyre
{
	namespace PAnimation
	{
		// Description:
		// Holds the state for an event to be notified during the playback of an animation. Events are processed by a PAnimationEventController during the
		// processing of the animation network instance.
		class PAnimationEvent : public PBase
		{
			PHYRE_BIND_DECLARE_CLASS(PAnimationEvent, PBase);

		public:
			float m_time;								// The time of the event
			PUInt32 m_id;								// The event ID to pass to the event callback.

			static PInt32 SortCallback(const void *a, const void *b);
		};

		// Description:
		// Holds a group of events pertaining to a single animation. As the animation is played, the PAnimationEventController sends events to the PAnimationEventController::eventCallback().
		class PAnimationEventList : public PBase
		{
		protected:
			PArray<PAnimationEvent> m_events;						// The list of events for the animation.

			// Description:
			// Function type definition for a callback for an animation event.
			// Arguments:
			// event :     Event currently being processed.
			// userData :  User data passed to the PAnimationEventList::forAllEvents() method.
			typedef void (*PAnimationEventCallback)(const PAnimationEvent &event, void *userData);

			PHYRE_BIND_DECLARE_CLASS(PAnimationEventList, PBase);

		public:
			PAnimationEventList();
			~PAnimationEventList();

			PResult sort();
			PResult setEventCount(PUInt32 eventCount);
			PResult setEvent(PUInt32 index, const PAnimationEvent &eventToSet);
			const PAnimationEvent *getEvent(PUInt32 index) const;
			PResult addEvent(const PAnimationEvent &eventToAdd);

			PResult forAllEvents(float startTime, float endTime, PAnimationEventCallback eventCallback, void *userData) const;

			inline PUInt32 getEventCount() const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_EVENT_LIST_H
