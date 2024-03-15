#ifndef UI_ELEMENTS_H
#define UI_ELEMENTS_H

#include <windows.h>
#include <string>
#include <vector>
#include <memory>

#define IDI_ICON1 101

HWND CreateAppWindow(HINSTANCE hInstance, int nCmdShow, const char* windowTitle, WNDPROC wndProc);

// UI tweaks
void ApplyStyle(HWND hWnd, const std::string& styleName);
void ApplyDefaultFont(HWND hWnd);

/// <summary>
/// UIElement class
/// </summary>
class UIElement {
public:
    virtual ~UIElement() = default;

    virtual HWND GetHandle() const = 0;

    // other here
};

/// <summary>
/// Button class
/// </summary>
class Button : public UIElement {
    HWND hWnd;

public:
    Button(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;
};

/// <summary>
/// Slider class
/// </summary>
class Slider : public UIElement {
    HWND hWnd;

public:
    Slider(HWND parent, int x, int y, int width, int height, int minRange, int maxRange);
    HWND GetHandle() const;
};

/// <summary>
/// Label class
/// </summary>
class Label : public UIElement {
    HWND hWnd;

public:
    Label(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;
};

/// <summary>
/// Checkbox class
/// </summary>
class CheckBox : public UIElement {
    HWND hWnd;

public:
    CheckBox(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;
};

/// <summary>
/// Radio class
/// </summary>
class Radio : public UIElement {
    HWND hWnd;

public:
    Radio(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;
};

/// <summary>
/// Scrollbar class
/// </summary>
class ScrollBar : public UIElement {
    HWND hWnd;

public:
    ScrollBar(HWND parent, bool isHorizontal, int x, int y, int width, int height);
    HWND GetHandle() const;
};

/// <summary>
/// Statusbar class
/// </summary>
class StatusBar : public UIElement {
    HWND hWnd;

public:
    StatusBar(HWND parent);
    HWND GetHandle() const;
    void SetText(const std::string& text, int part = 0);
};

/// <summary>
/// ListBox class
/// </summary>
class ListBox : public UIElement {
    HWND hWnd;

private:
    HWND hwndParent;
public:
    ListBox(HWND parent, int x, int y, int width, int height);
    HWND GetHandle() const;
};

/// <summary>
/// Combobox class
/// </summary>
class ComboBox : public UIElement {
    HWND hWnd;

public:
    ComboBox(HWND parent, int x, int y, int width, int height, bool editable, const std::string& labelText);
    HWND GetHandle() const;
    void AddItem(const std::string& itemText);

private:
    Label label;
};

#endif // UI_ELEMENTS_H