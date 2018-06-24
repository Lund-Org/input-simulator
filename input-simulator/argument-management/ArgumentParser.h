#pragma once

#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

#include "Argument.h"
#include "../inputsender/Input/Keys.h"

#define WINDOW_NAME "--windowName="
#define WINDOW_ID "--windowId="
#define INPUTS "--input"
#define CTRL "--ctrl"
#define ALT "--alt"
#define SYS "--system"
#define GLOBAL "--global"

//No error
#define NO_ERROR 0x00

//The user provided an input that is not supported (for instance --inputs="foo A B", 'foo' is not a supported input)
#define UNKNOWN_INPUT 0x01
//The user provided an argument that is not supported (for instance --foo)
#define UNKNOWN_ARGUMENT 0x02
//The window name can't be parsed properly (ie not surrounde with '"')
#define MALFORMATED_WINDOW_NAME 0x04
//The windowId is not a number (or can't be parsed as a base 10 integer)
#define MALFORMATED_WINDOW_ID 0x08
//The inputs can't be parsed properly (ie not surrounded with '"')
#define MALFORMATED_INPUTS 0x10

class ArgumentParser {

public:

  /**
   *\brief Parse the argument lists
   *
   *The arguments are meant to be the raw ones passed to the main function. 
   *
   *\param [in] argc The number of element in argv
   *\param [in] argv An array of string
   *\param [out] result The result of the parsing
   *
   *\return 0 if no error were found, a bitwise combinaison of UNKNOWN_INPUT, UNKNOWN_ARGUMENT, MALFORMATED_WINDOW_NAME and MALFORMATED_INPUTS otherwise
   */
  static int parseArgument (int argc, char** argv, Argument& result);
  
private:

  /**
   *\brief Converts 'string keys' to keycodes
   *
   *\param [in] inputs The list of key (space separated) to convert
   *\param [out] keys The result of translations. All key are valid keycode. Invalids keys are ignore and not returned
   *
   *\return 1 if all keys were successfully converted to keycodes 0 otherwise
   */
  static int parseInput (const std::string& inputs, std::vector<int>& keys);
};

