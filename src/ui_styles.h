#include <windows.h>
#include <string>

#ifndef UI_STYLES_H
#define UI_STYLES_H

/// <summary>
/// Apply style of element
/// </summary>
/// <param name="hWnd"></param>
/// <param name="styleName"></param>
void ApplyStyle(HWND hWnd, const std::string& styleName);

/// <summary>
/// Apply Windows-style fonts
/// </summary>
/// <param name="hWnd"></param>
void ApplyDefaultFont(HWND hWnd);

#endif // UI_STYLES_H