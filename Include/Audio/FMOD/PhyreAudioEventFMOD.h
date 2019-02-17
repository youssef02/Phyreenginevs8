/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_AUDIO_EVENT_FMOD_H
#define PHYRE_AUDIO_EVENT_FMOD_H

#include <Audio/PhyreAudioInterface.h>

namespace FMOD
{
	//! Forward declarations
	class EventSystem;
	class Event;
	class EventProject;
	class Sound;
} //! End of FMOD namespace

namespace Phyre
{
	namespace PAudio
	{
		//! Forward declarations
		class PAudioBank;

		// Description:
		// An audio event implementation that wraps core FMOD functionality.
		class PAudioEventFMOD
		{
			friend class PAudioBankFMOD;

		public:
			PAudioEventFMOD();
			~PAudioEventFMOD();
		
			PResult release();

			//! Transport control
			PResult play();
			PResult stop();
			PResult kill();
			PResult pause();
			PResult resume();
			
			//! Event attributes
			PResult setVolume(float volume);
			PResult set3DAttributes(const Vectormath::Aos::Vector3 *position, const Vectormath::Aos::Vector3 *velocity = NULL, const Vectormath::Aos::Vector3 *direction = NULL);

			//! FMOD specific
			FMOD::Event *getFMODEvent() const;

		private:
			static FMOD::EventSystem *GetFMODEventSystem();
			PResult setFMODEvent(FMOD::Event *fmodEvent);

		private:
			FMOD::Event *m_event;			// A pointer to the FMOD event which this class wraps.
		};
	} //! End of PAudio namespace
} //! End of Phyre namespace

#endif //! PHYRE_AUDIO_EVENT_FMOD_H
