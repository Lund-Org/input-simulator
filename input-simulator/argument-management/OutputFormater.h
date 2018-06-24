#pragma once

#include <vector>
#include <string>

#include "../inputsender/Window/WindowInfo.h"

#define WINDOW_TITLE_JSON_OUTPUT_KEY "title"
#define WINDOW_ID_JSON_OUTPUT_KEY "id"

//Debug purposes only
#define READABLE_JS

/**
 *\brief Class that outputs data to stdout
 */
class OutputFormater
{
public:
  /**
   *\brief Writes windows data to stdout stream
   *
   *The format is in JSON and follows the pattens (without spaces nor newlines):
   *[
   * {
   *   title="xxx",
   *   id=1234
   * },
   * {
   *   title="zzz",
   *   id=5678
   * }
   *]
   */
  static void output (const std::vector<inputsender::Window> windows);
};

