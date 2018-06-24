#pragma once

#include <algorithm>
#include <string>
#include <map>

#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)

	#include "../Impl/Win32/Input/KeysImpl.h"

#endif


namespace inputsender {

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
inline int geKeyCodeFromName (const std::string& code) {

  const std::map<std::string, int> keycodes{
    { "f1", KEY_F1 },
    { "f2", KEY_F2 },
    { "f3", KEY_F3 },
    { "f4", KEY_F4 },
    { "f5", KEY_F5 },
    { "f6", KEY_F6 },
    { "f7", KEY_F7 },
    { "f8", KEY_F8 },
    { "f9", KEY_F9 },
    { "f10", KEY_F10 },
    { "f11", KEY_F11 },
    { "f12", KEY_F12 },
    { "0", KEY_0 },
    { "1", KEY_1 },
    { "2", KEY_2 },
    { "3", KEY_3 },
    { "4", KEY_4 },
    { "5", KEY_5 },
    { "6", KEY_6 },
    { "7", KEY_7 },
    { "8", KEY_8 },
    { "9", KEY_9 },
    { "a", KEY_A },
    { "b", KEY_B },
    { "c", KEY_C },
    { "d", KEY_D },
    { "e", KEY_E },
    { "f", KEY_F },
    { "g", KEY_G },
    { "h", KEY_H },
    { "i", KEY_I },
    { "j", KEY_J },
    { "k", KEY_K },
    { "l", KEY_L },
    { "m", KEY_M },
    { "n", KEY_N },
    { "o", KEY_O },
    { "p", KEY_P },
    { "q", KEY_Q },
    { "r", KEY_R },
    { "s", KEY_S },
    { "t", KEY_T },
    { "u", KEY_U },
    { "v", KEY_V },
    { "w", KEY_W },
    { "x", KEY_X },
    { "y", KEY_Y },
    { "z", KEY_Z },
  };

  std::string tcode{ code };
  std::transform(code.begin(), code.end(), tcode.begin(), ::tolower);

  if (keycodes.find(tcode) != keycodes.end())
  {
    return keycodes.at(tcode);
  }

  return 0;
}



}