#include "resources.h"
#include <stdlib.h>

void exe(macro mymacro)
{
    for(auto action : mymacro.actions)
    {
        if(action.command == "exit")
        {
            PostQuitMessage(action.attribute == "0" ? 0 : 1);
        }
        else if (action.command == "msgbox")
        {
            MessageBoxA(NULL, (action.attribute.find(',') != std::string::npos) ? action.attribute.substr(0, action.attribute.find(',')).c_str() : action.attribute.c_str(), (action.attribute.find(',') != std::string::npos) ? action.attribute.substr(action.attribute.find(',')+2).c_str() : "info", MB_OK);
        }
        else if(action.command == "send")
        {
            for(auto c : action.attribute)
            {
                INPUT input;
                input.type = INPUT_KEYBOARD;
                input.ki.wVk = VkKeyScanA(c);
                input.ki.dwFlags = 0;
                SendInput(1, &input, sizeof(INPUT));
                input.ki.dwFlags = KEYEVENTF_KEYUP;
                SendInput(1, &input, sizeof(INPUT));
            }
        }
        else if(action.command == "click")
        {
            INPUT input;
            input.type = INPUT_MOUSE;

            if (action.attribute == "left")
            {
                input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                SendInput(1, &input, sizeof(INPUT));
                input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                SendInput(1, &input, sizeof(INPUT));
            }
            else if (action.attribute == "right")
            {
                input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
                SendInput(1, &input, sizeof(INPUT));
                input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
                SendInput(1, &input, sizeof(INPUT));
            }
            else if (action.attribute == "middle")
            {
                input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
                SendInput(1, &input, sizeof(INPUT));
                input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
                SendInput(1, &input, sizeof(INPUT));
            }
            else
            {
                MessageBoxA(NULL, "Invalid click type", "Error", MB_OK);
                PostQuitMessage(1);;
            }
        }
        else if(action.command == "execute")
        {
            ShellExecuteA(0, "open", action.attribute.c_str(), 0, 0, SW_SHOW);
        }
        else if(action.command == "wait")
        {
            Sleep(std::stoi(action.attribute));
        }
        else
        {
            MessageBoxA(NULL, "Invalid action", "Error", MB_OK);
            PostQuitMessage(1);;
        }
    }
}