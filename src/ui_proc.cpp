#include "ui_proc.h"

/// <summary>
/// UI Procedure
/// </summary>
/// <param name="hWnd"></param>
/// <param name="message"></param>
/// <param name="wParam"></param>
/// <param name="lParam"></param>
/// <returns></returns>
LRESULT CALLBACK DefaultWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) { // Keyboard processing
    case WM_CREATE: {
        // on window create
        break;
    }
    case WM_SIZE: {
        // on changing window size
        HWND hStatusBar = FindWindowEx(hWnd, NULL, STATUSCLASSNAME, NULL);
        if (hStatusBar) {
            MoveWindow(hStatusBar, 0, 0, 0, 0, TRUE);
        }
        break;
    }
    case WM_MOVE: {
        // on window create
        break;
    }
    case WM_PAINT: {
        // on window draw
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // All painting occurs here, between BeginPaint and EndPaint
        EndPaint(hWnd, &ps);
        break;
    }
    case WM_DESTROY: {
        // on window close
        PostQuitMessage(0);
        break;
    }
    case WM_KEYUP: {
        // on key release
        break;
    }
    case WM_KEYDOWN: {
        // on key pressing
        if (GetKeyState(VK_CONTROL) & 0x8000) {
            HWND hTabControl = GetDlgItem(hWnd, TABCONTROL_ID);
            if (hTabControl != nullptr) {
                int currentTabIndex = TabCtrl_GetCurSel(hTabControl);
                int tabCount = TabCtrl_GetItemCount(hTabControl);

                if (wParam == VK_TAB) {
                    if (GetKeyState(VK_SHIFT) & 0x8000) {
                        currentTabIndex--;
                        if (currentTabIndex < 0) {
                            currentTabIndex = tabCount - 1;
                        }
                    }
                    else {
                        currentTabIndex++;
                        if (currentTabIndex >= tabCount) {
                            currentTabIndex = 0;
                        }
                    }
                    TabCtrl_SetCurSel(hTabControl, currentTabIndex);
                }
            }
        }
        break;
    }
    case WM_SYSKEYUP: {
        // on utility key release
        break;
    }
    case WM_SYSKEYDOWN: {
        // on utility key pressing
        switch (wParam) {
        case VK_TAB:
            SetFocus(GetNextDlgTabItem(hWnd, GetFocus(), GetKeyState(VK_SHIFT) < 0));
            return 0;
        case VK_LEFT:
        case VK_UP:
        case VK_RIGHT:
        case VK_DOWN:
            break;
        default:
            break;
        }
        break;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK ChildWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_KEYDOWN: {
        if (GetKeyState(VK_CONTROL) & 0x8000) {
            // Обработка Ctrl+Tab и Ctrl+Shift+Tab для переключения вкладок
        }
        break;
    }
    case WM_SYSKEYDOWN: {
        // Обработка Alt+Mnemonic для активации элементов управления
        break;
    }
    case WM_GETDLGCODE: {
        // Включение обработки клавиш Tab и стрелок
        return DLGC_WANTTAB | DLGC_WANTARROWS;
    }
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}