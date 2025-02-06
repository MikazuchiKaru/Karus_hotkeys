#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <map>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <Windows.h>

const std::map<std::string, UINT> M_hotkeys = {
	{"F1", VK_F1}
};



struct action
{
	std::string command;
	std::string attribute;
};

struct macro
{
	UINT hotkey;
	std::vector<action> actions;
};

#endif