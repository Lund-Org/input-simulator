#pragma once

#include <Windows.h>

namespace inputsender { namespace priv {
	
	/** 
	 *\brief Encapsulate all necessary data for a Window
	 */
	class WindowImpl {

	private:
		friend class WindowFinderImpl;
		friend class WindowInfoImpl;

		friend class InputSenderImpl;

		/** 
		 *\brief Windows representation of windows
		 *
		 *All that is needed to work with Windows API is a Handle to a Window.
		 */
		HWND window;
	};

}}