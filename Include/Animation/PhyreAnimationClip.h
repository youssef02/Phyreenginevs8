/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CLIP_H
#define PHYRE_ANIMATION_CLIP_H

namespace Phyre
{
	namespace PAnimation
	{
		class PAnimationClip;
		class PAnimationClipBinding;
		class PAnimationHierarchyNode;
		class PAnimationSet;
		class PAnimationKeyDataType;
		class PTimeController;
		class PAnimationDataSource;

		// Description:
		// Animations are a collection of channels targeted at named nodes. PAnimationClip objects are combined in animation sets
		// (PAnimationSet), which include a list of named nodes that can be targeted by the animation set.
		class PAnimationClip : public PBase
		{
		protected:
			PAnimationClipBinding *m_binding;										// The binding to an animation set.
			PArray<PAnimationChannel *> m_channels;									// The array of channels for this animation.
			PArray<PAnimationConstantChannel> m_constantChannels;					// The array of constant values for this animation.
			float m_constantChannelStartTime;										// The start time of the constant channels.
			float m_constantChannelEndTime;											// The end time of the constant channels.
			PString m_name;															// The name of the animation clip.

			PHYRE_BIND_DECLARE_CLASS(PAnimationClip, PBase);

		public:
			PAnimationClip();
			~PAnimationClip();

			inline const PString &getName() const;
			inline void setName(const PChar *name);

			inline const PAnimationClipBinding *getBinding() const;
			const PAnimationClipBinding *createBinding(PCluster &cluster, PAnimationSet &animSet);
			void purgeBinding(PCluster *cluster);

			inline PUInt32 getAnimationChannelCount() const;
			inline PAnimationChannel *const *getAnimationChannels() const;
			inline PAnimationChannel *getAnimationChannel(PUInt32 index);
			inline const PAnimationChannel *getAnimationChannel(PUInt32 index) const;

			PResult setAnimationChannelCount(PUInt32 channelCount);
			PResult setAnimationChannel(PUInt32 index, PAnimationChannel *channel);
			PResult removeAnimationChannel(PUInt32 index);

			inline PUInt32 getAnimationConstantChannelCount() const;
			inline const PAnimationConstantChannel *getAnimationConstantChannels() const;
			inline PAnimationConstantChannel *getAnimationConstantChannel(PUInt32 index);
			inline const PAnimationConstantChannel *getAnimationConstantChannel(PUInt32 index) const;

			PResult setAnimationConstantChannelCount(PUInt32 constantChannelCount);
			PResult removeAnimationConstantChannel(PUInt32 index);

			PResult setAnimationConstantChannelTimeExtents(float start, float end);
			PResult getAnimationConstantChannelTimeExtents(float &start, float &end) const;

			PResult getTimeExtents(float &minTime, float &maxTime) const;

			PUInt32 countInterpolationKeyTypes() const;

			static PResult FixInstancesAfterLoading(PInstanceList &instances);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CLIP_H
