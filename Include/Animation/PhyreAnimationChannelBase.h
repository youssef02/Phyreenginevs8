/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_BASE_H
#define PHYRE_ANIMATION_CHANNEL_BASE_H

namespace Phyre
{
	namespace PAnimation
	{
		class PAnimationKeyDataType;

		// Description:
		// The class for adding key type and interpolation information to the animation targeting information
		// provided by PAnimationChannelTarget. This class is subsequently used for animation channels and
		// constant animation channels.
		class PAnimationChannelBase : public PAnimationChannelTarget
		{
		protected:
			const PAnimationKeyDataType *m_keyType;						// The value key type.
			PAnimationInterpolationType m_interp;						// The key interpolation type.

			PHYRE_BIND_DECLARE_CLASS(PAnimationChannelBase, PAnimationChannelTarget);

		public:
			PAnimationChannelBase();
			~PAnimationChannelBase();

			inline void setKeyType(const PAnimationKeyDataType *keyType);
			inline void setInterpolation(PAnimationInterpolationType interp);

			inline const PAnimationKeyDataType *getKeyType() const;
			inline PAnimationInterpolationType getInterpolation() const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_BASE_H
