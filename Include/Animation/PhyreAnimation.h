/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_H
#define PHYRE_ANIMATION_H

namespace Phyre
{
	// Description:
	// The namespace for Phyre animation classes and functions.
	// The animation module provides animation facilities for PhyreEngine(TM). Processing uses
	// animation networks of time controllers and animation data sources.
	//
	// Time controllers take a time value, and after performing some processing produce a new time
	// value. Different types of time controllers perform different processing on the time values.
	// Examples of processing include looping (via modulo operations), speed control (via scaling)
	// and phase adjustment (via addition).
	//
	// Animation networks produce and process slot arrays.  Slot arrays contain an intermediate
	// animation state for the animation network, consisting of a snapshot of the state for multiple
	// animation targets. Slot arrays are a fixed size array of slot array elements. Slot array
	// elements comprise a key type and an (up to) 4 float value. Slot arrays are sorted primarily
	// by animation key data type which causes like-typed keys to appear adjacent in the array.
	// This permits optimized/unrolled processing on the slot array.
	//
	// Animation data sources produce slot arrays. Animation data sources come in lots of different
	// types to perform different kinds of processing. Some (such as animation controllers) do this
	// from an animation source. Others (such as blender controllers) take one or more slot arrays
	// as input and process them to produce an output. Some have a one in, one out data flow, with
	// simple processing such as filtering.
	//
	// Slot arrays are sized and laid out to hold the superset of all animation channels within the
	// animation clips within an animation set. This is achieved by compiling the animation set. This
	// operation also pushes information to the animation clips themselves to allow them to efficiently
	// populate slot arrays.
	//
	// Animation channels within animation clips are sparsely scattered into the slot array by
	// an animation controller using the information generated at animation set compile time. The channels
	// are sorted/processed by interpolation type so as to enable unrolled/efficient processing.
	//
	// Target blenders gather from slot arrays in order to capture the different key types required
	// for a single target. This allows combination of different keys types that target the same
	// target. This allows channels such as scale, rotation and translation to be combined correctly
	// before being written to the target matrix.
	//
	// Interpolation types are specified per animation channel.
	namespace PAnimation
	{
	} //! End of PAnimation namespace.
} //! End of Phyre namespace.

#include "PhyreUtilityAnimation.h"

//! Processing optimization
#include "PhyreNetworkOptimizeBufferAllocator.h"
#include "PhyreNetworkOptimizeProcess.h"
#include "PhyreNetworkOptimize.h"
#include "PhyreAnimationSetSlotListIndexLookup.h"
#include "PhyreAnimationSetTargetLookup.h"

//! Animation data structures
#include "PhyreAnimationKeyDataType.h"
#include "PhyreAnimationSlotArray.h"
#include "PhyreAnimationChannelTimes.h"
#include "PhyreAnimationChannelTarget.h"
#include "PhyreAnimationChannelBase.h"
#include "PhyreAnimationChannel.h"
#include "PhyreAnimationConstantChannel.h"
#include "PhyreAnimationClipBinding.h"
#include "PhyreAnimationClip.h"
#include "PhyreAnimationSet.h"
#include "PhyreAnimationEventList.h"

#include "PhyreAnimationHierarchyNode.h"
#include "PhyreAnimationHierarchyCountNodes.h"
#include "PhyreAnimationHierarchyPopulateArrays.h"
#include "PhyreAnimationHierarchyDetectLoops.h"

//! Time controllers
#include "PhyreTimeController.h"
#include "PhyreTimeIntervalController.h"
#include "PhyreTimeScaleOffsetController.h"

//! Pre process data for animation data sources
#include "PhyreAnimationNetworkProcessState.h"
#include "PhyreAnimationNetworkPreprocessData.h"
#include "PhyreAnimationControllerPreprocessData.h"
#include "PhyreAnimationSlotFilterPreprocessData.h"
#include "PhyreAnimationWeightedBlenderControllerPreprocessData.h"
#include "PhyreAnimationAdditiveBlenderControllerPreprocessData.h"
#include "PhyreAnimationSpuTargetBlenderControllerPreprocessData.h"
#include "PhyreAnimationNetworkInstanceSPUJobPacket.h"

