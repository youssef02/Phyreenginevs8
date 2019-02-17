/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_ANIMATION_KEY_DATA_TYPE_INL
#define PHYRE_ANIMATION_KEY_DATA_TYPE_INL

namespace Phyre
{
	namespace PAnimation
	{

#ifndef __SPU__

		// Description:
		// The constructor for the PAnimationKeyDataType class. The type can not be used in Phyre until it is registered with registerAnimationKeyDataType().
		// Arguments:
		// name :   Name of the PAnimationKeyDataType.
		// width :  Width of the animation key (in floats).
		PAnimationKeyDataType::PAnimationKeyDataType(const PChar * name, PUInt32 width)
			: PNamedSemantic<class PAnimationKeyDataType>(name)
		{
			PHYRE_ASSERTMSG(width, "Constructing a PAnimationKeyDataType with no size");
			PHYRE_ASSERTMSG((width <= 4), "Constructing a PAnimationKeyDataType with a width too great (4 is the limit)\n");

			m_width = width;
			m_index = s_typeIndex++;		// Assign an index for hashing
		}

		// Description:
		// The destructor for the PAnimationKeyDataType class.
		PAnimationKeyDataType::~PAnimationKeyDataType()
		{
		}

		// Gets m_width.
		PUInt32 PAnimationKeyDataType::getWidth() const
		{
			return m_width;
		}

		// Gets m_index.
		PUInt32 PAnimationKeyDataType::getIndex() const
		{
			return m_index;
		}

		// Description:
		// Gets the animation key data type index.
		// Returns:
		// The animation key data type index.
		PUInt32 PAnimationKeyDataType::GetAnimKeyTypeCount()
		{
			return s_typeIndex;
		}

#endif //! __SPU__

	} //! End of PAnimation namespace
} //! End of Phyre namespace

#endif //! PHYRE_ANIMATION_KEY_DATA_TYPE_INL
