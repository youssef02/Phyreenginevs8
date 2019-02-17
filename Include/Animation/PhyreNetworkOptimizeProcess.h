/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_NETWORK_OPTIMIZE_PROCESS_H
#define PHYRE_NETWORK_OPTIMIZE_PROCESS_H

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Represents a node within the network being optimized. It manages the input and output dependencies as well as the allocated output buffer and order of
		// processing.                                                                                                                                           
		class PNetworkOptimizeProcess : public PMemoryBase
		{
		public:
			// Description:
			// The PNetworkOptimizeProcessBufferState indicates the state of the output buffer allocation for this process.
			enum PNetworkOptimizeProcessBufferState
			{
				BUFFER_UNALLOCATED = 0,								// The output buffer has not yet been allocated.
				BUFFER_ALLOCATED,									// The output buffer has been allocated and is live.
				BUFFER_EXPIRED										// The output buffer has expired and is available for re-use.
			};

			// Description:
			// Information about an input to a network process.
			class PNetworkOptimizeProcessInput
			{
			public:
				PNetworkOptimizeProcess				*m_input;				// The process feeding an input in this process.
				PUInt32								m_outputIndex;			// The input of the output from the process.

				inline PNetworkOptimizeProcessInput();
			};

			// Description:
			// Information about an output from a network process.
			class PNetworkOptimizeProcessOutput
			{
			public:
				PUInt32								m_cost;					// The cost of storing this output.
				PNetworkOptimizeProcessBufferState	m_bufferSlotState;		// The state of the buffer allocation for this output.
				PInt32								m_bufferSlot;			// The buffer index used for this output.

				inline PNetworkOptimizeProcessOutput();
			};

		public:
			PChar									m_name[256];			// The name of the object represented by this network process.

			PUInt32									m_inputCount;			// The number of inputs for this network process.
			PNetworkOptimizeProcessInput			m_inputs[32];			// The inputs for this network process.

			PUInt32									m_outputCount;			// The number of outputs for this network process.
			PNetworkOptimizeProcessOutput			m_outputs[32];			// The cost of the outputs for this network process.

			PUInt32									m_consumerCount;		// The number of consumers of the output produced by this network node.
			PNetworkOptimizeProcess					*m_consumers[32];		// The consumers of the output produced by this network node.

			PInt32									m_scheduleSlot;			// The processing schedule slot defining the order in which network processes are to be processed.
																			// Equal to -1 if it is not yet decided.

	public:
			PNetworkOptimizeProcess();

			bool setName(const PChar *name);
			bool addInput(PNetworkOptimizeProcess *inputProcess, PUInt32 outputIndex);
			bool addOutput(PUInt32 cost);
			bool addConsumer(PNetworkOptimizeProcess *consumerProcess);

			bool hasInput(const PNetworkOptimizeProcess *inputProcess, PUInt32 outputIndex) const;

			bool consumersAllScheduled(PUInt32 outputIndex) const;
			bool inputsAllScheduled() const;
			bool isScheduled() const;

			void reset();

			bool allocateOutputBuffers(PNetworkOptimizeBufferAllocator &buffers);
			bool expireBuffers(PNetworkOptimizeBufferAllocator &buffers);
			void setScheduleSlot(PInt32 scheduleSlot);

			PInt32 getInputCount() const;
			PInt32 getInputBuffer(PUInt32 index) const;
			PInt32 getOutputBuffer(PUInt32 index) const;

			PNetworkOptimizeProcess::PNetworkOptimizeProcessBufferState getOutputBufferState(PUInt32 index) const;
			const PNetworkOptimizeProcess::PNetworkOptimizeProcessOutput *inputUsingBuffer(PInt32 bufferIndex) const;
			const PChar *getName() const;
			PInt32 getScheduleSlot() const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_NETWORK_OPTIMIZE_PROCESS_H
