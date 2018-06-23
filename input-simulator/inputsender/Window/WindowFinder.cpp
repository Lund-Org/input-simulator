#include "WindowFinder.h"

namespace inputsender {

	void WindowFinder::setFilter (std::function<bool(Window)> filter) {
		priv::WindowFinderImpl::setFilter(
			[=](priv::WindowImpl windowImpl) {
				//Convert platform-dependent type to its generic representation
				Window wnd;
				wnd.m_windowImpl = windowImpl;

				return filter(wnd);
			}
		);
	}

	std::vector<Window> WindowFinder::getWindows () {
		std::vector<Window> windows;
		auto wnds = priv::WindowFinderImpl::getWindows();
	
		//Convert platform-dependent types to their generic representations
		for(auto& w : wnds) {
			Window tmp;
			tmp.m_windowImpl = w;

			windows.push_back(tmp);
		}

		return windows;
	}
}