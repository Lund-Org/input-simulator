#pragma once

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

	#include "..\Impl\Win32\Window\WindowFinderImpl.h"

#endif

#include "Window.h"

namespace inputsender {

	/**
	 *\brief Class that lists all windows
	 */
	class WindowFinder {

	public:
		/** 
		 *\brief Change the function that filters window (ie window that you may not want)
		 *
		 *Note that this class is not thread safe, calling this function while WindowFinder::getWindows is running
		 *may result in weird and unwanted behavior.
		 *
		 *Please see WindowInfo class that provides function that may be usefull such as WindowInfo::isVisible or WindowInfo::getTitle.
		 *
		 *\param [in] filter A function pointer. This function must return True if the window should be in the returned list and false otherwise.
		 */
		static void setFilter (std::function<bool (Window)> filter);

		/**
		 *\brief Lists top level windows
		 *
		 *\return A list of windows that 'passed' the 'filter' test.
		 */
		static std::vector<Window> getWindows ();
	};
}