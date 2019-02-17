/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SLOT_ARRAY_H
#define PHYRE_ANIMATION_SLOT_ARRAY_H

namespace Phyre
{
	namespace PAnimation
	{

		//! Forward declarations.
		class PAnimationKeyDataType;

		// Description:
		// The PAnimationInterpolationType enum identifies the different interpolation methods to employ.
		enum PAnimationInterpolationType
		{
			PE_ANIMINTERP_LERP,								// Linear interpolation should be used.
			PE_ANIMINTERP_SLERP,							// Spherical linear interpolation should be used.
			PE_ANIMINTERP_STEP,								// No interpolation should be used - the animation should be stepped/sampled.
			PE_ANIMINTERP_COUNT								// The number of animation interpolation types.
		};

		// Description:
		// Index into animation set slot list with key type.  Used in key arrays to identify the target of animation data.
		class PAnimationSlotListIndex : public PBase
		{
			PHYRE_BIND_DECLARE_CLASS(PAnimationSlotListIndex, PBase);

		public:
			const PAnimationKeyDataType	*m_animKeyType;			// Type of animation key.
			PAnimationInterpolationType m_interp;				// The interpolation type.
			PUInt32 m_targetIndex;								// Animation set slot list index.
			PUInt32 m_nodeCentricReIndex;						// When the slot list index array is viewed as a node-centric sorted list, this element re-indices the array to gather same-node slots together.
																// The node centric re-index member does not have a direct associated with the other members in this class.

			inline void init(const PAnimationKeyDataType *animKeyType, PAnimationInterpolationType interp, PUInt32 targetIndex);

#ifndef __SPU__

			inline PAnimationSlotListIndex();
			inline PUInt32 hash() const;
			inline bool operator < (const PAnimationSlotListIndex &other) const;
			inline bool operator > (const PAnimationSlotListIndex &other) const;
			inline bool operator == (const PAnimationSlotListIndex &other) const;

			static PInt32 SortCallback(const void *a, const void *b);
#endif //! __SPU__
		};

		// Description:
		// Slot array elements contain animation results targeted at a single slot and a reference to the final target in the object (by an index through the
		// animation network target node list).
		class PAnimationSlotArrayElement
		{
		protected:

#ifdef __SPU__
			typedef vec_float4 PValueType;			// The slot array element value type for SPU builds.
#else //! __SPU__
			typedef Vectormath::Aos::Vector4 PValueType;			// The slot array element value type for SPU builds.
#endif //! __SPU__

			PValueType m_value;							// The value for the slot array element.

			PAnimationSlotListIndex m_slotListIndex;	// Slot list index this is destined for.

		public:
			inline const PAnimationSlotArrayElement &operator = (const PAnimationSlotArrayElement &other);

			inline const PValueType &getValue() const;
			inline PValueType &getValue();
			inline const PAnimationSlotListIndex &getSlotListIndex() const;

			inline void setTargetSlotIndex(const PAnimationKeyDataType *keyType, PAnimationInterpolationType interp, PUInt32 targetIndex);
			inline void setTargetSlotIndex(const PAnimationSlotListIndex &slotListIndex);
			inline void setValue(const PValueType &value);
		};

		// Description:
		// Contains the intermediate animation network results before they are grabbed by the target blender and put into the target nodes. The slot array does
		// not own the array elements. They belong to the animation network instance. This is simply a convenient way of storing their location and size.
		class PAnimationSlotArray : public PBase
		{
			PHYRE_BIND_DECLARE_CLASS(PAnimationSlotArray, PBase);
		protected:
			PAnimationSlotArrayElement *m_slots;						// A pointer to the slot array elements which contain the processed key data.

		public:
			inline void setSlotAddr(PAnimationSlotArrayElement *slots);
			inline PAnimationSlotArrayElement *getSlots() const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SLOT_ARRAY_H
