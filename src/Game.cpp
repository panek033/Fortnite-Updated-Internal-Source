#include "../pch.h"
#include "../include/Game.hpp"
namespace husisudfr {
	GameData::GameData()
	{
#if DEBUG
		g_Console->printdbg("UD SINCE PROJECT CREATED\n", g_Console->color.pink);
#endif
		return;
	}

	GameVariables::GameVariables()
	{
#if DEBUG
		g_Console->printdbg("Use at your main fr\n", g_Console->color.pink);
#endif
		return;
	}

	//	Get Process Window Information
	void GameVariables::Init()
	{
		g_GamePid = GetCurrentProcessId();
		g_GameHandle = GetCurrentProcess();
		g_GameWindow = GetForegroundWindow();

		RECT tempRECT;
		GetWindowRect(g_GameWindow, &tempRECT);
		g_GameWidth = tempRECT.right - tempRECT.left;
		g_GameHeight = tempRECT.bottom - tempRECT.top;

		char tempTitle[MAX_PATH];
		GetWindowTextA(g_GameWindow, tempTitle, sizeof(tempTitle));
		g_GameTitle = tempTitle;

		char tempClassName[MAX_PATH];
		GetClassNameA(g_GameWindow, tempClassName, sizeof(tempClassName));
		g_ClassName = tempClassName;

		char tempPath[MAX_PATH];
		GetModuleFileNameExA(g_GameHandle, NULL, tempPath, sizeof(tempPath));
		g_GamePath = tempPath;
#if DEBUG
		g_Console->printdbg("Hus is ud fr\n", g_Console->color.pink);
#endif
	}
}