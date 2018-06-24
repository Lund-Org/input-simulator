#include "ArgumentParser.h"

int ArgumentParser::parseArgument (int argc, char** argv, Argument& result) {

  int return_v = NO_PARSE_ERROR;

  for(int i = 1; i < argc; ++i) {
  
    std::string arg = argv[i];
    unsigned int findPos = 0;

    if(arg.find(WINDOW_NAME) == 0) {

      std::string name = arg.substr(std::strlen(WINDOW_NAME));

      if(name.size() >= 2) {

        name.erase(name.begin());   //Remove "
        name.erase(name.end() - 1); //Remove "

        result.windowName = name;
      }
      else {
        std::cerr << "Invalid argument: " << arg << std::endl;
        return_v |= MALFORMATED_WINDOW_NAME;
      }
    }
    else if(arg.find(WINDOW_ID) == 0) {

      std::string stringId = arg.substr(std::strlen(WINDOW_ID));

      try {
        int id = std::stoi(stringId);
        result.windowId = id;
      }
      catch(std::exception e) {
        std::cerr << "Error while parsing : \"" << arg << "\", extracted : \"" << stringId << "\"" << std::endl;
        std::cerr << e.what() << std::endl;

        return_v |= MALFORMATED_WINDOW_ID;
      }

    }
    else if(arg.find(INPUTS) == 0) { 
    
      std::string inputs = arg.substr(std::strlen(INPUTS));

      if(inputs.size() >= 2) {

        inputs.erase(inputs.begin());   //Remove "
        inputs.erase(inputs.end() - 1); //Remove "
        
        std::vector<int> keys;
        
        if(!parseInput(inputs, keys)) {
          std::cerr << "Some inputs are not valids: " << inputs << std::endl;
          return_v |= UNKNOWN_INPUT;
        }
        
        result.keys = keys;
      }
      else {
        std::cerr << "Invalid argument: " << arg << std::endl;
        return_v |= MALFORMATED_INPUTS;
      }
    }
    else if(arg.find(CTRL) == 0) {
      result.isControl = true;
    }
    else if(arg.find(ALT) == 0) { 
      result.isAlt = true;
    }
    else if(arg.find(SYS) == 0) {
      result.isSystem = true;
    }
    else if(arg.find(GLOBAL) == 0) {
      result.isGlobal = true;
    }
    else { 

      std::cerr << "Unknown argument: " << arg << std::endl;

      return_v |= UNKNOWN_ARGUMENT;
    }
  }

  return return_v;
}

int ArgumentParser::parseInput (const std::string& inputs, std::vector<int>& keys)
{
  int return_v = 1;

  //Splitting by backspace can be easily done with streams
  std::istringstream iss(inputs + " ");
  std::vector<std::string> inputs_keys;

  std::copy(std::istream_iterator<std::string>(iss), 
            std::istream_iterator<std::string>(),
            std::back_inserter(inputs_keys));

  for(auto& ikey : inputs_keys) {

    int key = inputsender::getVSCode(ikey);

    if(key != 0) {
      keys.emplace_back(key);
    }
    else {
      std::cerr << "Unknown key: " << ikey << std::endl;

      return_v = 0;
    }
  }

  return return_v;
}