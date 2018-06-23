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
   *\return 1 if the argument were successfully parse, 0 otherwise
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

