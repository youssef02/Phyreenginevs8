/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CLIP_BINDING_H
#define PHYRE_ANIMATION_CLIP_BINDING_H

namespace Phyre
{
	namespace PAnimation
	{

		//! Forward declarations.
		class PAnimationSet;
		class PAnimationClip;

		//! Note: Vary alignment based on pointer size

#ifdef PHYRE_64BIT_PTR
		PHYRE_STRUCT_PREALIGN(8)
#else //! PHYRE_64BIT_PTR
		PHYRE_STRUCT_PREALIGN(4)
#endif //! PHYRE_64BIT_PTR
		// Description:
		// The PAnimationClipBinding class is a cache of information for an animation against an animation set. This holds the target slot array entry for each
		// animation channel.
		class PAnimationClipBinding : public PBase
		{
#ifndef __SPU__

		private:
			// Description:
			// A private new() operator to avoid allocation.
			// Arguments:
			// size :  The size to allocate.
			// Returns:
			// A pointer to the allocated memory, or NULL on failure.
			void *operator new(size_t size);

			// Description:
			// Private delete() operator to avoid allocation.
			// Arguments:
			// ptr :  A pointer to the object to delete.
			void operator delete(void *ptr);

			//! Following the channel map is a list of run lengths for grouped channels of the same type, terminated with a zero.

#endif //! __SPU__

			PHYRE_BIND_DECLARE_CLASS_HEADER(PAnimationClipBinding, PBase);

		public:
			// Description:
			// A mapping from animation channels to slot array indices. This allows an animation to inject slots into a slot array.
			// This mapping is also sorted to gather same-keytype channels to permit batch processing.
			class PAnimationClipBindingChannelMap : public PBase
			{
				PHYRE_BIND_DECLARE_CLASS(PAnimationClipBindingChannelMap, PBase);
			public:
				PInt16 m_destSlotArrayIndex;						// The index of the destination slot array index in the slot array.
				PUInt16 m_interp;									// The interpolation method for the channel. For constant channels this defines the behavior. 
			};

			// Description:
			// Accelerates PAnimationController::preprocess() by making a cache of the channel value and time pointers.
			class PAnimationClipBindingDataBlockCache : public PBase
			{
				PHYRE_BIND_DECLARE_CLASS(PAnimationClipBindingDataBlockCache, PBase);
			public:
				const float *m_times;											// A pointer to the array of times for this channel.
				const float *m_values;											// A pointer to the array of values for this channel.
				PUInt32 m_valueWidthAndKeyCount;								// An unsigned integer that stores two values. The number of floats in each value key is stored in the top byte and the number of value keys is stored in
																				// the lower 3 bytes.
				PUInt16 m_sourceChannelIndex;									// The index of the source channel in the animation.

				inline PUInt32 getValueWidth() const;
				inline PUInt32 getKeyCount() const;
			};

			PUInt16						m_spuBindingSize;						// The size of the binding structure to upload to the SPU.
			PUInt16						m_channelCount;							// The number of channels cached here.
			PUInt16						m_constantChannelCount;					// The number of constant values cached here.
			PUInt16						m_interpCountLength;					// The number of interpolation counts.

			//! Followed by...:
			//! PUInt16						m_interpCounts[m_interpCountLength];						// The number of each kind of interpolation method. The run length list describing how many channels of a single type are grouped together.
			//! PAnimationClipBindingChannelMap	m_channelSlotArrayIndex[channelCount];					// The slot array indices and interpolation methods for channels.
			//! PAnimationClipBindingChannelMap	m_constantChannelSlotArrayIndex[constantChannelCount];	// The slot array indices and interpolation methods for constant channels.
			//! PAnimationClipBindingDataBlockCache	m_dataBlockCache[channelCount];						// The data block cache for channels.

#ifndef __SPU__

			static inline size_t AdditionalAlloc(const PAnimationClip &animClip);

			PAnimationClipBinding();
			PResult initialize(const PAnimationSet &animSet, const PAnimationClip &anim);

			PResult rebuild(const PAnimationClip &anim);
#endif //! __SPU__

			inline const PUInt16 *getInterpCounts() const;
			inline PUInt16 *getInterpCounts();

			inline const PAnimationClipBindingChannelMap *getChannelMap() const;
			inline const PAnimationClipBindingChannelMap *getConstantChannelMap() const;
			inline PAnimationClipBindingChannelMap *getChannelMap();
			inline PAnimationClipBindingChannelMap *getConstantChannelMap();

#ifndef __SPU__
			//! Native alignment methods.
			inline const PAnimationClipBinding::PAnimationClipBindingDataBlockCache *getDataBlockCache() const;
			inline PAnimationClipBinding::PAnimationClipBindingDataBlockCache *getDataBlockCache();

			//! Export alignment methods.
			inline const PAnimationClipBinding::PAnimationClipBindingDataBlockCache *getDataBlockCache(const PClassLayoutInterface &layoutInterface) const;
			inline PAnimationClipBinding::PAnimationClipBindingDataBlockCache *getDataBlockCache(const PClassLayoutInterface &layoutInterface);
#endif //! __SPU__

		}
#ifdef PHYRE_64BIT_PTR
		PHYRE_STRUCT_POSTALIGN(8);
#else //! PHYRE_64BIT_PTR
		PHYRE_STRUCT_POSTALIGN(4);
#endif //! PHYRE_64BIT_PTR

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CLIP_BINDING_H
