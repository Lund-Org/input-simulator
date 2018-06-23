#pragma once

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

	#include "..\Impl\Win32\Window\WindowImpl.h"

#endif

namespace inputsender {
	
	/** 
	 *\brief Encapsulate all necessary data for a Window
	 */
	class Window {

		friend class InputSender;

		friend class WindowFinder;
		friend class WindowInfo;

		/**
		 *\brief OS-defined windows
		 *
		 *The actual type of this memeber changes depending on the OS (through #if defined(...) above)
		 */
		priv::WindowImpl m_windowImpl;
	};
}