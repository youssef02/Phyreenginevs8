/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_NETWORK_INSTANCE_PROCESS_HELPER_H
#define PHYRE_ANIMATION_NETWORK_INSTANCE_PROCESS_HELPER_H

namespace Phyre
{
	namespace PAnimation
	{

		class PAnimationNetworkInstance;

		// Description:
		// The base class for the helper to parallelize animation processing.
		class PAnimationNetworkInstanceProcessHelperBase
		{
		protected:
			PAnimationNetworkInstance **m_queuedJobs;	// An array of pointers to queued animation jobs.
			PUInt32 m_maxJobCount;						// The maximum number of jobs to be queued at once.

			PUInt32 m_flushedBase;						// The base index of flushed (but not synced) jobs.
			PUInt32 m_flushedCount;						// The count of flushed (but not synced) jobs.

			PUInt32 m_queuedBase;						// The base index of queued (but not flushed) jobs.
			PUInt32 m_queuedCount;						// The number of queued jobs.

			void pumpPipeline();

		public:
			PAnimationNetworkInstanceProcessHelperBase(PAnimationNetworkInstance **jobQueue, PUInt32 maxJobs);
			~PAnimationNetworkInstanceProcessHelperBase();

			PResult processAnimationNetworkInstance(PAnimationNetworkInstance &animationNetworkInstance);
		};

		// Description:
		// A templated class for parallelizing animation processing.
		// Arguments:
		// MAX_JOBS : The maximum number of jobs to process at once.
		template <PUInt32 MAX_JOBS>
		class PAnimationNetworkInstanceProcessHelper : public PAnimationNetworkInstanceProcessHelperBase
		{
		protected:
			PAnimationNetworkInstance *m_queuedJobsBuffer[MAX_JOBS];	// A buffer of job pointers being processed.

		public:
			PAnimationNetworkInstanceProcessHelper();
			~PAnimationNetworkInstanceProcessHelper();
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_NETWORK_INSTANCE_PROCESS_HELPER_H
