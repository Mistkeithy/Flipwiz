#ifndef UI_ELEMENTS_H
#define UI_ELEMENTS_H

#include <windows.h>
#include <string>

#define IDI_ICON1 101

HWND CreateAppWindow(HINSTANCE hInstance, int nCmdShow, const char* windowTitle, WNDPROC wndProc);

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

/// <summary>
/// Scrollbar class
/// </summary>
class ScrollBar {
public:
    ScrollBar(HWND parent, bool isHorizontal, int x, int y, int width, int height);
    HWND GetHandle() const;

private:
    HWND hWnd;
};

/// <summary>
/// Statusbar class
/// </summary>
class StatusBar {
public:
    StatusBar(HWND parent);
    HWND GetHandle() const;
    void SetText(const std::string& text, int part = 0);

private:
    HWND hWnd;
};

/// <summary>
/// Combobox class
/// </summary>
class ComboBox {
public:
    ComboBox(HWND parent, int x, int y, int width, int height, bool editable, const std::string& labelText);
    HWND GetHandle() const;
    void AddItem(const std::string& itemText);

private:
    HWND hWnd;
    Label label;
};

#endif // UI_ELEMENTS_H