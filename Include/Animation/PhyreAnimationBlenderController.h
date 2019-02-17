/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_BLENDER_CONTROLLER_H
#define PHYRE_ANIMATION_BLENDER_CONTROLLER_H

namespace Phyre
{
	namespace PAnimation
	{

		//! Forward declarations:
		class PAnimationNetworkInstance;
		class PAnimationSlotListIndex;
		class PAnimationSlotArrayElement;
		class PAnimationNetworkPreprocessData;
		class PAnimationSlotArray;
		class PAnimationHierarchyVisitContext;
		class PAnimationHierarchyNode;

		// Description:
		// Blender controllers combine multiple animation sources to produce one output. The combination is defined by the blendKeys() pure virtual
		// function (PAnimationWeightedBlenderController provides a simple weighted blend implementation).
		class PAnimationBlenderController : public PAnimationDataSource
		{
		public:
			// Description:
			// The PBlendKeysFn class defines the prototype of a function to blend several keys.
			// Arguments:
			// result :            Slot array element in which to place the result.
			// interp :            Interpolation scheme to use.
			// sourceKeys :        Arrays of source keys to blend.
			// keyCount :          Number of keys to blend.
			// preprocessData :    Pre\-process data containing the blend weights.
			// persistentBuffer :  Persistent buffer for storing any necessary coherence information.
			// Return Value List:
			// true - A blended key was produced.
			// false - A blended key was not produced.
			typedef bool (*PBlendKeysFn)(PAnimationSlotArrayElement *result, PAnimationInterpolationType interp, const PAnimationSlotArrayElement **sourceKeys, PUInt32 keyCount, const PAnimationNetworkPreprocessData *preprocessData, void *persistentBuffer);

		protected:
			PArray<PAnimationDataSource *> m_sources;	// An array of blender controller inputs.

			static PResult StaticProcess(PAnimationSlotArray &destSlotArray, const PAnimationSlotArray *const *srceSlotArrays, PUInt32 srceCount, const PAnimationNetworkPreprocessData *preprocessData, void *persistentBuffer, const PAnimationNetworkProcessState &state, PBlendKeysFn blendKeys);

			PHYRE_BIND_DECLARE_CLASS_ABSTRACT(PAnimationBlenderController, PAnimationDataSource);

		public:
			PAnimationBlenderController();
			~PAnimationBlenderController();

			virtual PResult setSourceCount(PUInt32 inputCount);
			PResult setSource(PUInt32 index, PAnimationDataSource &source);

			//! PAnimationHierarchyNode functionality

			inline virtual PUInt32 getSourceCount() const;
			inline virtual PAnimationDataSource *getSource(PUInt32 index) const;

			virtual bool traverseHierarchy(PAnimationHierarchyVisitContext &context, PAnimationHierarchyNode *parent = NULL);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_BLENDER_CONTROLLER_H
