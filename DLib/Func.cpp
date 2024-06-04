#include <string>

extern "C" __declspec(dllexport) bool CheckChars(const char* str, const char* chars) {
    std::string strCopy(str);
    std::string charsCopy(chars);

    for (char c : charsCopy) {
        if (strCopy.find(c) == std::string::npos) {
            return false;
        }
    }

    return true;
}