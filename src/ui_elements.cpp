#include "ui_elements.h"
#include <commctrl.h>

/// <summary>
/// Create Application Window
/// </summary>
/// <param name="hInstance"></param>
/// <param name="nCmdShow"></param>
/// <param name="windowTitle"></param>
/// <param name="wndProc"></param>
/// <returns></returns>
HWND CreateAppWindow(HINSTANCE hInstance, int nCmdShow, const char* windowTitle, WNDPROC wndProc)
{
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = wndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = windowTitle;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex)) {
        MessageBox(nullptr, "Call to RegisterClassEx failed!", windowTitle, NULL);
        return nullptr;
    }

    HWND hWnd = CreateWindow(
        windowTitle, windowTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        800, 600,
        nullptr, nullptr,
        hInstance, nullptr
    );

    if (!hWnd) {
        MessageBox(nullptr, "Call to CreateWindow failed!", windowTitle, NULL);
        return nullptr;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return hWnd;
}

LRESULT CALLBACK DefaultWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

/// <summary>
/// Button
/// </summary>
/// <param name="parent"></param>
/// <param name="text"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
Button::Button(HWND parent, const std::string& text, int x, int y, int width, int height) {
    hWnd = CreateWindow("BUTTON", text.c_str(),
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        x, y, width, height,
        parent, nullptr, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), nullptr);
    ApplyDefaultFont(hWnd);
}

HWND Button::GetHandle() const {
    return hWnd;
}

/// <summary
/// Create the silder element
/// </summary>
/// <param name="parent"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <param name="minRange"></param>
/// <param name="maxRange"></param>
Slider::Slider(HWND parent, int x, int y, int width, int height, int minRange, int maxRange) {
    hWnd = CreateWindow("msctls_trackbar32", nullptr,
        WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS,
        x, y, width, height,
        parent, nullptr, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), nullptr);

    SendMessage(hWnd, TBM_SETRANGEMIN, (WPARAM)TRUE, (LPARAM)minRange);
    SendMessage(hWnd, TBM_SETRANGEMAX, (WPARAM)TRUE, (LPARAM)maxRange);
}

HWND Slider::GetHandle() const {
    return hWnd;
}


/// <summary>
/// Label class
/// </summary>
/// <param name="parent"></param>
/// <param name="text"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
Label::Label(HWND parent, const std::string& text, int x, int y, int width, int height) {
    hWnd = CreateWindow("STATIC", text.c_str(), WS_CHILD | WS_VISIBLE | SS_LEFT, 
        x, y, width, height, parent, NULL, GetModuleHandle(NULL), NULL);
    ApplyDefaultFont(hWnd);
}

HWND Label::GetHandle() const {
    return hWnd;
}

/// <summary>
/// Check box class
/// </summary>
/// <param name="parent"></param>
/// <param name="text"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
CheckBox::CheckBox(HWND parent, const std::string& text, int x, int y, int width, int height) {
    hWnd = CreateWindow("BUTTON", text.c_str(), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 
        x, y, width, height, parent, NULL, GetModuleHandle(NULL), NULL);
    ApplyDefaultFont(hWnd);
}

HWND CheckBox::GetHandle() const {
    return hWnd;
}

/// <summary>
/// Radio box class
/// </summary>
/// <param name="parent"></param>
/// <param name="text"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
Radio::Radio(HWND parent, const std::string& text, int x, int y, int width, int height) {
    hWnd = CreateWindow("BUTTON", text.c_str(), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON, 
        x, y, width, height, parent, NULL, GetModuleHandle(NULL), NULL);
    ApplyDefaultFont(hWnd);
}

HWND Radio::GetHandle() const {
    return hWnd;
}

/// <summary>
/// Style of element
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
