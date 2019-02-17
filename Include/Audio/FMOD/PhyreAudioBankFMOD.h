/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_AUDIO_BANK_FMOD_H
#define PHYRE_AUDIO_BANK_FMOD_H

// Description:
// The namespace encapsulating the FMOD classes.
namespace FMOD
{
	//! Forward declarations
	class EventSystem;
	class EventProject;
	class Sound;
} //! End of FMOD namespace

namespace Phyre
{
	namespace PAudio
	{
		// Description:
		// An enumeration to identify the type of FMOD bank represented by a class.
		typedef enum FMODFileType
		{
			FMODFileFEV = 0,				// The bank is an FEV file.
			FMODFileFSB,					// The bank is an FSB file.
			FMODFileFSBStream,				// The bank contains reference to an FSB stream bank.
			FMODFileInvalid = 0xFFFFFFFF	// The bank is not valid or initialized.
		} FMODFileType;

		//! Forward declarations
		class PAudioEvent;

		// Description:
		// An audio bank implementation that manages FMOD, FEV and FSB files.
		class PAudioBankFMOD : public PBase
		{
			PHYRE_BIND_DECLARE_CLASS(PAudioBankFMOD, PBase);
		public:		
			///! Construction and destruction
			PAudioBankFMOD();
			~PAudioBankFMOD();

			//! Bank registration
			PResult setData(const PChar *name, PArray<PUInt8> &data, PUInt32 type);
			PResult setStreamData(const PChar *streamPath, const PChar *streamName);
			PResult registerBank();
			PResult unregisterBank();

			void setName(const PChar *name);
			void setStream(const PChar *stream);
			void setType(PUInt32 ftype);
			const PString &getName();
			const PString &getStream();
			PUInt32 getType();

			//! Event management
			PResult createEvent(const PChar *name, PAudio::PAudioEvent &audioEvent);
			PResult createEvent(PInt32 index, PAudio::PAudioEvent &audioEvent);
			PResult killAllEvents();

		private:
			static FMOD::EventSystem *GetFMODEventSystem();

		private:
			PUInt32 m_fileType;				// The file type for this bank.
			PString m_name;					// The name of this bank.
			PString m_streamPath;			// The path name for stream data. This is only used in streaming banks.
			PArray<PUInt8> m_data;			// The bank data.

			union
			{
				FMOD::EventProject *project;	// The FMOD project for FEV banks
				FMOD::Sound *sound;				// The sound pointer for FSB banks.
			} m_bankRef;						// The runtime reference to the bank.
		};

	} //! End of PAudio namespace
} //! End of Phyre namespace

#endif //! PHYRE_AUDIO_BANK_FMOD_H
