#ifndef UI_PROC_H
#define UI_PROC_H

#include <windows.h>
#include <string>
#include <uxtheme.h>
#include "ui_set.h"
#pragma comment(lib, "uxtheme.lib")

LRESULT CALLBACK DefaultWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

#endif // UI_PROC_H