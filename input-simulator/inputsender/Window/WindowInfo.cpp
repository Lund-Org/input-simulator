#include "WindowInfo.h"

namespace inputsender {

	bool WindowInfo::getParentWindow (Window window, Window& parentWindow) {
		return priv::WindowInfoImpl::getParentWindow(window.m_windowImpl, parentWindow.m_windowImpl);
	}

	bool WindowInfo::getWindowTitle (Window window, std::string& title) {
		return priv::WindowInfoImpl::getWindowTitle(window.m_windowImpl, title);
	}

	bool WindowInfo::isWindowVisible (Window window) {
		return priv::WindowInfoImpl::isWindowVisible(window.m_windowImpl);
	}

  int WindowInfo::getId (Window window) {
    return priv::WindowInfoImpl::getId(window.m_windowImpl);
  }
}