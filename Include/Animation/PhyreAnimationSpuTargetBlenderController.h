/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_H
#define PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_H

namespace Phyre
{
	namespace PAnimation
	{

		class PAnimationSlotArray;
		class PAnimationNetworkPreprocessData;
		class PAnimationNetworkInstance;
		class PAnimationHierarchyVisitContext;
		class PAnimationHierarchyNode;

		// Description:
		// The SPU target blender controller is not strictly speaking a target blender. It can be inserted before a target blender to allow an animation network
		// being processed on an SPU to use a fast path to write some animation results back to the scene graph. Matrix results for PNodes will be captured
		// here, written back by DMA, and removed from the slot array. This lightens the load on the main processor.
		class PAnimationSpuTargetBlenderController : public PAnimationDataSource
		{
		protected:
			PAnimationDataSource *m_animDataSource;					// The single animation data source. This source can be either from a single PAnimationController, or from a PAnimationBlenderController,
	                                        						// which blends multiple animations together.

			static PResult StaticProcess(PAnimationSlotArray &destSlotArray, const PAnimationSlotArray *const *srceSlotArrays, PUInt32 srceCount, const PAnimationNetworkPreprocessData *preprocessData, void *persistentBuffer, const PAnimationNetworkProcessState &state);
			virtual const PSpu::PElfInfo *getSpuProcessElf() const;
#ifdef PHYRE_SPU_PROFILE
			virtual void addProfileTimer(PUInt32 value) const;
#endif //! PHYRE_SPU_PROFILE

			PHYRE_BIND_DECLARE_CLASS(PAnimationSpuTargetBlenderController, PAnimationDataSource);

		public:
			PAnimationSpuTargetBlenderController();
			~PAnimationSpuTargetBlenderController();

			virtual PUInt32 getPreprocessBufferSize() const;
			virtual PUInt32 populatePreprocess(PAnimationNetworkInstance &instance, PAnimationNetworkPreprocessData &buffer, void *persistentBuffer);
			virtual PAnimationDataSourceProcessFn getProcessFn() const;

			PResult setSource(PAnimationDataSource &source);

			//! PAnimationHierarchyNode functionality

			inline virtual PUInt32 getSourceCount() const;
			inline PAnimationDataSource *getSource() const;
			inline virtual PAnimationDataSource *getSource(PUInt32 index) const;

			virtual bool traverseHierarchy(PAnimationHierarchyVisitContext &context, PAnimationHierarchyNode *parent = NULL);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SPU_TARGET_BLENDER_CONTROLLER_H
