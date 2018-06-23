#include "InputSender.h"

namespace inputsender {

	void InputSender::GlobalInput(int inputCode, KeyState state)
	{
		return priv::InputSenderImpl::GlobalInput(inputCode, state);
	}

	void InputSender::GlobalInputs(int* inputsCode, size_t numInputs, KeyState state)
	{
		return priv::InputSenderImpl::GlobalInputs(inputsCode, numInputs, state);
	}

	void InputSender::TargetInput(Window dest, int inputCode, KeyState state)
	{
		return priv::InputSenderImpl::TargetInput(dest.m_windowImpl, inputCode, state);
	}

	void InputSender::TargetInputs(Window dest, int* inputsCode, size_t numInputs, KeyState state)
	{
		return priv::InputSenderImpl::TargetInputs(dest.m_windowImpl, inputsCode, numInputs, state);
	}
}