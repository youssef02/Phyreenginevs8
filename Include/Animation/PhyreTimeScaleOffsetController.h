/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_TIME_SCALE_OFFSET_CONTROLLER_H
#define PHYRE_TIME_SCALE_OFFSET_CONTROLLER_H

namespace Phyre
{
	namespace PAnimation
	{

		class PAnimationHierarchyVisitContext;
		class PAnimationHierarchyNode;

		// Description:
		// Provides speed and synchronization functionality from a source time base. A continuous time is generated, having been scaled and offset by the given
		// parameters.
		class PTimeScaleOffsetController : public PTimeController
		{
		protected:
			PTimeController * m_parent;									// Parent from which to get input.
			float m_scale;												// Relative scale of local time to parent time. The scale determines how fast local time runs with respect to parent time.
			float m_offset;												// Offset of local time to parent time. The offset determines the time shift of local time with respect to parent time.

			PHYRE_BIND_DECLARE_CLASS(PTimeScaleOffsetController, PTimeController);

		public:
			PTimeScaleOffsetController();
			~PTimeScaleOffsetController();

			virtual float getTime() const;

			//! PAnimationHierarchyNode functionality
			virtual bool traverseHierarchy(PAnimationHierarchyVisitContext &context, PAnimationHierarchyNode *parent = NULL);

			inline PTimeController *getParent() const;
			inline float getScale() const;
			inline float getOffset() const;

			inline void setParent(PTimeController &parent);
			inline void setScale(float scale);
			inline void setOffset(float offset);
			void setSpeed(float speed);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_TIME_SCALE_OFFSET_CONTROLLER_H
