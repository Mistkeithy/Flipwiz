#ifndef UI_ELEMENTS_H
#define UI_ELEMENTS_H

#include <windows.h>
#include <string>
#include <uxtheme.h>
#pragma comment(lib, "uxtheme.lib")

HWND CreateAppWindow(HINSTANCE hInstance, int nCmdShow, const char* windowTitle, WNDPROC wndProc);
LRESULT CALLBACK DefaultWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

/// <summary>
/// Classes
/// </summary>
class Button;
class Slider;
class Label;
class CheckBox;
class Radio;

// UI tweaks
void ApplyStyle(HWND hWnd, const std::string& styleName);
void ApplyDefaultFont(HWND hWnd);

HWND CreateMenuItem(HWND hWnd, const std::string& itemName, const std::string& itemText, const std::string& itemShortcut);

/// <summary>
/// Button class
/// </summary>
class Button {
public:
    Button(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;

private:
    HWND hWnd;
};

/// <summary>
/// Slider class
/// </summary>
class Slider {
public:
    Slider(HWND parent, int x, int y, int width, int height, int minRange, int maxRange);
    HWND GetHandle() const;

private:
    HWND hWnd;
};

/// <summary>
/// Label class
/// </summary>
class Label {
public:
    Label(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;

private:
    HWND hWnd;
};

/// <summary>
/// Checkbox class
/// </summary>
class CheckBox {
public:
    CheckBox(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;

private:
    HWND hWnd;
};

/// <summary>
/// Radio class
/// </summary>
class Radio {
public:
    Radio(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;

private:
    HWND hWnd;
};


#endif // UI_ELEMENTS_H