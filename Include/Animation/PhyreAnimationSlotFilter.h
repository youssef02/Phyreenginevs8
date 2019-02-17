/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_SLOT_FILTER_H
#define PHYRE_ANIMATION_SLOT_FILTER_H

namespace Phyre
{
	namespace PAnimation
	{

		//! Forward declarations
		class PAnimationKeyDataType;
		class PAnimationSlotArray;
		class PAnimationNetworkPreprocessData;
		class PAnimationNetworkInstance;
		class PAnimationHierarchyVisitContext;
		class PAnimationHierarchyNode;

		// Description:
		// The PAnimationSlotFilterDeferredLoad class holds data used to defer processing of a loaded slot block list. It is processed at a fully linked time.
		class PAnimationSlotFilterDeferredLoad : public PBase
		{
			PHYRE_BIND_DECLARE_CLASS(PAnimationSlotFilterDeferredLoad, PBase);

		public:
			const PAnimationKeyDataType		*m_keyType;			// The key type of slot blockage.
			PString							m_nodeName;			// The name of the node being blocked.

			inline PAnimationSlotFilterDeferredLoad();
		};

		// Description:
		// Animation network node that blocks specific slots from passing through the animation network.
		class PAnimationSlotFilter : public PAnimationDataSource
		{
		protected:
			PArray<PUInt32> m_slotBlockList;							// List of slots to block.  These are stored as slot array entry indices.
			PAnimationDataSource *m_animDataSource;						// Source for animation.

			PArray<PAnimationSlotFilterDeferredLoad> m_deferredLoad;	// Array of deferred load slot blockages.

			bool slotIsBlocked(const PUInt32 slot) const;
			static PResult StaticProcess(PAnimationSlotArray &destSlotArray, const PAnimationSlotArray *const *srceSlotArrays, PUInt32 srceCount, const PAnimationNetworkPreprocessData *preprocessData, void *persistentBuffer, const PAnimationNetworkProcessState &state);
			virtual const PSpu::PElfInfo *getSpuProcessElf() const;
#ifdef PHYRE_SPU_PROFILE
			virtual void addProfileTimer(PUInt32 value) const;
#endif //! PHYRE_SPU_PROFILE

			static PInt32 SortCallback(const void *a, const void *b);

			PHYRE_BIND_DECLARE_CLASS(PAnimationSlotFilter, PAnimationDataSource);

		public:
			PAnimationSlotFilter();
			~PAnimationSlotFilter();

			virtual PUInt32 getPreprocessBufferSize() const;
			virtual PUInt32 populatePreprocess(PAnimationNetworkInstance &instance, PAnimationNetworkPreprocessData &buffer, void *persistentBuffer);

			virtual PAnimationDataSourceProcessFn getProcessFn() const;

			PResult blockSlot(const PAnimationSlotListIndex &slot);
			PResult unblockSlot(const PAnimationSlotListIndex &slot);

			inline PAnimationDataSource *getSource() const;

			PResult setSource(PAnimationDataSource &source);

			inline virtual PUInt32 getSourceCount() const;
			inline virtual PAnimationDataSource *getSource(PUInt32 index) const;

			virtual bool traverseHierarchy(PAnimationHierarchyVisitContext &context, PAnimationHierarchyNode *parent = NULL);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_SLOT_FILTER_H
