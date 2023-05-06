#include "ui_messages.h"

/// <summary>
/// UI Messages
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
}