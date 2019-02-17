/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_NETWORK_INSTANCE_PROCESS_HELPER_INL
#define PHYRE_ANIMATION_NETWORK_INSTANCE_PROCESS_HELPER_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationNetworkInstanceProcessHelper templated class.
		// Template Arguments:
		// MAX_JOBS - The maximum number of jobs.
		template <PUInt32 MAX_JOBS>
		PAnimationNetworkInstanceProcessHelper<MAX_JOBS>::PAnimationNetworkInstanceProcessHelper()
			: PAnimationNetworkInstanceProcessHelperBase(m_queuedJobsBuffer, MAX_JOBS)
		{
		}

		// Description:
		// The destructor for the PAnimationNetworkInstanceProcessHelper templated class.
		// Template Arguments:
		// MAX_JOBS - The maximum number of jobs.
		template <PUInt32 MAX_JOBS>
		PAnimationNetworkInstanceProcessHelper<MAX_JOBS>::~PAnimationNetworkInstanceProcessHelper()
		{
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_NETWORK_INSTANCE_PROCESS_HELPER_INL
