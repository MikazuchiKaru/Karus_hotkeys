#include "resources.h"


int hotkeycheck(macro mymacro)
{
    if (!RegisterHotKey(NULL, 1, 0, mymacro.hotkey)) {
        std::cerr << "Failed to register hotkey!" << std::endl;
        return 1;
    }
    RegisterHotKey(NULL, 2, 0, VK_F2);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if(msg.message == WM_HOTKEY && msg.wParam == 1)
        {
            return 0;
        }
        if(msg.message == WM_HOTKEY && msg.wParam == 1)
        {
            return 1;
        }
    }
    return 1;
}