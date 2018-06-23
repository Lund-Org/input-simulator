#include "WindowFinderImpl.h"

namespace inputsender { namespace priv {

	//By default, all windows are 'good'
	std::function<bool (WindowImpl)> WindowFinderImpl::m_filter = [](WindowImpl wnd) { return true;  };

	std::vector<WindowImpl> WindowFinderImpl::getWindows () {
		std::vector<WindowImpl> windows;
		EnumWindows(&enumWindProc, reinterpret_cast<LPARAM>(&windows));

		return windows;
	}

	void WindowFinderImpl::setFilter (std::function<bool (WindowImpl)> filter) {
		m_filter = filter;
	}

	BOOL CALLBACK WindowFinderImpl::enumWindProc (HWND window, LPARAM param) {
		std::vector<WindowImpl>* windows = reinterpret_cast<std::vector<WindowImpl>*>(param);

		WindowImpl wrapper;
		wrapper.window = window;

		//Filter windows
		if(m_filter(wrapper) && IsWindow(window))
		{
			windows->push_back(wrapper);
		}

		return TRUE;
	}

}}