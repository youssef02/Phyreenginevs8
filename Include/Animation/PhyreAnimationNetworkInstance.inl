/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_NETWORK_INSTANCE_INL
#define PHYRE_ANIMATION_NETWORK_INSTANCE_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationNetworkInstanceTarget class.
		PAnimationNetworkInstanceTarget::PAnimationNetworkInstanceTarget()
			: m_type(PE_TARGETTYPE_NONE)
			, m_memory(NULL)
			, m_memorySize(0)
			, m_object(NULL)
			, m_method(NULL)
			, m_function(NULL)
		{
		}

		///////////////////////////////////////////////////////////////////////

		// Description:
		// The constructor for the PANIThreadPoolJob class.
		// Arguments:
		// animNetworkInstance :  The animation network instance to be processed.
		PAnimationNetworkInstance::PANIThreadPoolJob::PANIThreadPoolJob(PAnimationNetworkInstance &animNetworkInstance)
			: m_animNetworkInstance(animNetworkInstance)
		{
		}

		// Description:
		// Kick any scheduled animation network instance processing if a thread pool is to process it.
		void PAnimationNetworkInstance::KickThreadPool()
		{
			PThreadPool::GetSingleton().startProcessing();
		}

		// Gets s_slotArrayElementsSize.
		PUInt32 PAnimationNetworkInstance::GetProcessBufferSize()
		{
			return s_slotArrayElementsSize;
		}

		// Gets s_slotArrayElements.
		// Note:
		// The pointer is returned as const since this data should not be written.
		const PAnimationSlotArrayElement *PAnimationNetworkInstance::GetProcessBuffer()
		{
			return s_slotArrayElements;
		}

		// Description:
		// Invalidate the target node list. This will cause it to be rebuilt on the next compile().
		// Return Value List:
		// PE_RESULT_NO_ERROR :  The node list was invalidated.
		PResult PAnimationNetworkInstance::invalidateTargetNodeList()
		{
			m_targetNodeListAnimSet = NULL;
			return PE_RESULT_NO_ERROR;
		}

		// Description:
		// Gets the number of animation data sources processed by this animation network instance.
		// Returns:
		// Number of animation data sources that this animation network instance processes.
		PUInt32 PAnimationNetworkInstance::getAnimationDataSourceCount() const
		{
			return m_animationDataSources.getCount();
		}

		// Description:
		// Gets the target nodes array of this animation network instance.
		// Returns:
		// A pointer to the target nodes array of this animation network instance.
		const PAnimationNetworkInstanceTarget *PAnimationNetworkInstance::getInstanceTargetNodes() const
		{
			return m_instanceTargetNodes.getArray();
		}

		// Description:
		// Gets the number of target nodes that this animation network instance targets. This is equal to the total number of nodes that the animation set can
		// target. The actual number of targeted nodes can be a subset of this, depending on selected animations and blender configurations.
		// Returns:
		// Number of object nodes targeted by this animation network instance.
		PUInt32 PAnimationNetworkInstance::getInstanceTargetNodeCount() const
		{
			return m_instanceTargetNodes.getCount();
		}

		// Description:
		// Gets a specific animation data source from the animation network instance.
		// Arguments:
		// index :  The index of the animation data source to obtain.
		// Returns:
		// A pointer to the animation data source (or NULL if the index was out of range).
		PAnimationDataSource *PAnimationNetworkInstance::getAnimationDataSource(PUInt32 index) const
		{
			return (index < m_animationDataSources.getCount()) ? m_animationDataSources[index].m_dataSource : NULL;
		}

		// Description:
		// Gets the target node animation set.
		// Returns:
		// A pointer to the target node animation set.
		const PAnimationSet *PAnimationNetworkInstance::getTargetNodeAnimationSet() const
		{
			return m_targetNodeListAnimSet;
		}

		// Description:
		// Gets information about the animation network instance target.
		// Arguments:
		// index :  The index of the target index to get.
		// Returns:
		// Target node info for the specified slot list index (or 0 if the index was out of range).
		const PAnimationNetworkInstanceTarget *PAnimationNetworkInstance::getInstanceTargetNodeInfo(PUInt32 index) const
		{
			PHYRE_ASSERTMSG(index<m_instanceTargetNodes.getCount(), "PAnimationNetworkInstance::getInstanceTargetNodeInfo : The specified index is invalid");
			return &m_instanceTargetNodes[index];
		}

		// Gets m_targetBlender.
		PAnimationTargetBlenderController *PAnimationNetworkInstance::getTargetBlender() const
		{
			return m_targetBlender;
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_NETWORK_INSTANCE_INL
