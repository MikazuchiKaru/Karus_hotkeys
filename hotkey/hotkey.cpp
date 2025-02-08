#include "resources.h"
#include "actions.cpp"


int hotkeycheck(std::vector<macro> macros)
{
    for(int i = 0; i < macros.size(); i++)
    {
        UINT combinedModifiers = 0;
        for (UINT modifier : macros[i].modifiers) {
            combinedModifiers |= modifier;
        }

        if (!RegisterHotKey(NULL, i+1, combinedModifiers, macros[i].hotkey)) {
            std::cerr << "Failed to register hotkey!" << std::endl;
            return 1;
        }
    }
    RegisterHotKey(NULL, 0, 0, VK_F3);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        for(int i = 0; i < macros.size(); i++)
        {   
            if(msg.message == WM_HOTKEY && msg.wParam == i+1)
            {
                exe(macros[i]);
            }
        }
    }
    return 0;
}