/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_DATA_SOURCE_INL
#define PHYRE_ANIMATION_DATA_SOURCE_INL

namespace Phyre
{
	namespace PAnimation
	{
		// Sets m_animationSet.
		void PAnimationDataSource::setAnimationSet(PAnimationSet *animationSet)
		{
			m_animationSet = animationSet;
		}

		// Sets m_animationSet.
		void PAnimationDataSource::setAnimationSet(PAnimationSet &animationSet)
		{
			m_animationSet = &animationSet;
		}

		// Gets m_animationSet.
		PAnimationSet *PAnimationDataSource::getAnimationSet() const
		{
			return m_animationSet;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_DATA_SOURCE_INL
