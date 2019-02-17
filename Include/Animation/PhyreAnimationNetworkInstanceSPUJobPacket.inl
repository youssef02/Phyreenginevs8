/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_NETWORK_INSTANCE_SPU_JOB_PACKET_INL
#define PHYRE_ANIMATION_NETWORK_INSTANCE_SPU_JOB_PACKET_INL

namespace Phyre
{
	namespace PSpu
	{
		typedef void *PAddr;
		typedef PUInt32 LSAddress;
	} //! End of PSpu namespace

	namespace PAnimation
	{

		// Description:
		// Calculates the size of the job packet required for a specified number of animation data sources.
		// Arguments:
		// animDataSourceCount - Number of animation data sources to size the job packet for.
		// Returns:
		// Size of the required job packet for the specified number of animation data sources.
		PUInt32 PAnimationNetworkInstanceSPUJobPacket::Size(PUInt32 animDataSourceCount)
		{
			return sizeof(PAnimationNetworkInstanceSPUJobPacket) + (animDataSourceCount-1) * sizeof(PSPUAnimDataSourceInfo);
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_NETWORK_INSTANCE_SPU_JOB_PACKET_INL
