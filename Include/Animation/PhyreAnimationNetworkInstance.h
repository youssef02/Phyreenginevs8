/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_NETWORK_INSTANCE_H
#define PHYRE_ANIMATION_NETWORK_INSTANCE_H

namespace Phyre
{
	namespace PAnimation
	{

		class PAnimationDataSource;
		class PAnimationNetworkInstance;

		// Description:
		// Pairing of data source and destination buffer for animation network instance processing.
		class PAnimationDataSourceListEntry : public PBase
		{
			PHYRE_BIND_DECLARE_CLASS(PAnimationDataSourceListEntry, PBase);
		public:
			PAnimationDataSource *m_dataSource;							// Data source to be processed.
			PUInt32 m_inputCount;										// Number of slot array inputs.
			PUInt32 m_inputIndex[32];									// Index of input slot arrays.
			PUInt32 m_destSlotArray;									// Target slot array to process into.
			PUInt32 m_persistentBufferOffset;							// The offset into the persistent buffer.
			PUInt32 m_preprocessBufferOffset;							// The offset into the preprocess buffer.

			PAnimationDataSourceListEntry();
		};

		// Description:
		// Represents a target object and index for the target blender to target.
		class PAnimationNetworkInstanceTarget : public PBase
		{
			PHYRE_BIND_DECLARE_CLASS(PAnimationNetworkInstanceTarget, PBase);
		public:
			// Description:
			// Enumerated type to identify the bound target type for an animation channel.
			enum PAnimationNetworkInstanceTargetType
			{
				PE_TARGETTYPE_NONE = 0,									// There is no target type established.
				PE_TARGETTYPE_MEMORY,									// A block of memory is being targeted.
				PE_TARGETTYPE_METHOD,									// An object method is being targeted.
				PE_TARGETTYPE_FUNCTION,									// And object function is being targeted.
				PE_TARGETTYPE_COUNT										// The number of target types.
			};

			PAnimationNetworkInstanceTargetType		m_type;				// Identifier for the target type.

			//! Memory target
			void									*m_memory;			// The address of the memory being targeted.
			PUInt32									m_memorySize;		// The size of the memory being targeted.

			//! Method target
			PBase									*m_object;			// The pointer to the target object.
			const PClassCallableMethod				*m_method;			// The pointer to the caller object for invoking the method.

			//! Function target
			const PClassCallableFunction			*m_function;		// The pointer to the caller object for invoking the function.

			inline PAnimationNetworkInstanceTarget();
		};

		// Description:
		// Animation network instances contain all time controllers and animation controllers to target an object. They also contain a map of animation set node
		// IDs to target object nodes so that the results can be targeted at the correct places.
		//
		// Intermediate processing results are placed in slot arrays. The first pass implementation stores the slot arrays local to the animation controller. A
		// subsequent optimization would be to place these in a preallocated buffer for efficient processing (and the capability of multiple instances for each
		// controller network).
		//
		// The list of animation controllers and time controllers are both sorted so that dependencies are processed automatically before dependents. Assuming
		// that there are no loops in the system, we can use a simple sort with the compare testing for immediate dependencies between elements.
		//
		// The mapping from animation set nodes to real life screen graph nodes is defined by the findTarget pure virtual function. This method must be
		// implemented by a derived class before this class becomes usable.
		class PAnimationNetworkInstance : public PBase
		{
		protected:
			static PAnimationSlotArrayElement *s_slotArrayElements;
			static PUInt32 s_slotArrayElementsSize;
			static PUInt32 s_slotArrayAllocedBase;
			static PUInt32 s_slotArrayAllocedTop;

		protected:
			PArray<PAnimationDataSourceListEntry> m_animationDataSources;	// Array of pointers to animation data sources.

			PArray<PAnimationNetworkInstanceTarget> m_instanceTargetNodes;	// Array of target objects that the animation network targets.
			const PAnimationSet *m_targetNodeListAnimSet;					// Animation set that the node list was built from.
																			// Note: Not this member is not serialized since this would invalidate rebinding on load.

			PAnimationTargetBlenderController *m_targetBlender;				// The target blender to bind.

			PUInt32 m_slotArrayElementsRequired;							// Number of slot array elements required for processing.
			PArray<PUInt128> m_persistentBuffer;							// The persistent buffer used to store persistent state.
			PUInt32 m_preprocessBufferSize;									// The size of preprocess memory.
			PArray<PAnimationSlotArray> m_slotArrays;						// Slot arrays used for processing.

#ifdef PHYRE_SPU_ENABLED

			bool m_spuRunnable;												// Is this network instance executable on SPU.

#endif //! PHYRE_SPU_ENABLED

			PAnimationNetworkInstanceSPUJobPacket *m_jobPacket;				// The SPU job packet for when running asynchronously.

			PResult setAnimationDataSourceCount(PUInt32 animationDataSourceCount);
			PResult setInstanceTargetNodeCount(PUInt32 numInstanceTargetNodes);

			PResult setupSlotArray();

			// Description:
			// Base class for a thread pool job to process animation network instances.
			class PANIThreadPoolJob : public PFreelistAllocatedThreadPoolJob
			{
				PHYRE_PRIVATE_ASSIGNMENT_OPERATOR(PANIThreadPoolJob);

			protected:
				PAnimationNetworkInstance	&m_animNetworkInstance;		// Animation network instance to process.

			public:
				inline PANIThreadPoolJob(PAnimationNetworkInstance &animNetworkInstance);

				virtual void doWork(PUInt8 *threadWorkspace, PUInt32 threadWorkspaceSize, PUInt32 threadNum);
			};

			PFreelistAllocatedThreadPoolJob		*m_threadPoolJob;				// The thread pool job associated with this animation network.
			static PFreeList					*s_jobsFreeList;

			void processUsingInfoPacket(PUInt8 *workspace);

			PHYRE_BIND_DECLARE_CLASS(PAnimationNetworkInstance, PBase);

		public:
			PAnimationNetworkInstance();
			virtual ~PAnimationNetworkInstance();

			//! Thread pools and processing
			static PResult InitializeThreadPool();
			static PResult TerminateThreadPool();
			inline static void KickThreadPool();
			PResult processStart();
			PResult processEnd();
			static void ProcessReset();

			//! Binding and unbinding.
			PResult bind(PAnimationTargetBlenderController *targetBlender, PAnimationChannelTargetBind **binders, PUInt32 binderCount);

			PUInt32 getProcessBufferSize() const;
			static PResult SetProcessBuffer(PAnimationSlotArrayElement *processBuffer, PUInt32 numElements);
			inline static PUInt32 GetProcessBufferSize();
			inline static const PAnimationSlotArrayElement *GetProcessBuffer();

			inline PResult invalidateTargetNodeList();
			inline PUInt32 getAnimationDataSourceCount() const;
			inline const PAnimationNetworkInstanceTarget *getInstanceTargetNodes() const;
			inline PUInt32 getInstanceTargetNodeCount() const;
			inline PAnimationDataSource *getAnimationDataSource(PUInt32 index) const;
			inline const PAnimationSet *getTargetNodeAnimationSet() const;

			inline const PAnimationNetworkInstanceTarget *getInstanceTargetNodeInfo(PUInt32 index) const;
			inline PAnimationTargetBlenderController *getTargetBlender() const;

			virtual void processAnimationEvent(const PAnimationEvent &eventToProcess, float prevTime, float curTime);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_NETWORK_INSTANCE_H
