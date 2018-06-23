#include "WindowInfoImpl.h"

namespace inputsender { namespace priv {
	
	bool WindowInfoImpl::getParentWindow (WindowImpl window, WindowImpl& parentWindow) {
		//API call
		HWND parent = GetParent(window.window);
		parentWindow.window = parent;

		//NULL means 'no parent'
		return parent != NULL;
	}

	bool WindowInfoImpl::getWindowTitle (WindowImpl window, std::string& title) {
		//Retrieve the length of the title (does not include null terminated character)
		int textLength = GetWindowTextLength(window.window);
		LPSTR buffer  = new CHAR[textLength + 1];

		GetWindowText(window.window, buffer, textLength + 1);

		title = buffer;

		delete[] buffer;

		//May means this is not an actual window
		//In any case, if this function return false, this is not worth using the out value
		return textLength > 0;
	}

	bool WindowInfoImpl::isWindowVisible (WindowImpl window) {
		return IsWindowVisible(window.window);
	}
} }