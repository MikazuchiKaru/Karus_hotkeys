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

        if (!RegisterHotKey(NULL, i, combinedModifiers, macros[i].hotkey)) {
            std::cerr << "Failed to register hotkey!" << i << std::endl;
            return 1;
        }
    }
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        for(int i = 0; i < macros.size(); i++)
        {   
            if(msg.message == WM_HOTKEY && msg.wParam == i)
            {
                exe(macros[i]);
            }
        }
    }
    // Unregister all hotkeys before exiting
    for(int i = 0; i < macros.size(); i++)
    {
        UnregisterHotKey(NULL, i);
    }
    UnregisterHotKey(NULL, 0);

    return 0;
}