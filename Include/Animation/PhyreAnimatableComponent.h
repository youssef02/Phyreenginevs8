/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATABLE_COMPONENT_H
#define PHYRE_ANIMATABLE_COMPONENT_H

namespace Phyre
{
	namespace PRendering
	{
		class PMeshInstance;
	} //! End of PRendering namespace.

	namespace PAnimation
	{
		// Description:
		// Represents a component that can be added to an entity to play back a single animation.
		class PAnimatableComponent : public PComponent
		{
			PHYRE_BIND_DECLARE_CLASS(PAnimatableComponent, PComponent);

		protected:
			PAnimationSet						*m_animationSet;					// The animation set for this component.
			PAnimationClip						*m_animationClip;					// The currently playing animation clip. This is set to NULL if the animation clip is uninitialized or stopped.

			PTimeIntervalController				m_timeIntervalController;			// An interval-based time controller for playing looping animations.
			PTimeScaleOffsetController			m_timeScaleOffsetController;		// A scaled and offset time interval controller for playing once off animations and controlling the speed of looping animations.
			PAnimationController				m_animationController;				// An animation controller to read from the playing animation clip.
			PAnimationTargetBlenderController	m_animationTargetBlenderController;	// The target blender for writing the results of the animation.
			PAnimationNetworkInstance			m_animationNetworkInstance;			// The animation network instance for playing the current clip.

			float								m_speed;							// The speed at which to play the animation.

			void enableAnimationNetwork(bool enable);

			PResult prepareToPlay(PAnimationClip *clip);

		public:
			PAnimatableComponent();
			virtual ~PAnimatableComponent();

			PResult configureAnimationDataSources();

			inline PResult			setAnimationSet(PAnimationSet *animationSet);
			inline PAnimationSet	*getAnimationSet() const;
			inline PResult			setAnimationClip(PAnimationClip *animationClip);
			inline PAnimationClip	*getAnimationClip() const;
			inline PAnimationNetworkInstance &getAnimationNetworkInstance();
			inline const PAnimationNetworkInstance &getAnimationNetworkInstance() const;
			inline float getSpeed() const;
			void setSpeed(float speed);

			PResult playOnce(PAnimationClip *clip);
			PResult playLooping(PAnimationClip *clip);
			void stop();

			static PResult FixInstancesAfterLoading(PInstanceList &instances);
		};

	} //! End of PAnimation namespace.

} //! End of Phyre namespace.

#endif //! PHYRE_ANIMATABLE_COMPONENT_H
