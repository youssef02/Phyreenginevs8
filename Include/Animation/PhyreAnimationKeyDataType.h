/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_KEY_DATA_TYPE_H
#define PHYRE_ANIMATION_KEY_DATA_TYPE_H

namespace Phyre
{
	namespace PAnimation
	{

#ifdef __SPU__

		class PAnimationKeyDataType;

#else //! __SPU__

		// Description:
		// Describes data types for animation keys. Animation keys are stored in PAnimationChannelDataBlocks, and represent things such as times,
		// rotations, translations, scales, and so forth.
		class PAnimationKeyDataType : public PNamedSemantic<class PAnimationKeyDataType>
		{
		protected:
			static PUInt32 s_typeIndex;								// Incrementing animation key data type index for hashing. This is an estimate of how many animation key 
																	// types have been registered. This value is not 100% accurate. It returns a counter used to assign unique IDs
																	// to types, and if any types have been unregistered, this will not be reflected in the count returned.

			PUInt32 m_width;										// Width of the key (in floats).
			PUInt32 m_index;										// Unique index for this key (for hashing).

		public:
			inline PAnimationKeyDataType(const PChar *name, PUInt32 width);
			inline ~PAnimationKeyDataType();
			inline PUInt32 getWidth() const;
			inline PUInt32 getIndex() const;

			static inline PUInt32 GetAnimKeyTypeCount();

			static PResult RegisterAnimationKeyDataType(PAnimationKeyDataType &animationKeyDataType);
			static PResult UnregisterAnimationKeyDataType(PAnimationKeyDataType &animationKeyDataType);
		};

#endif //! __SPU__

		//!
		//! PAnimationKeyDataType Macros
		//!

		// Description:
		// Defines an instance of an animation key type.
		// Arguments:
		// _TYPE : The name for the animation key type.
		// WIDTH : The number of float elements in an animation key of this type.
		#define PHYRE_DEFINE_ANIMKEYTYPE(_TYPE, WIDTH) PAnimationKeyDataType _TYPE##_g_animKeyDataTypeInstance(#_TYPE, WIDTH);

		// Description:
		// Externs an instance of an animation key type to allow applications to access types directly.
		// Arguments:
		// _TYPE : The name of the animation key type to extern.
		#define PHYRE_EXTERN_ANIMKEYTYPE(_TYPE) extern PAnimationKeyDataType _TYPE##_g_animKeyDataTypeInstance;

		// Description:
		// Accesses an animation key type.
		// Arguments:
		// _TYPE : The name of the animation key type to get.
		#define PHYRE_GET_ANIMKEYTYPE(_TYPE) &_TYPE##_g_animKeyDataTypeInstance

		//!
		//! Standard animation key datatypes
		//!

		// Description:
		// Definition for 4 element rotation quaternion.
		PHYRE_EXTERN_ANIMKEYTYPE(Rotation)

		// Description:
		// Definition for 3 element translation vector.
		PHYRE_EXTERN_ANIMKEYTYPE(Translation)

		// Description:
		// Definition for 3 element scale vector.
		PHYRE_EXTERN_ANIMKEYTYPE(Scale)

		// Description:
		// Definition for 4 element shader instance parameter.
		PHYRE_EXTERN_ANIMKEYTYPE(ShaderParameterF4)

		// Description:
		// Definition for 3 element shader instance parameter.
		PHYRE_EXTERN_ANIMKEYTYPE(ShaderParameterF3)

		// Description:
		// Definition for 2 element shader instance parameter.
		PHYRE_EXTERN_ANIMKEYTYPE(ShaderParameterF2)

		// Description:
		// Definition for 1 element shader instance parameter.
		PHYRE_EXTERN_ANIMKEYTYPE(ShaderParameterF1)

		// Description:
		// Definition for 4 element light color.
		PHYRE_EXTERN_ANIMKEYTYPE(LightColor)

		// Description:
		// Definition for 1 element light intensity.
		PHYRE_EXTERN_ANIMKEYTYPE(LightIntensity)

		// Description:
		// Definition for 2 element light falloff and penumbra.
		PHYRE_EXTERN_ANIMKEYTYPE(LightFalloffAndPenumbra)

		// Description:
		// Definition for 1 element camera vertical field of view.
		PHYRE_EXTERN_ANIMKEYTYPE(CameraFov)

		// Description:
		// Definition for 1 element camera near clip plane.
		PHYRE_EXTERN_ANIMKEYTYPE(CameraZNear)

		// Description:
		// Definition for 1 element camera far clip plane.
		PHYRE_EXTERN_ANIMKEYTYPE(CameraZFar)

		// Description:
		// Definition for 1 element orthographic camera size.
		PHYRE_EXTERN_ANIMKEYTYPE(CameraOrthographicSize)

		// Description:
		// Definition for morph modifier weight.
		PHYRE_EXTERN_ANIMKEYTYPE(MorphTargetWeight)

		// Description:
		// Definition for bool user attribute.
		PHYRE_EXTERN_ANIMKEYTYPE(UserAttributeBool)

		// Description:
		// Definition for PInt32 user attribute.
		PHYRE_EXTERN_ANIMKEYTYPE(UserAttributeInt)

		// Description:
		// Definition for float user attribute.
		PHYRE_EXTERN_ANIMKEYTYPE(UserAttributeFloat)

		// Description:
		// Definition for vector user attribute.
		PHYRE_EXTERN_ANIMKEYTYPE(UserAttributeVector)

	} //! End of PAnimation namespace
} //! End of Phyre namespace

PHYRE_DECLARE_TYPE_FOR_NAMED_SEMANTIC(Phyre::PAnimation, PAnimationKeyDataType)

#endif //! PHYRE_ANIMATION_KEY_DATA_TYPE_H
