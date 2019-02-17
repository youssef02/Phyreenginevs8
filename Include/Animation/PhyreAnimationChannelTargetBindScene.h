/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SCENE_H
#define PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SCENE_H

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The class for binding animation channel targets to named nodes within a scene node hierarchy.
		class PAnimationChannelTargetBindScene : public PAnimationChannelTargetBind
		{
			PHYRE_PRIVATE_ASSIGNMENT_OPERATOR(PAnimationChannelTargetBindScene);

		protected:
			PScene::PNode &m_bindRoot;						// The root of the scene graph hierarchy to bind too.

		public:
			inline PAnimationChannelTargetBindScene(PScene::PNode &bindRoot);

			virtual PResult bindTargets(PAnimationNetworkInstanceTarget *instanceTargets, const PAnimationChannelTarget *targets, PUInt32 targetCount);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SCENE_H
