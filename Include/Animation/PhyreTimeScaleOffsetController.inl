/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_TIME_SCALE_OFFSET_CONTROLLER_INL
#define PHYRE_TIME_SCALE_OFFSET_CONTROLLER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Gets m_parent.
		PTimeController *PTimeScaleOffsetController::getParent() const
		{
			return m_parent;
		}

		// Gets m_scale.
		float PTimeScaleOffsetController::getScale() const
		{
			return m_scale;
		}

		// Gets m_offset.
		float PTimeScaleOffsetController::getOffset() const
		{
			return m_offset;
		}

		// Sets m_scale.
		void PTimeScaleOffsetController::setScale(float scale)
		{
			m_scale = scale;
		}

		// Sets m_offset.
		void PTimeScaleOffsetController::setOffset(float offset)
		{
			m_offset = offset;
		}

		// Sets m_parent.
		void PTimeScaleOffsetController::setParent(PTimeController &parent)
		{
			m_parent = &parent;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_TIME_SCALE_OFFSET_CONTROLLER_INL
