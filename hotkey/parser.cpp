#include "resources.h"

macro parse(const std::string filepath)
{
	macro mymacro;
	std::ifstream file(filepath);
	std::string line;

	while (std::getline(file, line))
	{
		if (line.empty() || line[0] == '#') {
            continue; // Skip empty lines or comments
        }
		if (line.find(';') == std::string::npos)
		{
			if(M_hotkeys.find(line) != M_hotkeys.end()) mymacro.hotkey = M_hotkeys.at(line);
		}
		else
		{
			mymacro.actions.push_back({ line.substr(4, line.find(',') - 4), line.substr(line.find(',') + 2, line.find(';') - 1 - line.find(",") - 1) });
		}
	}
	return mymacro;
}