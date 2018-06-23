#pragma once

#include <algorithm>
#include <string>

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

	#include "../Impl/Win32/Input/KeysImpl.h"

#endif

/**
 *\brief Map a key to its corresponding keycode
 *
 *The lenght of code can not exceed 3 characters.
 *If the lenght of code is 2 (or three) the function expect it to be one of F1 to F12 keys.
 *
 *Only letters and digit are handle for one character length code.
 *
 *In any other case, this function will return 0 as a NO-translation code.
 *
 *\param [in] code The key to convert
 *
 *\return Either the keycode or 0 if there is no translation
 */
inline int getVSCode(const std::string& code)
{
  if(code.size() > 3) {
    return 0;
  }
  
  std::string tcode = code;

  std::transform(code.begin(), code.end(), tcode.begin(), ::tolower);

  if (tcode.find("f") == 0 && code.size() >= 2) {
    tcode = tcode.substr(1);

    try {
      int fcode = std::stoi(tcode);

      switch (fcode)
      {
      case 1:
        return KEY_F1;
      case 2:
        return KEY_F2;
      case 3:
        return KEY_F3;
      case 4:
        return KEY_F4;
      case 5:
        return KEY_F5;
      case 6:
        return KEY_F6;
      case 7:
        return KEY_F7;
      case 8:
        return KEY_F8;
      case 9:
        return KEY_F9;
      case 10:
        return KEY_F10;
      case 11:
        return KEY_F11;
      case 12:
        return KEY_F12;
      default:
        return 0;
      }
    }
    catch(std::exception e) {
      return 0;
    }
  }

  if(tcode.size() == 1)
  {
    switch (tcode[0])
    {
    case '0':
      return KEY_0;
    case '1':
      return KEY_1;
    case '2':
      return KEY_2;
    case '3':
      return KEY_3;
    case '4':
      return KEY_4;
    case '5':
      return KEY_5;
    case '6':
      return KEY_6;
    case '7':
      return KEY_7;
    case '8':
      return KEY_8;
    case '9':
      return KEY_9;
    case 'a':
      return KEY_A;
    case 'b':
      return KEY_B;
    case 'c':
      return KEY_C;
    case 'd':
      return KEY_D;
    case 'e':
      return KEY_E;
    case 'f':
      return KEY_F;
    case 'g':
      return KEY_G;
    case 'h':
      return KEY_H;
    case 'i':
      return KEY_I;
    case 'j':
      return KEY_J;
    case 'k':
      return KEY_K;
    case 'l':
      return KEY_L;
    case 'm':
      return KEY_M;
    case 'n':
      return KEY_N;
    case 'o':
      return KEY_O;
    case 'p':
      return KEY_P;
    case 'q':
      return KEY_Q;
    case 'r':
      return KEY_R;
    case 's':
      return KEY_S;
    case 't':
      return KEY_T;
    case 'u':
      return KEY_U;
    case 'v':
      return KEY_V;
    case 'w':
      return KEY_W;
    case 'x':
      return KEY_X;
    case 'y':
      return KEY_Y;
    case 'z':
      return KEY_Z;
    default:
      return 0;
    }
  }

  return 0;
}