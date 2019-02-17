/* SCE CONFIDENTIAL
PhyreEngine(TM) Package 3.1.5.0
* Copyright (C) 2011 Sony Computer Entertainment Inc.
* All Rights Reserved.
*/

#ifndef PHYRE_UTILITY_ANIMATION_H
#define PHYRE_UTILITY_ANIMATION_H

// Description:
// Namespace for Phyre classes and functions.
namespace Phyre
{
	namespace PAnimation
	{
		// Description:
		// The PUtilityAnimation class represents the initialization object for the Phyre animation module.
		class PUtilityAnimation : public PUtility
		{
		private:
			virtual PResult initialize();
			virtual PResult terminate();

		public:
			PUtilityAnimation();
			virtual ~PUtilityAnimation();
		};

		// Description:
		// The instance of the PUtilityAnimation class for registration.
		extern PUtilityAnimation s_utilityAnimation;

	} //! End of PAnimation namespace
} //! End of Phyre Namespace

#endif //! PHYRE_UTILITY_ANIMATION_H
