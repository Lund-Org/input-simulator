#include <iostream>
#include <string>

#include "..\Window\WindowFinder.h"
#include "..\Window\WindowInfo.h"

#include "..\Input\InputSender.h"

using namespace inputsender;

////////////////////////////////////////////////////////////////
//                                                            //
//Exemple that demonstrates how to use the API                //
//                                                            //
//This exemple looks for all Mozilla Firefox windows and      //
//close one tab on EACH window. 							  //
//Be carefull, this may loose you some tab you would have     //
//kept open.                                                  //
// 								                              //
//(ie presses : (Ctrl + F4)).                                 //
//                                                            //
////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {

	//Sets filter to find mozilla windows
	WindowFinder::setFilter(
		[](Window wnd) {
			if(WindowInfo::isWindowVisible(wnd)) {

				std::string title;
				if(WindowInfo::getWindowTitle(wnd, title)) {

					//Each windows finishes with 'Mozilla Firefox'
					//This is not the best filter in the world but it will do the trick
					return title.find("Mozilla Firefox") != std::string::npos;
				}

				//The window is not interesting
				return false;
			}
			
			//The window is not interesting
			return false;
		}
	);

	//Send global input for control key
	//Firefox only accept this one for control presses
	InputSender::GlobalInput(KEY_LCONTROL, KeyState::PRESS);

	//Lists all windows that match with the filter given earlier
	auto wnd = WindowFinder::getWindows();
	for(auto& w : wnd) {

		//Send F4 key directly to the window, note that CTRL key is still pressed
		//at this moment
		InputSender::TargetInput(w, KEY_F4, KeyState::PRESS_RELEASE);
	}

	//Release controls key, if you ever forget to do this, you won't be able
	//to use text editors anymore (the operating system thinks you didn't release
	//the key). If this ever happens, just press manually the control key, this 
	//will trigger the release state for the control key.
	InputSender::GlobalInput(KEY_LCONTROL, KeyState::RELEASE);

	std::cin.get();
	return EXIT_SUCCESS;
}