/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SLOT_FILTER_INL
#define PHYRE_ANIMATION_SLOT_FILTER_INL

namespace Phyre
{
	namespace PAnimation
	{

		//!
		//! PAnimationSlotFilterDeferredLoad implementation.
		//!

		// Description:
		// The constructor for the PAnimationSlotFilterDeferredLoad class.
		PAnimationSlotFilterDeferredLoad::PAnimationSlotFilterDeferredLoad()
			: m_keyType(NULL)
		{
		}

		//!
		//! PAnimationSlotFilter implementation.
		//!

		// Description:
		// Gets the m_animDataSource member.
		// Returns:
		// A pointer to the animation data source.
		PAnimationDataSource *PAnimationSlotFilter::getSource() const
		{
			return m_animDataSource;
		}

		// Description:
		// Gets the number of animation data sources processed by this animation network instance.
		// Returns:
		// Number of animation data sources that this animation network instance processes.
		PUInt32 PAnimationSlotFilter::getSourceCount() const
		{
			return 1;
		}

		// Description:
		// Gets the m_animDataSource member.
		// Arguments:
		// index - The index.
		// Returns:
		// A pointer to the animation data source.
		PAnimationDataSource *PAnimationSlotFilter::getSource(PUInt32 index) const
		{
			(void)index;
			return m_animDataSource;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SLOT_FILTER_INL
