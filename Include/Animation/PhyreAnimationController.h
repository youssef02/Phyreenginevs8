/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CONTROLLER_H
#define PHYRE_ANIMATION_CONTROLLER_H

namespace Phyre
{
	namespace PAnimation
	{

		class PAnimationClip;
		class PTimeController;
		class PAnimationSlotArray;
		class PAnimationNetworkPreprocessData;
		class PAnimationNetworkInstance;
		class PAnimationHierarchyVisitContext;
		class PAnimationHierarchyNode;

		// Description:
		// The PAnimationController class takes animation data from an animation, and a time from a time controller, and generates interpolated animation
		// data, placing the results in the output slot array for processing by other operators (blenders and target blenders).
		class PAnimationController : public PAnimationDataSource
		{
		protected:
			PAnimationClip *m_animationClip;							// The animation clip that this controller uses.
			PTimeController *m_timeController;							// The time controller this controller uses.

			static PResult StaticProcess(PAnimationSlotArray &destSlotArray, const PAnimationSlotArray *const *srceSlotArrays, PUInt32 srceCount, const PAnimationNetworkPreprocessData *preprocessData, void *persistentBuffer, const PAnimationNetworkProcessState &state);
			virtual const PSpu::PElfInfo *getSpuProcessElf() const;
#ifdef PHYRE_SPU_PROFILE
			virtual void addProfileTimer(PUInt32 value) const;
#endif //! PHYRE_SPU_PROFILE

			PHYRE_BIND_DECLARE_CLASS(PAnimationController, PAnimationDataSource);

		public:
			PAnimationController();
			~PAnimationController();

			inline PAnimationClip *getAnimationClip() const;
			inline PTimeController *getTimeController() const;

			virtual PUInt32 getPersistentBufferSize() const;
			virtual PUInt32 getPreprocessBufferSize() const;
			virtual PUInt32 getPrefetchBufferSize() const;
			virtual PUInt32 populatePreprocess(PAnimationNetworkInstance &instance, PAnimationNetworkPreprocessData &buffer, void *persistentBuffer);

			virtual PAnimationDataSourceProcessFn getProcessFn() const;

			PResult setAnimationClip(PAnimationClip &animationClip);
			PResult setTimeController(PTimeController &timeController);

			//! PAnimationHierarchyNode functionality
			virtual bool traverseHierarchy(PAnimationHierarchyVisitContext &context, PAnimationHierarchyNode *parent = NULL);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CONTROLLER_H
