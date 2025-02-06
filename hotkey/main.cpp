#include "resources.h"
#include "hotkey.cpp"
#include "parser.cpp"


int main()
{
    std::vector<macro> macros = parse("macro.txt");
    if (hotkeycheck(macros)) return 1;
    return 0;
}