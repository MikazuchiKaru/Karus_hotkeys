#pragma once
#ifndef HEADER_H
#define HEADER_H
#define WM_MY_EXIT (WM_USER + 1)
#include <map>
#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <Windows.h>

const std::map<std::string, UINT> M_hotkeys =
{
	//modifiers
	{"!", MOD_ALT},
	{"^", MOD_CONTROL},
	{"+", MOD_SHIFT},
	{"%", MOD_WIN},
	//mouse buttons
	{"LMB", VK_LBUTTON},
	{"RMB", VK_RBUTTON},
	{"MMB", VK_MBUTTON},
	{"X1", VK_XBUTTON1},
	{"X2", VK_XBUTTON2},
	//keys
    {"F1", VK_F1},
    {"F2", VK_F2},
    {"F3", VK_F3},
    {"F4", VK_F4},
    {"F5", VK_F5},
    {"F6", VK_F6},
    {"F7", VK_F7},
    {"F8", VK_F8},
    {"F9", VK_F9},
    {"F10", VK_F10},
    {"F11", VK_F11},
    {"F12", VK_F12},
    {"A", 'A'},
    {"B", 'B'},
    {"C", 'C'},
    {"D", 'D'},
    {"E", 'E'},
    {"F", 'F'},
    {"G", 'G'},
    {"H", 'H'},
    {"I", 'I'},
    {"J", 'J'},
    {"K", 'K'},
    {"L", 'L'},
    {"M", 'M'},
    {"N", 'N'},
    {"O", 'O'},
    {"P", 'P'},
    {"Q", 'Q'},
    {"R", 'R'},
    {"S", 'S'},
    {"T", 'T'},
    {"U", 'U'},
    {"V", 'V'},
    {"W", 'W'},
    {"X", 'X'},
    {"Y", 'Y'},
    {"Z", 'Z'},
    {"1", '1'},
    {"2", '2'},
    {"3", '3'},
    {"4", '4'},
    {"5", '5'},
    {"6", '6'},
    {"7", '7'},
    {"8", '8'},
    {"9", '9'},
    {"0", '0'},
    {"-", '-'},
    {"=", '='},
    {"[", '['},
    {"]", ']'},
    {"'", '\''},
    {",", ','},
    {".", '.'},
    {"/", '/'},
    {"\\", '\\'},
    {"`", '`'},
    {" ", ' '},
	//special keys
    {"TAB", VK_TAB},
    {"ENTER", VK_RETURN},
    {"BACKSPACE", VK_BACK},
    {"SHIFT", VK_SHIFT},
    {"CTRL", VK_CONTROL},
    {"ALT", VK_MENU},
    {"CAPSLOCK", VK_CAPITAL},
    {"ESC", VK_ESCAPE},
    {"PGUP", VK_PRIOR},
    {"PGDN", VK_NEXT},
    {"END", VK_END},
    {"HOME", VK_HOME},
    {"LEFT", VK_LEFT},
    {"UP", VK_UP},
    {"RIGHT", VK_RIGHT},
    {"DOWN", VK_DOWN},
    {"INS", VK_INSERT},
    {"DEL", VK_DELETE},
    {"NUMLOCK", VK_NUMLOCK},
    {"SCROLLLOCK", VK_SCROLL},
    {"PAUSE", VK_PAUSE},
    {"PRINTSCREEN", VK_SNAPSHOT},
    {"LWIN", VK_LWIN},
    {"RWIN", VK_RWIN},
    {"NUM0", VK_NUMPAD0},
    {"NUM1", VK_NUMPAD1},
    {"NUM2", VK_NUMPAD2},
    {"NUM3", VK_NUMPAD3},
    {"NUM4", VK_NUMPAD4},
    {"NUM5", VK_NUMPAD5},
    {"NUM6", VK_NUMPAD6},
    {"NUM7", VK_NUMPAD7},
    {"NUM8", VK_NUMPAD8},
    {"NUM9", VK_NUMPAD9}
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