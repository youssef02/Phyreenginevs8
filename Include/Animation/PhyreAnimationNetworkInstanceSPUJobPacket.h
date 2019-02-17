/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_NETWORK_INSTANCE_SPU_JOB_PACKET_H
#define PHYRE_ANIMATION_NETWORK_INSTANCE_SPU_JOB_PACKET_H

#ifdef PHYRE_SPU_PROFILE
#include <cell/spurs/trace.h>
#endif //! PHYRE_SPU_PROFILE

namespace Phyre
{
	namespace PSpu
	{
		typedef void *PAddr;
	} //! End of PSpu namespace

	namespace PAnimation
	{

		// Description:
		// Holds the information necessary for the SPU animation driver to fetch, process and return the results of an animation network instance.
		class PAnimationNetworkInstanceSPUJobPacket
		{
		public:
			// Description:
			// The PSPUAnimDataSourceInfo contains information about processing a single animation data source on the SPU.
			class PSPUAnimDataSourceInfo
			{
			public:
				PSpu::PAddr	m_codeEA;						// The effective address of the code in main memory.
				PUInt32		m_codeSize;						// The size of the code in main memory.
				PUInt32		m_codeEntry;					// The offset relative to the code base of the code entry point.

				PUInt32		m_inputSlotArrayCount;			// The number of input slot arrays.
				PUInt32		m_inputSlotArrayIndex[32];		// The indices of the input slot arrays.
				PUInt32		m_outputSlotArrayIndex;			// The index of the output slot array.

				PSpu::PAddr	m_preprocessDataEA;				// The effective address of the preprocess data in main memory.

				// Description:
				// Union of preprocess data size and profile timer value to save space.
				union
				{
					PUInt32		m_preprocessDataSize;		// The size of the preprocess data in main memory passed to the SPU.
					PUInt32		m_profileTimer;				// The profile timer value returning from the SPU.
				} u;										// Union of preprocess data size and profile timer value to save space.

				PUInt32		m_persistentDataOffset;			// Offset of the persistent data within the persistent network state.

#ifdef PHYRE_SPU_PROFILE
	    		CellSpursTracePacket m_spursTraceStart;		// Spurs trace memory for start.
	    		CellSpursTracePacket m_spursTraceStop;		// Spurs trace memory for stop.
#endif //! PHYRE_SPU_PROFILE
			};

			volatile PUInt32		m_slotArrayEntryCount;			// Flag written back by the SPU process to indicate number of slot array entries produced.

			PSpu::PAddr				m_preprocessBlockEA;			// Address of the preprocess ring buffer block for the animation network.

			PSpu::PAddr				m_persistentDataEA;				// The effective address of the persistent network state in main memory.
			PUInt32					m_persistentDataSize;			// The size of the persistent network state in main memory.

			PSpu::PAddr				m_destSlotArrayEA;				// The effective address of the target slot array in main memory.
			PUInt32					m_destSlotArraySize;			// The size of the target slot array in main memory.

			PUInt32					m_slotArraySize;				// The maximum number of entries in any one slot array during network processing.
			PUInt32					m_slotArrayCount;				// The number of slot arrays required during processing.
			PSpu::PAddr				m_slotArrayIndicesEA;			// The effective address of the array of structures describing what each slot array entry is.

			PUInt32					m_animationDataSourceCount;		// The number of animation data sources to process.
			PSPUAnimDataSourceInfo	m_animDataSource[1];			// Variable size array of animation data source information.

			inline static PUInt32 Size(PUInt32 animDataSourceCount);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_NETWORK_INSTANCE_SPU_JOB_PACKET_H
