#include "resources.h"

std::vector<macro> parse(const std::string filepath)
{
    std::vector<macro> macros;
    std::vector<UINT> modifiers;
    macro mymacro;
    std::ifstream file(filepath);
    std::string line;
    int i = -1;   //index turns 0 with the first macro

    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#') {
            continue;
        }
        if (line.find(';') == std::string::npos)
        {
            if(line.find('/') != std::string::npos) {
                for(int i = 0; i < line.find('/'); i++) {   //for each modifier
                    if(M_hotkeys.find(line.substr(i, 1)) != M_hotkeys.end())
                    {
                        modifiers.push_back(M_hotkeys.at(line.substr(i, 1)));
                    }
                    else
                    {
                        MessageBoxA(NULL, "Invalid modifier", "Error", MB_OK);
                        exit(1);
                    }
                }
                line = line.substr(line.find('/')+1);
            }
            if(M_hotkeys.find(line) != M_hotkeys.end()) {   //if it exists..
                macros.push_back({M_hotkeys.at(line)});     //it pushes it back (creates new macro)
                i++;
                if (!modifiers.empty()) {
                    macros[i].modifiers = modifiers;
                    modifiers.clear();
                }
            }
            else
            {
                MessageBoxA(NULL, "Invalid hotkey", "Error", MB_OK);
                exit(1);
            }
        }
        else
        {
            if (i >= 0) {
                macros[i].actions.push_back({ line.substr(4, line.find(',') - 4),
                line.substr(line.find(',') + 2, line.find(';') - 1 - line.find(",") - 1) }); //starts at x+2 so ends at y-(x+2)
            }
        }
    }
    file.close();
    return macros;
}