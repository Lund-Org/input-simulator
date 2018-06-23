#include "InputSenderImpl.h"

#include <iostream>

namespace inputsender { namespace priv {

	void InputSenderImpl::GlobalInput (int inputCode, KeyState state) {
		INPUT ip;
		ZeroMemory(&ip, sizeof(INPUT));
	
		ip.type = INPUT_KEYBOARD;
	
		ip.ki.time = 0;
		ip.ki.wVk  = inputCode;
		ip.ki.dwFlags = 0;
		ip.ki.wScan = 0;

		if(state == KeyState::PRESS || state == KeyState::PRESS_RELEASE) {
			SendInput(1, &ip, sizeof(INPUT));
		}

		if(state == KeyState::RELEASE || state == KeyState::PRESS_RELEASE) {
			ip.ki.dwFlags |= KEYEVENTF_KEYUP;

			SendInput(1, &ip, sizeof(INPUT));		
		}
	}
	
	void InputSenderImpl::GlobalInputs (int* inputsCode, size_t numInputs, KeyState state) {
#if defined(SEND_INPUT_ARRAY_MODE)
		INPUT* ips = new INPUT[numInputs];
		ZeroMemory(ips, numInputs * sizeof(INPUT));

		for(unsigned int i = 0; i < numInputs; ++i) {
			ips[i].type = INPUT_KEYBOARD;
			
			ips[i].ki.time = 0;
			ips[i].ki.wVk  = inputsCode[i];
			ips[i].ki.dwFlags = 0;
			ips[i].ki.wScan = 0;
		}

		if(state == KeyState::PRESS || state == KeyState::PRESS_RELEASE) {
			SendInput(1, ips, sizeof(INPUT));
		}

		if(state == KeyState::RELEASE || state == KeyState::PRESS_RELEASE) {
			for(unsigned int i = 0; i < numInputs; ++i) {
				ips[i].ki.dwFlags |= KEYEVENTF_KEYUP;
			}

			SendInput(1, ips, sizeof(INPUT));		
		}

		delete[] ips;
#else
		for(unsigned int i = 0; i < numInputs; ++i) {
			GlobalInput(inputsCode[i], state);
		}
#endif
	}

	void InputSenderImpl::TargetInput (WindowImpl dest, int inputCode, KeyState state) {
		if(state == KeyState::PRESS || state == KeyState::PRESS_RELEASE) {
			SendMessage(dest.window, WM_KEYDOWN, inputCode, 0);
		}

		if(state == KeyState::RELEASE || state == KeyState::PRESS_RELEASE) {
			SendMessage(dest.window, WM_KEYUP, inputCode, 0);
		}
	}

	void InputSenderImpl::TargetInputs (WindowImpl dest, int* inputsCode, size_t numInputs, KeyState state) {
		for(unsigned int i = 0; i < numInputs; ++i) {
			TargetInput(dest, inputsCode[i], state);
		}
	}

} }