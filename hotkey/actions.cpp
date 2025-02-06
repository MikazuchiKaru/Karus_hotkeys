#include "resources.h"
#include <stdlib.h>

void exe(macro mymacro)
{
    for(auto action : mymacro.actions)
    {
        if(action.command == "execute")
        {
            ShellExecuteA(0, "open", action.attribute.c_str(), 0, 0, SW_SHOW);
        }
        if(action.command == "wait")
        {
            Sleep(std::stoi(action.attribute));
        }
    }
}