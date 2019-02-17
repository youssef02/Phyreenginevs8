/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_CHANNEL_TARGET_H
#define PHYRE_ANIMATION_CHANNEL_TARGET_H

namespace Phyre
{
	//! Forward declarations:
	class PClassDescriptor;

	namespace PRendering
	{
		//! Forward declarations:
		class PMaterial;
		class PEffectVariant;
	} //! End of PRendering namespace

	namespace PAnimation
	{

		//! Forward declarations:
		class PAnimationChannelTarget;

		// Description:
		// An abstraction of target for an animation channel.
		class PAnimationChannelTarget : public PBase
		{
		public:
			// Description:
			// The enumerated type identifying the type of animation target.
			enum PTargetType
			{
				PE_TARGETTYPE_NONE = 0,												// The animation target has no type.
				PE_TARGETTYPE_NAMED_OBJECT,											// The animation target is a named object.
				PE_TARGETTYPE_NAMED_DATAMEMBER,										// The animation target is a named data member.
				PE_TARGETTYPE_NAMED_METHOD,											// The animation target is a named method.
				PE_TARGETTYPE_NAMED_FUNCTION,										// The animation target is a named function.
				PE_TARGETTYPE_NAMED_SHADER_PARAMETER,								// The animation target is a named shader parameter.
				PE_TARGETTYPE_COUNT													// The number of animation target types.
			};

		protected:
			PReferenceAssignable<const PClassDescriptor>	m_instanceObjectType;	// The type of the target instance object (PBase, PNode, PCamera, etc).
			PBase											*m_instanceObject;		// The specific instance of target instance object.
			const PClassDescriptor							*m_baseObjectType;		// The type of the target base object (PBase, PNode, PCamera, etc).
			const PBase										*m_baseObject;			// The specific instance of target base object.

			PTargetType										m_type;					// The type of the animation target (object, data member, method, function, shader parameter, etc).
			PString											m_name;					// The name of the target object.
			PUInt32											m_index;				// The index of the element within the named target (eg, array index).

			//! Case 1 : Named object - identifies a named object of specific type.  The bind operation is responsible for finding it.
			//! Case 2 : Named data member - identified a named member on a specific type.
			//! Case 3 : Named method - identifies a named method on a specific type. Method is void setSomething(const float *value, PUInt32 index);
			//! Case 4 : Named function - identifies a named function on a specific type.  Function is void setSomething(const float *value, PUInt32 index);
			//! Case 5 : Named shader parameter - identifies a named shader parameter on a parameter buffer.
			//!
			//! m_targetType			m_instanceObjectType	m_instanceObject	m_baseObjectType	m_baseObject	m_targetName	m_index
			//!
			//! NAMED_OBJECT			Yes						Optional			Optional			Optional		Yes				No
			//! NAMED_DATAMEMBER		Yes						Optional			Optional			Optional		Yes				Optional (matrix indexing, eg)
			//! NAMED_METHOD			Yes						Optional 			Optional			Optional		Yes				No
			//! NAMED_FUNCTION			Yes						Optional			Optional			Optional		Yes				No
			//! NAMED_SHADER_PARAMETER	PMaterial CD			Optional			PEffectVariant CD	Yes				Yes				Optional (parameter array indexing, eg)
			//!
			//!
			//! Usage examples:
			//!
			//! Targeting mesh instance matrices:
			//! NAMED_DATAMEMBER		PMeshInstance CD		Optional			PMesh CD			Yes				m_currentPose	Matrix index.
			//!
			//! Targeting shader parameters:
			//! NAMED_SHADER_PARAMETER	PMaterial CD			Optional			PEffectVariant CD	Yes				ParamName		Optional (shader parameter array index).
			//!
			//! Targeting camera member:
			//! NAMED_DATAMEMBER		PCameraPerspective CD	Optional			No					No				MemberName		Optional (shader parameter array index).
			//!
			//! Targeting node with nickname:
			//! NAMED_OBJECT			PNode CD				No					No					No				Node nickname	No

			PHYRE_BIND_DECLARE_CLASS(PAnimationChannelTarget, PBase);

			static bool FindClassDescriptorDataMember(const PClassDescriptor &targetCd, const PChar *targetDataMemberName);

		public:
			inline PAnimationChannelTarget();
			inline ~PAnimationChannelTarget();

			const PAnimationChannelTarget &operator =(const PAnimationChannelTarget &other);
			bool operator == (const PAnimationChannelTarget &other) const;

#ifndef __SPU__
			PResult setTargetNamedObject(const PClassDescriptor &cd, const PChar *targetObjectName);

			PResult setTargetNamedDataMember(const PClassDescriptor &cd, PBase *object, const PChar *targetDataMemberName, PUInt32 index);
			PResult setTargetNamedDataMember(const PClassDescriptor &cd, PBase *object, const PClassDescriptor *baseCd, const PBase *baseObject, const PChar *targetDataMemberName, PUInt32 index);

			PResult setTargetNamedMethod(const PClassDescriptor &cd, PBase *object, const PChar *targetMethodName, PUInt32 index);

			PResult setTargetNamedFunction(const PClassDescriptor &cd, PBase *object, const PChar *targetFunctionName, PUInt32 index);

			PResult setTargetNamedShaderParameter(PRendering::PMaterial *material, const PChar *targetParameterName, PUInt32 index);
			PResult setTargetNamedShaderParameter(const PRendering::PEffectVariant *effectVariant, const PChar *targetParameterName, PUInt32 index);
#endif //! __SPU__

			inline PTargetType getTargetType() const;

			inline const PClassDescriptor &getTargetObjectType() const;
			inline PBase *getTargetObject() const;

			inline const PClassDescriptor *getTargetBaseObjectType() const;
			inline const PBase *getTargetBaseObject() const;

			inline const PChar *getTargetName() const;
			inline PUInt32 getTargetIndex() const;
		};

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_CHANNEL_TARGET_H
