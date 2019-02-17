/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_AUDIO_INTERFACE_FMOD_H
#define PHYRE_AUDIO_INTERFACE_FMOD_H

namespace FMOD
{
	//! Forward declarations
	class EventSystem;
	class Event;
} //! End of FMOD namespace

namespace Phyre
{
	namespace PAudio
	{
		// Description:
		// An audio interface implementation that wraps core FMOD functionality.
		class PAudioInterfaceFMOD : public PAudioInterfaceBase
		{
		public:
			PAudioInterfaceFMOD();
			~PAudioInterfaceFMOD();

			//! System management
			static PResult Initialize();
			PResult initialize(const MemCallbacks &cb, const PChar *mediaDirectory);
			PResult terminate();

			//! Listener
			PResult setListener3DAttributes(const Vectormath::Aos::Vector3 *position,
				const Vectormath::Aos::Vector3 *velocity = NULL,
				const Vectormath::Aos::Vector3 *forward = NULL,
				const Vectormath::Aos::Vector3 *up = NULL);
			
			//! Reverb management
			PResult setAmbientReverb(const PChar *reverbName = NULL);
			PResult setAmbientReverb(PInt32 reverbIndex);

			//! Update
			PResult update();

			//! Media directory
			const PString &getMediaDirectory() const;

			//! Custom FMOD functions
			FMOD::EventSystem	*getFMODEventSystem();

		private:
			//! Internal helpers
			PResult mainInit();

		private:
			FMOD::EventSystem		*m_eventSystem;				// A pointer to the FMOD event system.
			PString					m_mediaDirectory;			// The media directory.
			
		public:
			static MemCallbacks		s_cb;						// Used for wrapping user callbacks to abstract the interface.
		};
	} //! End of PAudio namespace
} //! End of Phyre namespace

#endif //! PHYRE_AUDIO_INTERFACE_FMOD_H
