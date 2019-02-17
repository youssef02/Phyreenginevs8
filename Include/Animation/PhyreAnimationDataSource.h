/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_DATA_SOURCE_H
#define PHYRE_ANIMATION_DATA_SOURCE_H

namespace Phyre
{
	// Description:
	// The namespace for SPU classes of the Phyre Core.
	namespace PSpu
	{
		//! Forward declarations:
		class PElfInfo;
	} //! End of PSpu namespace

	namespace PAnimation
	{

		//! Forward declarations:
		class PAnimationNetworkInstance;

		// Description:
		// The PAnimationDataSourceProcessFn type defines the prototype for an animation data source process function.  This function
		// is responsible for taking preprocess data, input slot arrays, and persistent data and producing a slot array output.  It can
		// also update the persistent data.
		// Arguments:
		// instance :			Animation network instance being evaluated.
		// destSlotArray :		Target slot array for the animation controller to process into.
		// srceSlotArrays :		Source slot arrays for the animation data source to process from.
		// srceCount :			Number of source slot arrays.
		// preprocessData :		Pre\-process data for the animation node.
		// persistentBuffer :	Per\-instance persistent buffer.
		// state :				Global state for the processing of the animation network.
		// Return Value List:
		// PE_RESULT_NO_ERROR :  The operation was completed successfully.
		typedef PResult (*PAnimationDataSourceProcessFn)(PAnimationSlotArray &destSlotArray, const PAnimationSlotArray *const *srceSlotArrays, PUInt32 srceCount, const PAnimationNetworkPreprocessData *preprocessData, void *persistentBuffer, const PAnimationNetworkProcessState &state);

		// Description:
		// Animation data sources are objects capable of processing and supplying the resultant animation data. They include animation controllers, animation
		// blender controllers, and animation target blender controllers.
		class PAnimationDataSource : public PAnimationHierarchyNode
		{
		protected:
			PAnimationSet *m_animationSet;									// Binding of data source to animation set.

#ifdef PHYRE_SPU_ENABLED

			const PSpu::PElfInfo *m_spuElf;									// Elf info for this animation data source.

#endif //! PHYRE_SPU_ENABLED

			// Description:
			// Return the PElfInfo structure for the SPU ELF associated with this animation data source.
			// Returns:
			// A pointer to the PElfInfo structure for the SPU ELF associated with this animation data source.
			virtual const PSpu::PElfInfo *getSpuProcessElf() const = 0;

			PHYRE_BIND_DECLARE_CLASS_ABSTRACT(PAnimationDataSource, PAnimationHierarchyNode);

		public:
			PAnimationDataSource();
			~PAnimationDataSource();

#ifdef PHYRE_SPU_PROFILE
			// Description:
			// Adds a profile timer value to this animation data source.
			// Arguments:
			// value - Timer value to add to the animation data source profile timer.
			virtual void addProfileTimer(PUInt32 value) const = 0;
#endif //! PHYRE_SPU_PROFILE

			virtual PUInt32 getPersistentBufferSize() const;

			// Description:
			// Gets the worst-case amount of pre-process data required for this data source.
			// Returns:
			// Pre-process data size.
			virtual PUInt32 getPreprocessBufferSize() const = 0;

			virtual PUInt32 getPrefetchBufferSize() const;

			// Description:
			// Populates a preprocess data block containing all the necessary information to process an animation data source.
			// Arguments:
			// instance :          The animation network instance being processed.
			// buffer :            The buffer to populate.
			// persistentBuffer :  The persistent buffer allocated by the network instance to the specification of getPersistentBufferSize().
			// Returns:
			// A pointer to the preprocess data.
			virtual PUInt32 populatePreprocess(PAnimationNetworkInstance &instance, PAnimationNetworkPreprocessData &buffer, void *persistentBuffer) = 0;

			// Description:
			// Accessor for the static process function for this animation node.
			// Returns:
			// A pointer to the process function for this animation node.
			virtual PAnimationDataSourceProcessFn getProcessFn() const = 0;

			const PSpu::PElfInfo *getSpuProcess();

			inline void setAnimationSet(PAnimationSet *animationSet);
			inline void setAnimationSet(PAnimationSet &animationSet);
			inline PAnimationSet *getAnimationSet() const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_DATA_SOURCE_H
