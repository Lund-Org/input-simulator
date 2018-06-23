#pragma once

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
	
	#include "..\Impl\Win32\Window\WindowInfoImpl.h"

#endif

#include "Window.h"

namespace inputsender {

	/** 
	 *\brief Windows implementation to get information about a window
	 *
	 *Most functions return a boolean meant to indicate weather the information are valid or not.
	 *
	 *However, please note that, in Windows operating system,
	 *windows may be invalid (ie windows close) or reused (ie pointing to another window or to another object). 
	 *
	 *As a result, function may return true but the information may not be the one the user is expecting to get.
	 */
	class WindowInfo {

	public:
		/**
		 *\brief Returns the parent window
		 *
		 *\param [in] window The window we want the parent from
		 *\param [out] parentWindow The parent of the window if it exists
		 *
		 *\return True if the window has a parent, False otherwise
		 */
		static bool getParentWindow (Window window, Window& parentWindow);

		/** 
		 *\brief Returns the title of the window
		 *
		 *\param [in]  window The window we want the title from
		 *\param [out] title The title of the window
		 *
		 *\return True if the title has at least one letter, false otherwise.
		 */
		static bool getWindowTitle (Window window, std::string& title);

		/** 
		 *\brief Returns if the window is visible
		 *
		 *\param [in] window The window we want to know the visibility from
		 *
		 *\return True if the window is visible, false otherwise
		 */
		static bool isWindowVisible (Window window);
	
    /**
     *\brief Returns an unique id for the window
     *
     *\param [in] window The window we want the id of.
     *
     *\return The id of the window, 0 if no id can be provided.
     */
    static int getId (Window window);
  };
}