#include "ui_styles.h"

/// <summary>
/// Apply style of element
/// </summary>
/// <param name="hWnd"></param>
/// <param name="styleName"></param>
void ApplyStyle(HWND hWnd, const std::string& styleName) {
    if (styleName.empty()) {
        // current aero theme
        //SetWindowTheme(hWnd, L" ", L" ");
    }
    else {
        // other styles
    }
}

/// <summary>
/// Apply Windows-style fonts
/// </summary>
/// <param name="hWnd"></param>
void ApplyDefaultFont(HWND hWnd) {
    NONCLIENTMETRICS ncm;
    ncm.cbSize = sizeof(NONCLIENTMETRICS);
    SystemParametersInfo(SPI_GETNONCLIENTMETRICS, ncm.cbSize, &ncm, 0);
    HFONT hFont = CreateFontIndirect(&ncm.lfMessageFont);
    SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, TRUE);
}