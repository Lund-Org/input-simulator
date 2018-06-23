#pragma once

#include <vector>
#include <functional>

#include <Windows.h>

#include "WindowImpl.h"

namespace inputsender { namespace priv {

	/**
	 *\brief Windows-defined implementation that lists all windows
	 */
	class WindowFinderImpl {

	public:
		/** 
		 *\brief Change the function that filters window (ie window that you may not want)
		 *
		 *Note that this class is not thread safe, calling this function while WindowFinderImpl::getWindows is running
		 *may result in weird and unwanted behavior.
		 *
		 *Please see WindowInfoImpl class that provides function that may be usefull such as WindowInfoImpl::isVisible or WindowInfoImpl::getTitle.
		 *
		 *\param [in] filter A function pointer. This function must return True if the window should be in the returned list and false otherwise.
		 */
		static void setFilter (std::function<bool (WindowImpl)> filter);

		/**
		 *\brief Lists top level windows
		 *
		 *\return A list of windows that 'passed' the 'filter' test.
		 */
		static std::vector<WindowImpl> getWindows ();

		/** 
		 *\brief Callback for EnumWindow function
		 *
		 *\param [in] window The newly listed window
		 *\param [in] param A pointer to a std::vector<WindowImpl>
		 *
		 *\return TRUE (which means EnumWindow function will continue until all windows were listed)
		 */
		static BOOL CALLBACK enumWindProc (HWND window, LPARAM param);

		/**
		 *\brief Filter in order to only get interesting windows
		 */
		static std::function<bool (WindowImpl)> m_filter;
	};

} }