#include "resources.h"

std::vector<macro> parse(const std::string filepath)
{
    std::vector<macro> macros;
    macro mymacro;
    std::ifstream file(filepath);
    std::string line;
    int i = -1; // Initialize i to -1 to correctly index macros

    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines or comments
        }
        if (line.find(';') == std::string::npos)
        {
            if(M_hotkeys.find(line) != M_hotkeys.end()) {
                macros.push_back({M_hotkeys.at(line)});
                i++; // Increment i only when a new macro is added
            }
        }
        else
        {
            if (i >= 0) { // Ensure i is valid before accessing macros
                macros[i].actions.push_back({ line.substr(4, line.find(',') - 4), line.substr(line.find(',') + 2, line.find(';') - 1 - line.find(",") - 1) });
            }
        }
    }
    
    return macros;
}