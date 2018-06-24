#include <iostream>
#include <string>

#include "argument-management\ArgumentParser.h"
#include "argument-management\OutputFormater.h"

#include "inputsender\Input\InputSender.h"
#include "inputsender\Window\WindowFinder.h"

#define SUCCESS 0
#define ARGUMENT_ERROR 1
#define WINDOW_NOT_FOUND 2
#define INVALID_INPUT 3

int main(int argc, char** argv) {

  //No arguments (argv as always the exe name in first place)
  if(argc == 1) {

    inputsender::WindowFinder::setFilter(
        [](inputsender::Window w) {
          std::string title;
          inputsender::WindowInfo::getWindowTitle(w, title);

          return inputsender::WindowInfo::isWindowVisible(w) && title !=  "";
        }
    );
    auto wnds = inputsender::WindowFinder::getWindows();

    OutputFormater::output(wnds);
  }
  else {

    Argument args;
    int parseResult = ArgumentParser::parseArgument(argc, argv, args);

    if(parseResult == NO_PARSE_ERROR) {

      //No target
      if(!args.isGlobal         && 
          args.windowName == "" && 
          args.windowId == 0) {

        return ARGUMENT_ERROR;

      }

      //No inputs
      if(!args.isAlt     && 
         !args.isControl &&
         !args.isSystem  &&
          args.keys.size() == 0) {

        return ARGUMENT_ERROR;

      }

      if(args.isControl) {
        inputsender::InputSender::GlobalInput(KEY_LCONTROL, inputsender::KeyState::PRESS);
      }

      if (args.isSystem) {
        inputsender::InputSender::GlobalInput(KEY_SYS, inputsender::KeyState::PRESS);
      }

      if (args.isAlt) {
        inputsender::InputSender::GlobalInput(KEY_ALT, inputsender::KeyState::PRESS);
      }




      //TODO : System and ALT key
      
      if(args.isGlobal && args.keys.size() > 0) {
        inputsender::InputSender::GlobalInputs(&args.keys[0], args.keys.size(), inputsender::KeyState::PRESS);
        inputsender::InputSender::GlobalInputs(&args.keys[0], args.keys.size(), inputsender::KeyState::RELEASE);
      }
      else {
        //Find windows
        inputsender::WindowFinder::setFilter(
           [&](inputsender::Window w) -> bool {

             if(!inputsender::WindowInfo::isWindowVisible(w)) {
               return false;
             }

             std::string title;
             inputsender::WindowInfo::getWindowTitle(w, title);

             //Can be compacted but would be not easily understanable

             //Filter by name ?
             if(args.windowName != "") {

               //Names match ?
               if(args.windowName == title) {
                 //Check for IDs
                 if(args.windowId == 0) {
                   return true;
                 }
                 else {
                   return args.windowId == inputsender::WindowInfo::getWindowId(w);
                 }                 
               }

               return false;
             }

             //We already know that args.windowId is non null
             return args.windowId == inputsender::WindowInfo::getWindowId(w);
           }
        );

        auto wnds = inputsender::WindowFinder::getWindows();

        if(wnds.size() == 0) {
          std::cerr << "No window found" << std::endl;
          return WINDOW_NOT_FOUND;
        }
        else if(args.keys.size() > 0) {
          for(auto& w : wnds) {
            inputsender::InputSender::TargetInputs(w, &args.keys[0], args.keys.size(), inputsender::KeyState::PRESS);
            inputsender::InputSender::TargetInputs(w, &args.keys[0], args.keys.size(), inputsender::KeyState::RELEASE);
          }
        }

      }

      if(args.isControl) {
        inputsender::InputSender::GlobalInput(KEY_LCONTROL, inputsender::KeyState::RELEASE);
      }

      if (args.isSystem) {
        inputsender::InputSender::GlobalInput(KEY_SYS, inputsender::KeyState::RELEASE);
      }

      if (args.isAlt) {
        inputsender::InputSender::GlobalInput(KEY_ALT, inputsender::KeyState::RELEASE);
      }
    } 
    else {
      
      if(parseResult & UNKNOWN_INPUT) {

        return INVALID_INPUT;

      }
      else {

        return ARGUMENT_ERROR;

      }

    }
  }

	std::cin.get();
	return SUCCESS;
}