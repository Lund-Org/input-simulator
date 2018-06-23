#pragma once

#include <iostream>
#include "WindowImpl.h"

namespace inputsender { namespace priv {

	/** 
	 *\brief Windows implementation to get information about a window
	 *
	 *Most functions return a boolean meant to indicate weather the information are valid or not.
	 *
	 *However, please note that, as written in Microsoft Documentation,
	 *handle may be invalid (ie windows close) or reused (ie pointing to another window or to another object). 
	 *
	 *As a result, function may return true but the information may not be the one the user is expecting to get.
	 */
	class WindowInfoImpl {

	public:
		/**
		 *\brief Returns the parent window
		 *
		 *\param [in] window The window we want the parent from
		 *\param [out] parentWindow The parent of the window if it exists
		 *
		 *\return True if the window has a parent, False otherwise
		 */
		static bool getParentWindow (WindowImpl window, WindowImpl& parentWindow);
		
		/** 
		 *\brief Returns the title of the window
		 *
		 *\param [in]  window The window we want the title from
		 *\param [out] title The title of the window
		 *
		 *\return True if the title has at least one letter, false otherwise.
		 */
		static bool getWindowTitle (WindowImpl window, std::string& title);

		/** 
		 *\brief Returns if the window is visible
		 *
		 *\param [in] window The window we want to know the visibility from
		 *
		 *\return True if the window is visible, false otherwise
		 */
		static bool isWindowVisible (WindowImpl window);
	};

} }