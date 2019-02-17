/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_NETWORK_OPTIMIZE_H
#define PHYRE_NETWORK_OPTIMIZE_H

namespace Phyre
{
	namespace PAnimation
	{
		// Description:
		// Defines an input to a process, in terms of the providing process's index, and the particular output of that process.
		class PNetworkOptimizeInput
		{
		public:
			PUInt32					m_processIndex;			// Index of process providing the input.
			PUInt32					m_outputIndex;			// Index of process's output providing the input.
		};

		// Description:
		// Manages the optimization of a network of interdependent network processes. The order and output buffer allocations for the processes will be decided at
		// \optimization time.
		class PNetworkOptimize
		{
		private:
			PNetworkOptimizeProcess		*m_processes;						// The array of network processes making up the network to be optimized.
			PUInt32						m_processCount;						// The number of network processes to be optimized.

		public:
			PNetworkOptimize();
			~PNetworkOptimize();

			bool setProcessCount(PUInt32 processCount);
			bool setProcess(PUInt32 processIndex, const PChar *name,
							PUInt32 inputCount, const PNetworkOptimizeInput *inputs,
							PUInt32 outputCount, const PUInt32 *outputCosts);

			bool optimize(bool reuseInputs = false);

			PUInt32 getProcessCount() const;
			PInt32 getProcessAtSlot(PInt32 slot) const;
			PInt32 getOutputAtSlot(PInt32 slot, PUInt32 outputIndex) const;
			PInt32 getInputCountAtSlot(PInt32 slot) const;
			PInt32 getInputAtSlot(PInt32 slot, PInt32 inputIndex) const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_NETWORK_OPTIMIZE_H
