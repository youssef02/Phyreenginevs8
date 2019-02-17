/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_NETWORK_PROCESS_STATE_H
#define PHYRE_ANIMATION_NETWORK_PROCESS_STATE_H

namespace Phyre
{
	namespace PAnimation
	{

		//! Forward declarations.
		class PAnimationSlotListIndex;

		// Description:
		// Contains global information relating to the processing of an animation network.
		class PAnimationNetworkProcessState
		{
		public:
			const PAnimationSlotListIndex	*m_slotArrayIndices;	// Slot list entries describing the purpose of slot array entries in the slot array.
			PUInt32							m_slotArraySize;		// Number of entries in a slot array.
			PUInt8							*m_tempSpace;			// Temp workspace for network processing.  Only relevant on SPU.
			PUInt32							m_tempSpaceSize;		// Size of workspace.
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_NETWORK_PROCESS_STATE_H
