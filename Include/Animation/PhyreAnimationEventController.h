/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_EVENT_CONTROLLER_H
#define PHYRE_ANIMATION_EVENT_CONTROLLER_H

namespace Phyre
{
	namespace PAnimation
	{

		class PAnimationEventList;
		class PTimeController;
		class PAnimationEvent;
		class PAnimationSlotArray;
		class PAnimationNetworkInstance;
		class PAnimationHierarchyVisitContext;
		class PAnimationHierarchyNode;

		// Description:
		// Processes event lists and notifies events through a registered callback. This animation data source does not produce any slot array output; it is
		// merely a data source that can be processed as part of an animation network.
		class PAnimationEventController : public PAnimationDataSource
		{
		protected:
			PAnimationEventList *m_animationEventList;					// The animation event list this controller uses.
			PTimeController *m_timeController;							// The time controller this controller uses.

			static void EventCallback(const PAnimationEvent &event, void *userData);
			static PResult StaticProcess(PAnimationSlotArray &destSlotArray, const PAnimationSlotArray *const *srceSlotArrays, PUInt32 srceCount, const PAnimationNetworkPreprocessData *preprocessData, void *persistentBuffer, const PAnimationNetworkProcessState &state);
			virtual const PSpu::PElfInfo *getSpuProcessElf() const;
#ifdef PHYRE_SPU_PROFILE
			virtual void addProfileTimer(PUInt32 value) const;
#endif //! PHYRE_SPU_PROFILE

			PHYRE_BIND_DECLARE_CLASS(PAnimationEventController, PAnimationDataSource);

		public:
			PAnimationEventController();
			~PAnimationEventController();

			inline PAnimationEventList *getAnimationEventList() const;
			inline PTimeController *getTimeController() const;
			inline void setAnimationEventList(PAnimationEventList &animationEventList);
			inline void setTimeController(PTimeController &timeController);

			virtual PUInt32 getPreprocessBufferSize() const;
			virtual PUInt32 getPersistentBufferSize() const;
			virtual PUInt32 populatePreprocess(PAnimationNetworkInstance &instance, PAnimationNetworkPreprocessData &buffer, void *persistentBuffer);

			virtual PAnimationDataSourceProcessFn getProcessFn() const;

			//! PAnimationHierarchyNode functionality
			virtual bool traverseHierarchy(PAnimationHierarchyVisitContext &context, PAnimationHierarchyNode *parent = NULL);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_EVENT_CONTROLLER_H
