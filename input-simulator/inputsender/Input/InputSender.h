#pragma once

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

	#include "../Impl/Win32/Input/InputSenderImpl.h"

#endif

#include "../Window/Window.h"
#include "Keys.h"

namespace inputsender {

	class InputSender {

	public:	
		/**
		 *\brief Simulate an input at a system level
		 *
		 *\param [in] inputCode virtual keyCode of the input to be simulated
		 *\param [in] state how the key should be simulated
		 */
		static void GlobalInput(int inputCode, KeyState state);
		/**
		 *\brief Simulate multiples inputs at a system level
		 *
		 *\param [in] inputsCode virtual keyCode of each input to be simulated
		 *\param [in] numInputs number of inputs to be simulated
		 *\param [in] state how the keys should be simulated
		 */
		static void GlobalInputs(int* inputsCode, size_t numInputs, KeyState state);

		/**
		 *\brief Simulate multiples inputs at a system level
		 *
		 *\param [in] inputsCode virtual keyCode of each input to be simulated
		 *\param [in] numInputs number of inputs to be simulated
		 *\param [in] state how the keys should be simulated
		 */
		static void TargetInput(Window dest, int inputCode, KeyState state);
		/**
		 *\brief Simulate multiples inputs at a window level
		 *
		*\param [in] dest the window at which event should be 'thrown'
		 *\param [in] inputsCode virtual keyCode of each input to be simulated
		 *\param [in] numInputs number of inputs to be simulated
		 *\param [in] state how the keys should be simulated
		 */
		static void TargetInputs(Window dest, int* inputsCode, size_t numInputs, KeyState state);
	};

}