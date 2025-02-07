#include "resources.h"
#include "hotkey.cpp"
#include "parser.cpp"


int main()
{
    std::vector<macro> macros = parse("macro.txt");
    if (hotkeycheck(macros)) return 1;
    MessageBoxA(NULL, "app closed successfully", "info", MB_OK);
    return 0;
}