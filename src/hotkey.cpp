#include "resources.h"
#include "actions.cpp"

int hotkeycheck(std::vector<macro> macros)
{
    for(int i = 0; i < macros.size(); i++)
    {
        UINT combinedModifiers = 0;
        for (UINT modifier : macros[i].modifiers) {
            combinedModifiers |= modifier;  //combines the modifiers into one
        }

        if (!RegisterHotKey(NULL, i, combinedModifiers, macros[i].hotkey)) {    //returns 0 if error occurs
            std::cerr << "Failed to register hotkey!" << i << std::endl;
            return 1;
        }
    }
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))    //it checks for messages until it receives a quit message
    {
        for(int i = 0; i < macros.size(); i++)
        {   
            if(msg.message == WM_HOTKEY && msg.wParam == i)
            {
                exe(macros[i]);
            }
        }
    }
    for(int i = 0; i < macros.size(); i++)
    {
        UnregisterHotKey(NULL, i);  //important for proper shutdown
    }
    return 0;
}