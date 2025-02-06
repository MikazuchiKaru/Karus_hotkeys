#include "resources.h"
#include "hotkey.cpp"
#include "parser.cpp"
#include "actions.cpp"


int main()
{
    macro mymacro = parse("macro.txt");
    if (!hotkeycheck(mymacro)) exe(mymacro);
    return 0;
}