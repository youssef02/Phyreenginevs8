/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_NETWORK_OPTIMIZE_BUFFER_ALLOCATOR_H
#define PHYRE_NETWORK_OPTIMIZE_BUFFER_ALLOCATOR_H

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// Manages the allocation and tracking of the cost of buffers used during the network's processing.
		class PNetworkOptimizeBufferAllocator
		{
		public:
			// Description:
			// Provides an abstract base class for adding additional constraints to the allocation algorithm. Additional acceptance/rejection criteria may be added to
			// candidate buffers for allocation. This base class should be subclassed, additional contextual information should be added in the derived class, and it
			// should be passed to the PNetworkOptimizeBufferAllocator::allocate() method.
			class PBufferAcceptance
			{
			public:
				// Description:
				// Accept or reject a buffer as a good or bad candidate for allocation.
				// Arguments:
				// bufferIndex - The buffer being considered for allocation.
				// allocator - The allocator object performing the allocation.
				// Return Value List:
				// true - The buffer is a good candidate for allocation.
				// false - The buffer is a bad candidate for allocation.
				virtual bool bufferOkToAllocate(PInt32 bufferIndex, const PNetworkOptimizeBufferAllocator &allocator) = 0;

				virtual ~PBufferAcceptance();
			};

		private:
			// Description:
			// Maintains the allocation status and maximum cost of buffers allocated for network processing.
			class PBufferInfo : public PMemoryBase
			{
			public:
				bool						m_allocated;				// Is this buffer allocated.
				PUInt32						m_bufferCost;				// Maximum buffer cost so far

				PBufferInfo();
			};

			PBufferInfo						*m_buffers;					// Array of buffer information.
			PUInt32							m_bufferCount;				// Buffers allocated.
			PInt32							m_maxBufferIndexAllocated;	// Maximum index of buffer allocated.

			bool growBufferList();

		public:
			PNetworkOptimizeBufferAllocator();
			virtual ~PNetworkOptimizeBufferAllocator();

			PInt32 allocate(PUInt32 cost, PNetworkOptimizeBufferAllocator::PBufferAcceptance &acceptance);
			void deallocate(PUInt32 index);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_NETWORK_OPTIMIZE_BUFFER_ALLOCATOR_H
