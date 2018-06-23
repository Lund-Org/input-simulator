#pragma once

#include <string>
#include <vector>

/**
 *\brief Encapsulates all possible inputs given
 */
struct Argument {

  /**
   *\brief Construcs empty argument
   */
  Argument ();

  //Targetting data

  /** The name of the window **/
  std::string windowName;
  /** The id of the window**/
  int windowId;
   
  /** 
   *Should input be global or targetted ? Note that if this field is set to true,
   *windowName and windowId are ignore even if these are valid parameters.
   *
   *Also, this field only affect inputs in keys field.
   */
  bool isGlobal;


  //Inputs data

  /** Should the control key be pressed ?**/
  bool isControl;
  /** Should the alt key be pressed ?**/
  bool isAlt;
  /** Should the system (Windows or Mac) key be pressed ?**/
  bool isSystem;
    
  /** List of key to press **/
  std::vector<int> keys;
};