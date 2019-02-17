/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SLOT_ARRAY_INL
#define PHYRE_ANIMATION_SLOT_ARRAY_INL

namespace Phyre
{
	namespace PAnimation
	{

		//!
		//! PAnimationSlotListIndex implementation.
		//!

		// Description:
		// Initializes the PAnimationSlotListIndex class.
		// Arguments:
		// animKeyType :	Type of animation key.
		// interp :			The interpolation method to use for this slot array element.
		// targetIndex :	Animation set slot list index.
		void PAnimationSlotListIndex::init(const PAnimationKeyDataType *animKeyType, PAnimationInterpolationType interp, PUInt32 targetIndex)
		{
			m_animKeyType = animKeyType;
			m_interp = interp;
			m_targetIndex = targetIndex;
		}

#ifndef __SPU__

		// Description:
		// The constructor for the PAnimationSlotListIndex class.
		PAnimationSlotListIndex::PAnimationSlotListIndex()
			: m_animKeyType(NULL)
			, m_interp(PE_ANIMINTERP_COUNT)
			, m_targetIndex(0)
			, m_nodeCentricReIndex(0)
		{
		}

		// Description:
		// Hash for simplifying stepping through and combining slot lists.
		// Returns:
		// Hash combining the node index with the animation key type.
		PUInt32 PAnimationSlotListIndex::hash() const
		{
			// The anim key type is more important than the node index so that the slot array contents are sorted by type.
			// This permits fast batch processing of the slot array.
			PHYRE_ASSERT(m_animKeyType);
			PUInt32 index = m_animKeyType ? m_animKeyType->getIndex() : 0;
			return ((index << 24) | m_targetIndex);
		}

		// Description:
		// Less than comparison operator.
		// Arguments:
		// other :  Other PAnimationSlotListIndex to compare with.
		// Returns:
		// True if this object is less than the supplied one.
		bool PAnimationSlotListIndex::operator < (const PAnimationSlotListIndex &other) const
		{
			return hash() < other.hash();
		}

		// Description:
		// Greater than comparison operator.
		// Arguments:
		// other :  Other PAnimationSlotListIndex to compare with.
		// Returns:
		// True if this object is greater than the supplied one.
		bool PAnimationSlotListIndex::operator > (const PAnimationSlotListIndex &other) const
		{
			return hash() > other.hash();
		}

		// Description:
		// Equality comparison operator.
		// Arguments:
		// other :  Other PAnimationSlotListIndex to compare with.
		// Returns:
		// True if this object is equal to the supplied one.
		bool PAnimationSlotListIndex::operator == (const PAnimationSlotListIndex &other) const
		{
			return hash() == other.hash();
		}

#endif //! __SPU__

		//!
		//! PAnimationSlotArrayElement implementation.
		//!

		// Description:
		// Assignment operator for the PAnimationSlotArrayElement class.
		// Arguments:
		// other :  Object to copy.
		// Returns:
		// Constant reference to assigned object.
		const PAnimationSlotArrayElement &PAnimationSlotArrayElement::operator = (const PAnimationSlotArrayElement &other)
		{
			m_value = other.m_value;
			m_slotListIndex = other.m_slotListIndex;

			return *this;
		}

		// Gets m_value.
		const PAnimationSlotArrayElement::PValueType &PAnimationSlotArrayElement::getValue() const
		{
			return m_value;
		}

		// Gets m_value.
		PAnimationSlotArrayElement::PValueType &PAnimationSlotArrayElement::getValue()
		{
			return m_value;
		}

		// Gets m_slotListIndex.
		const PAnimationSlotListIndex &PAnimationSlotArrayElement::getSlotListIndex() const
		{
			return m_slotListIndex;
		}

		// Description:
		// Sets the target slot ID for this slot.
		// Arguments:
		// keyType :		Target key type for this slot.
		// interp :			Interpolation method to use.
		// targetIndex :	Target index for this slot.
		void PAnimationSlotArrayElement::setTargetSlotIndex(const PAnimationKeyDataType *keyType, PAnimationInterpolationType interp, PUInt32 targetIndex)
		{
			m_slotListIndex.init(keyType, interp, targetIndex);
		}

		// Sets m_slotListIndex.
		void PAnimationSlotArrayElement::setTargetSlotIndex(const PAnimationSlotListIndex &slotListIndex)
		{
			m_slotListIndex = slotListIndex;
		}

		// Sets m_value.
		void PAnimationSlotArrayElement::setValue(const PAnimationSlotArrayElement::PValueType &value)
		{
			m_value = value;
		}

		//!
		//! PAnimationSlotArray implementation.
		//!

		// Sets m_slots.
		void PAnimationSlotArray::setSlotAddr(PAnimationSlotArrayElement *slots)
		{
			m_slots = slots;
		}

		// Gets m_slots.
		PAnimationSlotArrayElement *PAnimationSlotArray::getSlots() const
		{
			return m_slots;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SLOT_ARRAY_INL
