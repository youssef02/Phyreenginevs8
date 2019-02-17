/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_ADDITIVE_BLENDER_CONTROLLER_H
#define PHYRE_ANIMATION_ADDITIVE_BLENDER_CONTROLLER_H

namespace Phyre
{
	namespace PAnimation
	{

		//! Forward declarations:
		class PAnimationSlotArray;
		class PAnimationNetworkPreprocessData;
		class PAnimationNetworkInstance;
		class PAnimationSlotArrayElement;

		// Description:
		// An implementation of a simple additive blend. The first source is the base animation and any weight assigned to this is ignored. Subsequent sources are
		// added to the base source according to the blend weight specified for them. Source weights are constant across all key frames and nodes.
		class PAnimationAdditiveBlenderController : public PAnimationBlenderController
		{
		protected:
			PArray<float> m_sourceWeights;				// The array of weights for each of the data sources.

			static PResult StaticProcess(PAnimationSlotArray &destSlotArray, const PAnimationSlotArray *const *srceSlotArrays, PUInt32 srceCount, const PAnimationNetworkPreprocessData *preprocessData, void *persistentBuffer, const PAnimationNetworkProcessState &state);
			virtual const PSpu::PElfInfo *getSpuProcessElf() const;
#ifdef PHYRE_SPU_PROFILE
			virtual void addProfileTimer(PUInt32 value) const;
#endif //! PHYRE_SPU_PROFILE

			PHYRE_BIND_DECLARE_CLASS(PAnimationAdditiveBlenderController, PAnimationBlenderController);

		public:
			PAnimationAdditiveBlenderController();
			~PAnimationAdditiveBlenderController();

			virtual PUInt32 getPreprocessBufferSize() const;
			virtual PUInt32 populatePreprocess(PAnimationNetworkInstance &instance, PAnimationNetworkPreprocessData &buffer, void *persistentBuffer);

			virtual PAnimationDataSourceProcessFn getProcessFn() const;
			virtual PResult setSourceCount(PUInt32 inputCount);

			inline float getWeight(PUInt32 index) const;

			PResult setWeight(PUInt32 index, float weight);
			static bool BlendKeys(PAnimationSlotArrayElement *result, PAnimationInterpolationType interp, const PAnimationSlotArrayElement **sourceKeys, PUInt32 keyCount, const PAnimationNetworkPreprocessData *preprocessData, void *persistentBuffer);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_ADDITIVE_BLENDER_CONTROLLER_H