#include "PhyreVisitorFindNamedNodes.h"

//! Animation data sources
#include "PhyreAnimationDataSource.h"
#include "PhyreAnimationEventController.h"
#include "PhyreAnimationController.h"
#include "PhyreAnimationSlotFilter.h"
#include "PhyreAnimationBlenderController.h"
#include "PhyreAnimationWeightedBlenderController.h"
#include "PhyreAnimationAdditiveBlenderController.h"
#include "PhyreAnimationSpuTargetBlenderController.h"
#include "PhyreAnimationTargetBlenderController.h"

//! Instantiation
#include "PhyreAnimationChannelTargetBind.h"
#include "PhyreAnimationChannelTargetBindDataMember.h"
#include "PhyreAnimationChannelTargetBindShaderParameter.h"
#include "PhyreAnimationChannelTargetBindFunction.h"
#include "PhyreAnimationChannelTargetBindMethod.h"
#include "PhyreAnimationChannelTargetBindScene.h"
#include "PhyreAnimationNetworkInstance.h"

//! Component(s)
#include "PhyreAnimatableComponent.h"

//! Processing
#include "PhyreAnimationNetworkInstanceProcessHelper.h"

//! Inline files
#include "PhyreAnimationAdditiveBlenderController.inl"
#include "PhyreAnimationAdditiveBlenderControllerPreprocessData.inl"
#include "PhyreAnimationBlenderController.inl"
#include "PhyreAnimationChannel.inl"
#include "PhyreAnimationChannelBase.inl"
#include "PhyreAnimationChannelTarget.inl"
#include "PhyreAnimationChannelTargetBindShaderParameter.inl"
#include "PhyreAnimationChannelTargetBindDataMember.inl"
#include "PhyreAnimationChannelTargetBindFunction.inl"
#include "PhyreAnimationChannelTargetBindMethod.inl"
#include "PhyreAnimationChannelTargetBindScene.inl"
#include "PhyreAnimationChannelTimes.inl"
#include "PhyreAnimationClip.inl"
#include "PhyreAnimationClipBinding.inl"
#include "PhyreAnimationConstantChannel.inl"
#include "PhyreAnimationController.inl"
#include "PhyreAnimationControllerPreprocessData.inl"
#include "PhyreAnimationDataSource.inl"
#include "PhyreAnimationEventController.inl"
#include "PhyreAnimationEventList.inl"
#include "PhyreAnimationHierarchyCountNodes.inl"
#include "PhyreAnimationHierarchyPopulateArrays.inl"
#include "PhyreAnimationKeyDataType.inl"
#include "PhyreAnimationNetworkInstance.inl"
#include "PhyreAnimationNetworkInstanceProcessHelper.inl"
#include "PhyreAnimationNetworkInstanceSPUJobPacket.inl"
#include "PhyreAnimationNetworkPreprocessData.inl"
#include "PhyreAnimationSet.inl"
#include "PhyreAnimationSetSlotListIndexLookup.inl"
#include "PhyreAnimationSetTargetLookup.inl"
#include "PhyreAnimationSlotArray.inl"
#include "PhyreAnimationSlotFilter.inl"
#include "PhyreAnimationSlotFilterPreprocessData.inl"
#include "PhyreAnimationSpuTargetBlenderController.inl"
#include "PhyreAnimationSpuTargetBlenderControllerPreprocessData.inl"
#include "PhyreAnimationTargetBlenderController.inl"
#include "PhyreAnimationWeightedBlenderController.inl"
#include "PhyreAnimationWeightedBlenderControllerPreprocessData.inl"
#include "PhyreNetworkOptimizeProcess.inl"
#include "PhyreTimeController.inl"
#include "PhyreTimeIntervalController.inl"
#include "PhyreTimeScaleOffsetController.inl"
#include "PhyreVisitorFindNamedNodes.inl"
#include "PhyreAnimatableComponent.inl"

#endif //! PHYRE_ANIMATION_H
