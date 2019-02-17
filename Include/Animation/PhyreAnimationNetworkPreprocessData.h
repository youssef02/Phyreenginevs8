/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_NETWORK_PREPROCESS_DATA_H
#define PHYRE_ANIMATION_NETWORK_PREPROCESS_DATA_H

namespace Phyre
{
	namespace PSpu
	{
		typedef void *PAddr;
	} //! End of PSpu namespace

	namespace PAnimation
	{

		// Description:
		// Represents a required data transfer for a process node of an animation network. Data fetches will be prefetched by the network's process function.
		class PAnimationNetworkProcessDataFetch
		{
		public:
			PUInt32						m_size;			// The size of the transfer (multiple of 16 bytes).
			PSpu::PAddr					m_eaAddress;	// The main memory address of the data (16 byte aligned).
		} __attribute__((aligned(8)));

		// Description:
		// Represents a list of pre-fetch data transfers for an animation network process node.
		class PAnimationNetworkPreprocessData
		{
		public:
			PUInt32								m_dataOffset;		// Offset to the pre-process data.
			PUInt32								m_fetchCount;		// The number of data transfers.
#ifdef __SPU__
			PSpu::LSAddress						m_fetchLsAddress;	// LS address at which fetches are placed.
#else //! __SPU__
			PUInt32								m_fetchLsAddress;	// LS address at which fetches are placed.
#endif //! __SPU__
			PUInt32								m_pad;				// Padding to align fetch list;
			PAnimationNetworkProcessDataFetch	m_fetches[1];		// Variable size array of transfers.

			inline void initialize(PUInt32 fetchCount);

			inline void *getPreprocessData();
			inline const void *getPreprocessData() const;
			inline static PUInt32 Size(PUInt32 fetchCount, PUInt32 dataSize);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_NETWORK_PREPROCESS_DATA_H
