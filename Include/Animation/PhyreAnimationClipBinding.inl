/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CLIP_BINDING_INL
#define PHYRE_ANIMATION_CLIP_BINDING_INL

namespace Phyre
{
	namespace PAnimation
	{

#ifndef __SPU__

		// Description:
		// Determines the required size of the binding structure.
		// Arguments:
		// animClip - The animation clip to size the additional allocation for.
		// Returns:
		// The size in bytes of the required structure.
		size_t PAnimationClipBinding::AdditionalAlloc(const PAnimationClip &animClip)
		{
			PUInt32 channelCount				= animClip.getAnimationChannelCount();
			PUInt32 constantChannelCount		= animClip.getAnimationConstantChannelCount();
			PUInt32 keyTypeInterpolationCount	= animClip.countInterpolationKeyTypes();

			size_t size = 0;
			size += sizeof(PUInt16) * PhyreAlign<4>(keyTypeInterpolationCount);						// The interpolation counts.
			size += sizeof(PAnimationClipBindingChannelMap) * (channelCount+constantChannelCount);	// Channel mappings.
			size = PhyreAlign<PHYRE_ALIGN_OF(PAnimationClipBindingDataBlockCache)>((PUInt32)size);	// Align for platform.
			size += sizeof(PAnimationClipBindingDataBlockCache) * channelCount;						// Cached animation data blocks.
			size = PhyreAlign<16>((PUInt32)size);

			return size;
		}

#endif //! __SPU__

		// Description:
		// Gets the number of floats in each value key.
		// Returns:
		// The number of floats in each value key.
		PUInt32 PAnimationClipBinding::PAnimationClipBindingDataBlockCache::getValueWidth() const
		{
			return m_valueWidthAndKeyCount >> 24;
		}

		// Description:
		// Gets the number of keys.
		// Returns:
		// The number of keys.
		PUInt32 PAnimationClipBinding::PAnimationClipBindingDataBlockCache::getKeyCount() const
		{
			return m_valueWidthAndKeyCount & 0x00FFFFFF;
		}

		// Gets m_interpCounts.
		const PUInt16 *PAnimationClipBinding::getInterpCounts() const
		{
			return (const PUInt16 *)(this+1);
		}

		// Gets m_interpCounts.
		PUInt16 *PAnimationClipBinding::getInterpCounts()
		{
			return (PUInt16 *)(this+1);
		}

		// Description:
		// An accessor for the mapping from animation channels to slot array indices.
		// These describe the target slot array entry for each animation channel,
		// and also group animation channels by type for efficient processing.
		// Returns:
		// A pointer to an array of channel map structures.
		const PAnimationClipBinding::PAnimationClipBindingChannelMap *PAnimationClipBinding::getChannelMap() const
		{
			PUInt32 roundedUpInterpCountLength = (m_interpCountLength + 3) & ~3;
			return reinterpret_cast<const PAnimationClipBindingChannelMap *>(getInterpCounts() + roundedUpInterpCountLength);
		}

		// Description:
		// An accessor for the mapping from constant animation channels to slot array indices,
		// which describe the target slot array entry for each constant animation channel.
		// They also group animation channels by type for efficient processing.
		// Returns:
		// A pointer to an array of channel map structures.
		const PAnimationClipBinding::PAnimationClipBindingChannelMap *PAnimationClipBinding::getConstantChannelMap() const
		{
			return getChannelMap() + m_channelCount;
		}

		// Description:
		// An accessor for the mapping from animation channels to slot array indices, 
		// which describe the target slot array entry for each animation channel.
		// They also group animation channels by type for efficient processing.
		// Returns:
		// A pointer to an array of channel map structures.
		PAnimationClipBinding::PAnimationClipBindingChannelMap *PAnimationClipBinding::getChannelMap()
		{
			PUInt32 roundedUpInterpCountLength = (m_interpCountLength + 3) & ~3;
			return reinterpret_cast<PAnimationClipBindingChannelMap *>(getInterpCounts() + roundedUpInterpCountLength);
		}

		// Description:
		// An accessor for the mapping from constant animation channels to slot array indices,
		// which describe the target slot array entry for each constant animation channel.
		// They also group animation channels by type for efficient processing.
		// Returns:
		// A pointer to an array of channel map structures.
		PAnimationClipBinding::PAnimationClipBindingChannelMap *PAnimationClipBinding::getConstantChannelMap()
		{
			return getChannelMap() + m_channelCount;
		}

#ifndef __SPU__
		// Description:
		// An accessor for the data block cache.
		// Returns:
		// A const reference to the data block cache.
		const PAnimationClipBinding::PAnimationClipBindingDataBlockCache *PAnimationClipBinding::getDataBlockCache() const
		{
			return reinterpret_cast<const PAnimationClipBindingDataBlockCache *>(PhyreAlign<PHYRE_ALIGN_OF(PAnimationClipBindingDataBlockCache)>((void *)(getChannelMap() + m_channelCount + m_constantChannelCount)));
		}

		// Description:
		// An accessor for the data block cache.
		// Returns:
		// A pointer to the data block cache.
		PAnimationClipBinding::PAnimationClipBindingDataBlockCache *PAnimationClipBinding::getDataBlockCache()
		{
			return reinterpret_cast<PAnimationClipBindingDataBlockCache *>(PhyreAlign<PHYRE_ALIGN_OF(PAnimationClipBindingDataBlockCache)>((void *)(getChannelMap() + m_channelCount + m_constantChannelCount)));
		}

		// Description:
		// An accessor for the data block cache.
		// Arguments:
		// layoutInterface - The class layout interface that defines the alignment requirement for the PAnimationClipBindingDataBlockCache class.
		// Returns:
		// A pointer to the data block cache.
		const PAnimationClipBinding::PAnimationClipBindingDataBlockCache *PAnimationClipBinding::getDataBlockCache(const PClassLayoutInterface &layoutInterface) const
		{
			PUInt32 targetAlignment = layoutInterface.getClassAlignment(PHYRE_CLASS(PAnimationClipBindingDataBlockCache));
			const void *ptr = getChannelMap() + m_channelCount + m_constantChannelCount;
			PUInt32 locallyAlignedOffset = PhyreGetPointerOffsetInBytes32(this, ptr);
			return reinterpret_cast<const PAnimationClipBindingDataBlockCache *>(PhyreOffsetPointerByBytes(this, PhyreAlign(locallyAlignedOffset, targetAlignment)));
		}

		// Description:
		// An accessor for the data block cache.
		// Arguments:
		// layoutInterface - The class layout interface that defines the alignment requirement for the PAnimationClipBindingDataBlockCache class.
		// Returns:
		// A pointer to the data block cache.
		PAnimationClipBinding::PAnimationClipBindingDataBlockCache *PAnimationClipBinding::getDataBlockCache(const PClassLayoutInterface &layoutInterface)
		{
			PUInt32 targetAlignment = layoutInterface.getClassAlignment(PHYRE_CLASS(PAnimationClipBindingDataBlockCache));
			void *ptr = getChannelMap() + m_channelCount + m_constantChannelCount;
			PUInt32 locallyAlignedOffset = PhyreGetPointerOffsetInBytes32(this, ptr);
			return reinterpret_cast<PAnimationClipBindingDataBlockCache *>(PhyreOffsetPointerByBytes(this, PhyreAlign(locallyAlignedOffset, targetAlignment)));
		}

#endif //! __SPU__

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CLIP_BINDING_INL
