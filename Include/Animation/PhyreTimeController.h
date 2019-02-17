/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_TIME_CONTROLLER_H
#define PHYRE_TIME_CONTROLLER_H

namespace Phyre
{
	namespace PAnimation
	{

		class PAnimationHierarchyVisitContext;
		class PAnimationHierarchyNode;

		// Description:
		// The base class for all time controllers. In the base class form it provides basic time accumulation functionality. The derived forms, PTimeIntervalController
		// and PTimeScaleOffsetController, provide looping and offset functionality.
		class PTimeController : public PAnimationHierarchyNode
		{
		protected:
			static float s_globalTime;									// Time of controller.

			PHYRE_BIND_DECLARE_CLASS(PTimeController, PAnimationHierarchyNode);

		public:
			PTimeController();

			static PResult GlobalTick(float deltaTime);
			
			inline static float GetGlobalTime();
			inline static void ResetGlobalTime();

			virtual float getTime() const;

			//! PAnimationHierarchyNode functionality
			virtual bool traverseHierarchy(PAnimationHierarchyVisitContext &context, PAnimationHierarchyNode *parent = NULL);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_TIME_CONTROLLER_H
