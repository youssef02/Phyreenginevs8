/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SCENE_INL
#define PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SCENE_INL

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// The constructor for the PAnimationChannelTargetBindScene class.
		// Arguments:
		// bindRoot : The root of the scene node hierarchy to bind to.
		PAnimationChannelTargetBindScene::PAnimationChannelTargetBindScene(PScene::PNode &bindRoot)
			: m_bindRoot(bindRoot)
		{
		}

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_BIND_SCENE_INL
