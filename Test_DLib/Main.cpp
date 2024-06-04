#include <iostream>
#include <string>
#include <Windows.h>

typedef bool (*CheckCharsFunc)(const char*, const char*);
using namespace std;
int main() {
    
    cout << "Enter a string: ";
    string str;
    getline(cin, str);

    cout << "Enter characters to search for: ";
    string chars;
    getline(cin, chars);

    HMODULE hLib = LoadLibraryA("path_to_your_dll.dll");
    if (hLib == NULL) {
        cerr << "Failed to load library." << endl;
        return 1;
    }

    CheckCharsFunc func = (CheckCharsFunc)GetProcAddress(hLib, "CheckChars");
    if (func == NULL) {
        cerr << "Failed to get function address." << endl;
        FreeLibrary(hLib);
        return 1;
    }

    bool result = func(str.c_str(), chars.c_str());

    cout << "All characters found: " << (result ? "true" : "false") << endl;

    FreeLibrary(hLib);

    return 0;
}