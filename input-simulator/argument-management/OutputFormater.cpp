#include "OutputFormater.h"

void OutputFormater::output (const std::vector<inputsender::Window> windows)
{
  std::cout << "[";
    
#if defined(READABLE_JS)
      std::cout << "\n";
#endif

    for(unsigned int i = 0; i < windows.size(); ++i) {

#if defined(READABLE_JS)
      std::cout << "  ";
#endif

      std::cout << "{";

        std::string title;
        inputsender::WindowInfo::getWindowTitle(windows[i], title);
        
          
#if defined(READABLE_JS)
      std::cout << "\n";
#endif

#if defined(READABLE_JS)
      std::cout << "    ";
#endif

        std::cout << WINDOW_TITLE_JSON_OUTPUT_KEY << ":" << "\"" << title << "\"";

        std::cout << ",";

#if defined(READABLE_JS)
      std::cout << "\n";
#endif

#if defined(READABLE_JS)
      std::cout << "    ";
#endif

        std::cout << WINDOW_ID_JSON_OUTPUT_KEY << ":" << inputsender::WindowInfo::getId(windows[i]);

#if defined(READABLE_JS)
      std::cout << "\n";
#endif

#if defined(READABLE_JS)
      std::cout << "  ";
#endif
      std::cout << "}";

      if(i != windows.size() - 1) {
        std::cout << ",";
      }

#if defined(READABLE_JS)
      std::cout << std::endl; //Let's flush 
#endif

    }

  std::cout << "]";
}