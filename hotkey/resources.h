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
	{"^", MOD_CONTROL},
	{"+", MOD_SHIFT},
	{"F1", VK_F1},
	{"F2", VK_F2}
};



struct action
{
	std::string command;
	std::string attribute;
};

struct macro
{
	UINT hotkey;
	std::vector<UINT> modifiers;
	std::vector<action> actions;
};



#endif