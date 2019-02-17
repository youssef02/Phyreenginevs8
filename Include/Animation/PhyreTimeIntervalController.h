/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_TIME_INTERVAL_CONTROLLER_H
#define PHYRE_TIME_INTERVAL_CONTROLLER_H

namespace Phyre
{
	namespace PAnimation
	{

		class PAnimationHierarchyVisitContext;
		class PAnimationHierarchyNode;

		// Description:
		// Provides looping functionality from a source time base. A range of times can be generated, based at any position in the parent time base.
		class PTimeIntervalController : public PTimeController
		{
		protected:
			PTimeController * m_parent;									// Parent from which to get input from.
			float m_parentBase;											// Time of parent that maps to base time in local interval.
			float m_localBase;											// Base of local time interval. Local base is the lower extent of the time range output.
			float m_localRange;											// Size of local time interval. Local range is the size of the time range output.

			PHYRE_BIND_DECLARE_CLASS(PTimeIntervalController, PTimeController);

		public:
			PTimeIntervalController();
			~PTimeIntervalController();

			virtual float getTime() const;

			//! PAnimationHierarchyNode functionality
			virtual bool traverseHierarchy(PAnimationHierarchyVisitContext &context, PAnimationHierarchyNode *parent = NULL);

			inline PTimeController *getParent() const;
			inline float getLocalBase() const;
			inline float getLocalRange() const;
			inline float getParentBase() const;

			inline void setParent(PTimeController &parent);
			inline void setParentBase(float parentBase);
			inline void setLocalBase(float localBase);
			inline void setLocalRange(float localRange);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_TIME_INTERVAL_CONTROLLER_H
