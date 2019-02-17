/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_NETWORK_PREPROCESS_DATA_INL
#define PHYRE_ANIMATION_NETWORK_PREPROCESS_DATA_INL

namespace Phyre
{
	namespace PSpu
	{
		typedef void *PAddr;
	} //! End of PSpu namespace

	namespace PAnimation
	{

		// Description:
		// Initializes the PAnimationNetworkPreprocessData object.
		// Arguments:
		// fetchCount - The number of data pre-fetches.
		void PAnimationNetworkPreprocessData::initialize(PUInt32 fetchCount)
		{
			// Round fetch count up to multiple of 2 for purposes of allocation.
			PUInt32 fetchCountAllocated = (fetchCount + 1) & ~1;

			// Initialize descriptor.
			PUInt32 dataOffset = sizeof(PAnimationNetworkPreprocessData) +
									  sizeof(PAnimationNetworkProcessDataFetch) * (fetchCountAllocated-1);
			m_dataOffset = (dataOffset+15) & ~15;

			m_fetchCount = fetchCount;
			m_fetchLsAddress = 0;
			m_pad = 0;

			// Blank the last fetch in case we didn't need it.
			if(fetchCount & 0x1)
			{
				m_fetches[fetchCountAllocated-1].m_size = 0;
				m_fetches[fetchCountAllocated-1].m_eaAddress = 0;
			}
		}

		// Description:
		// Gets the pointer to the pre-process data.
		// Returns:
		// A pointer to the pre-process data.
		void *PAnimationNetworkPreprocessData::getPreprocessData()
		{
			return (PUInt8 *)this + m_dataOffset;
		}

		// Description:
		// Gets the pointer to the pre-process data.
		// Returns:
		// A pointer to the pre-process data.
		const void *PAnimationNetworkPreprocessData::getPreprocessData() const
		{
			return (const PUInt8 *)this + m_dataOffset;
		}

		// Description:
		// Calculates the size for a specified list of fetches.
		// Arguments:
		// fetchCount - The number of data fetches to store.
		// dataSize   - The size of the data.
		// Returns:
		// The size of the data structure for the specified number of fetches.
		PUInt32 PAnimationNetworkPreprocessData::Size(PUInt32 fetchCount, PUInt32 dataSize)
		{
			// Round fetch count up to multiple of 2 for purposes of allocation.
			PUInt32 fetchCountAllocated = (fetchCount + 1) & ~1;

			// Round data up to next 16 byte boundary.
			dataSize = (dataSize + 15) & ~15;

			PUInt32 size = sizeof(PAnimationNetworkPreprocessData) + sizeof(PAnimationNetworkProcessDataFetch) * (fetchCountAllocated-1);
			size = (size + 15) & ~15;		// Align data
			return size + dataSize;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_NETWORK_PREPROCESS_DATA_INL
