#ifndef UI_MESSAGES_H
#define UI_MESSAGES_H

#include <windows.h>
#include <string>
#include <uxtheme.h>
#pragma comment(lib, "uxtheme.lib")

LRESULT CALLBACK DefaultWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

#endif // UI_MESSAGES_H