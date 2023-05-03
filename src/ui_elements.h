#ifndef UI_ELEMENTS_H
#define UI_ELEMENTS_H

#include <windows.h>
#include <string>

HWND CreateAppWindow(HINSTANCE hInstance, int nCmdShow, const char* windowTitle, WNDPROC wndProc);
LRESULT CALLBACK DefaultWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

class Button;
class Slider;
void ApplyStyle(HWND hWnd, const std::string& styleName);

class Button {
public:
    Button(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;

private:
    HWND hWnd;
};

class Slider {
public:
    Slider(HWND parent, int x, int y, int width, int height, int minRange, int maxRange);
    HWND GetHandle() const;

private:
    HWND hWnd;
};

#endif // UI_ELEMENTS_H