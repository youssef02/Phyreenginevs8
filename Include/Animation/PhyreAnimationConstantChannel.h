/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CONSTANT_CHANNEL_H
#define PHYRE_ANIMATION_CONSTANT_CHANNEL_H

namespace Phyre
{
	namespace PAnimation
	{

		// Description:
		// A pairing of a constant value and target node for the animation.
		class PAnimationConstantChannel : public PAnimationChannelBase
		{
		protected:

			float m_value[4];										// A constant value.

			PHYRE_BIND_DECLARE_CLASS(PAnimationConstantChannel, PAnimationChannelBase);

		public:

			inline const float *getValue() const;

			inline PAnimationConstantChannel();

			const PAnimationConstantChannel &operator =(const PAnimationConstantChannel &other);

			void setValue(const float *value);
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CONSTANT_CHANNEL_H
