/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_TARGET_BLENDER_CONTROLLER_H
#define PHYRE_ANIMATION_TARGET_BLENDER_CONTROLLER_H

namespace Phyre
{
	namespace PAnimation
	{

		//! Forward declarations:
		class PAnimationNetworkInstance;
		class PAnimationSlotArray;
		class PAnimationHierarchyVisitContext;
		class PAnimationHierarchyNode;

		// Description:
		// Responsible for taking a single source of animation data and putting it into scene graph nodes. The single source of animation can be the result of
		// blending multiple animations together through the PAnimationBlenderController class. The mapping onto scene graph nodes is defined by the
		// animation network instance.
		class PAnimationTargetBlenderController : public PAnimationDataSource
		{
		protected:
			PAnimationDataSource *m_animDataSource;						// The single animation data source. This source can be either from a single PAnimationController, or from a PAnimationBlenderController,
	                                        							// which blends multiple animations together.

			virtual const PSpu::PElfInfo *getSpuProcessElf() const;
#ifdef PHYRE_SPU_PROFILE
			virtual void addProfileTimer(PUInt32 value) const;
#endif //! PHYRE_SPU_PROFILE

			PHYRE_BIND_DECLARE_CLASS(PAnimationTargetBlenderController, PAnimationDataSource);

		public:
			PAnimationTargetBlenderController();
			~PAnimationTargetBlenderController();

			virtual PAnimationDataSourceProcessFn getProcessFn() const;

			virtual PUInt32 getPreprocessBufferSize() const;
			virtual PUInt32 populatePreprocess(PAnimationNetworkInstance &instance, PAnimationNetworkPreprocessData &buffer, void *persistentBuffer);
			virtual PResult process(PAnimationNetworkInstance *instance, const PAnimationSlotArray &srceSlotArray) const;
			PResult setSource(PAnimationDataSource &source);

			//! PAnimationHierarchyNode functionality

			inline virtual PUInt32 getSourceCount() const;
			inline PAnimationDataSource *getSource() const;
			inline virtual PAnimationDataSource *getSource(PUInt32 index) const;

			virtual bool traverseHierarchy(PAnimationHierarchyVisitContext &context, PAnimationHierarchyNode *parent = NULL);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_TARGET_BLENDER_CONTROLLER_H
