/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_NETWORK_OPTIMIZE_PROCESS_INL
#define PHYRE_NETWORK_OPTIMIZE_PROCESS_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PNetworkOptimizeProcessInput class.
		PNetworkOptimizeProcess::PNetworkOptimizeProcessInput::PNetworkOptimizeProcessInput()
			: m_input(NULL)
			, m_outputIndex(0)
		{
		}

		// Description:
		// The constructor for the PNetworkOptimizeProcessOutput class.
		PNetworkOptimizeProcess::PNetworkOptimizeProcessOutput::PNetworkOptimizeProcessOutput()
			: m_cost(0)
			, m_bufferSlotState(BUFFER_UNALLOCATED)
			, m_bufferSlot(-1)
		{
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_NETWORK_OPTIMIZE_PROCESS_INL
