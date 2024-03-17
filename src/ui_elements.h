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
/// Arragement controls
/// </summary>
struct ArrangeSettings {
    enum class Direction { 
        Row, 
        Column, 
        Diagonal 
    };
    enum class Gravity { 
        TopLeft,
        Center,
        BottomRight 
    };

    Direction direction;
    bool stretchWidth;
    bool stretchHeight;
    int elementsPerRow;
    Gravity gravity;
    int gapX;
    int gapY;
    int startX;
    int startY;
    int containerWidth;
    int containerHeight;
    int controlHeight;

    ArrangeSettings()
        : direction(Direction::Column), stretchWidth(false), stretchHeight(false), elementsPerRow(3),
        gravity(Gravity::TopLeft), gapX(10), gapY(10), startX(10), startY(10),
        containerWidth(50), containerHeight(50), controlHeight(30) {}
};

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
private:
    HWND hWnd;

public:
    Button(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;
    ~Button();
};

/// <summary>
/// Slider class
/// </summary>
class Slider : public UIElement {
private:
    HWND hWnd;

public:
    Slider(HWND parent, int x, int y, int width, int height, int minRange, int maxRange);
    HWND GetHandle() const;
    ~Slider();
};

/// <summary>
/// Label class
/// </summary>
class Label : public UIElement {
private:
    HWND hWnd;

public:
    Label(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;
    ~Label();
};

/// <summary>
/// Checkbox class
/// </summary>
class CheckBox : public UIElement {
private:
    HWND hWnd;

public:
    CheckBox(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;
    ~CheckBox();
};

/// <summary>
/// Radio class
/// </summary>
class Radio : public UIElement {
private:
    HWND hWnd;

public:
    Radio(HWND parent, const std::string& text, int x, int y, int width, int height);
    HWND GetHandle() const;
    ~Radio();
};

/// <summary>
/// Scrollbar class
/// </summary>
class ScrollBar : public UIElement {
private:
    HWND hWnd;

public:
    ScrollBar(HWND parent, bool isHorizontal, int x, int y, int width, int height);
    HWND GetHandle() const;
    ~ScrollBar();
};

/// <summary>
/// Statusbar class
/// </summary>
class StatusBar : public UIElement {
private:
    HWND hWnd;

public:
    StatusBar(HWND parent);
    HWND GetHandle() const;
    void SetText(const std::string& text, int part = 0);
    ~StatusBar();
};

/// <summary>
/// ListBox class
/// </summary>
class ListBox : public UIElement {
private:
    HWND hWnd;
    HWND hwndParent;

public:
    ListBox(HWND parent, int x, int y, int width, int height);
    HWND GetHandle() const;
    ~ListBox();
};

/// <summary>
/// Combobox class
/// </summary>
class ComboBox : public UIElement {
private:
    HWND hWnd;
    Label label;

public:
    ComboBox(HWND parent, int x, int y, int width, int height, bool editable, const std::string& labelText);
    HWND GetHandle() const;
    void AddItem(const std::string& itemText);
    ~ComboBox();
};

/// <summary>
/// Frame class
/// </summary>
class Frame : public UIElement {
public:
    enum class FrameType {
        Automatic,
        Floating
    };

    Frame(HWND parent, int x, int y, int width, int height, FrameType type = FrameType::Automatic);
    virtual ~Frame();

    HWND GetHandle() const override;
    void AddControl(std::unique_ptr<UIElement> control);
    void SetType(FrameType type);

    void ArrangeControls(const ArrangeSettings& settings = {});


private:
    HWND hwndParent;
    int x, y, width, height;
    FrameType type;
    HWND hWnd;
    std::vector<std::unique_ptr<UIElement>> controls;

    void CreateFrameWindow();
};

#endif // UI_ELEMENTS_H