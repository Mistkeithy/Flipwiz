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
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    if (!RegisterClassEx(&wcex)) {
        MessageBox(nullptr, "Call to RegisterClassEx failed!", windowTitle, NULL);
        return nullptr;
    }

    DWORD windowExStyle = WS_EX_OVERLAPPEDWINDOW | WS_EX_CONTROLPARENT;

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

Button::~Button() {
    if (hWnd) {
        DestroyWindow(hWnd);
    }
}

/// <summary
/// Silder
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
        WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | WS_TABSTOP,
        x, y, width, height,
        parent, nullptr, (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE), nullptr);

    SendMessage(hWnd, TBM_SETRANGEMIN, (WPARAM)TRUE, (LPARAM)minRange);
    SendMessage(hWnd, TBM_SETRANGEMAX, (WPARAM)TRUE, (LPARAM)maxRange);
}

HWND Slider::GetHandle() const {
    return hWnd;
}

Slider::~Slider() {
    if (hWnd) {
        DestroyWindow(hWnd);
    }
}


/// <summary>
/// Label
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

Label::~Label() {
    if (hWnd) {
        DestroyWindow(hWnd);
    }
}

/// <summary>
/// Check box
/// </summary>
/// <param name="parent"></param>
/// <param name="text"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
CheckBox::CheckBox(HWND parent, const std::string& text, int x, int y, int width, int height) {
    hWnd = CreateWindow("BUTTON", text.c_str(), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX | WS_TABSTOP,
        x, y, width, height, parent, NULL, GetModuleHandle(NULL), NULL);
    ApplyDefaultFont(hWnd);
}

HWND CheckBox::GetHandle() const {
    return hWnd;
}

CheckBox::~CheckBox() {
    if (hWnd) {
        DestroyWindow(hWnd);
    }
}

/// <summary>
/// Radio box
/// </summary>
/// <param name="parent"></param>
/// <param name="text"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
Radio::Radio(HWND parent, const std::string& text, int x, int y, int width, int height) {
    hWnd = CreateWindow("BUTTON", text.c_str(), WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_TABSTOP,
        x, y, width, height, parent, NULL, GetModuleHandle(NULL), NULL);
    ApplyDefaultFont(hWnd);
}

HWND Radio::GetHandle() const {
    return hWnd;
}

Radio::~Radio() {
    if (hWnd) {
        DestroyWindow(hWnd);
    }
}

/// <summary>
/// Scrollbar 
/// </summary>
/// <param name="parent"></param>
/// <param name="isHorizontal"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
ScrollBar::ScrollBar(HWND parent, bool isHorizontal, int x, int y, int width, int height) {
    DWORD windowStyle = WS_CHILD | WS_VISIBLE | (isHorizontal ? SBS_HORZ : SBS_VERT);
    hWnd = CreateWindowEx(0, "SCROLLBAR", nullptr, windowStyle, x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
}

HWND ScrollBar::GetHandle() const {
    return hWnd;
}

ScrollBar::~ScrollBar() {
    if (hWnd) {
        DestroyWindow(hWnd);
    }
}

/// <summary>
/// Status bar
/// </summary>
/// <param name="parent"></param>
StatusBar::StatusBar(HWND parent) {
    hWnd = CreateWindowEx(0, STATUSCLASSNAME, nullptr, WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 0, 0, 0, 0, parent, nullptr, GetModuleHandle(nullptr), nullptr);
    UpdateWindow(hWnd);
}

HWND StatusBar::GetHandle() const {
    return hWnd;
}

void StatusBar::SetText(const std::string& text, int part) {
    SendMessage(hWnd, SB_SETTEXT, part, (LPARAM)text.c_str());
}

StatusBar::~StatusBar() {
    if (hWnd) {
        DestroyWindow(hWnd);
    }
}

/// <summary>
/// ListBox
/// </summary>
/// <param name="parent"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <param name="editable"></param>
ListBox::ListBox(HWND parent, int x, int y, int width, int height) {
    hwndParent = parent;
    hWnd = CreateWindowExW(WS_EX_CLIENTEDGE, L"LISTBOX", nullptr,
        WS_CHILD | WS_VISIBLE | WS_VSCROLL | LBS_NOTIFY,
        x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
    ApplyDefaultFont(hWnd);
}

HWND ListBox::GetHandle() const {
    return hWnd;
}

ListBox::~ListBox() {
    if (hWnd) {
        DestroyWindow(hWnd);
    }
}

/// <summary>
/// ComboBox
/// </summary>
/// <param name="parent"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <param name="editable"></param>
ComboBox::ComboBox(HWND parent, int x, int y, int width, int height, bool editable, const std::string& labelText)
    : hWnd(nullptr), label(parent, labelText, x, y - 20, width, 20) {
    DWORD windowStyle = WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | WS_TABSTOP | (editable ? 0 : CBS_DROPDOWNLIST);
    hWnd = CreateWindowEx(0, "COMBOBOX", nullptr, windowStyle, x, y, width, height, parent, nullptr, GetModuleHandle(nullptr), nullptr);
    ApplyDefaultFont(hWnd);
}

HWND ComboBox::GetHandle() const {
    return hWnd;
}

void ComboBox::AddItem(const std::string& itemText) {
    SendMessage(hWnd, CB_ADDSTRING, 0, reinterpret_cast<LPARAM>(itemText.c_str()));
}

ComboBox::~ComboBox() {
    if (hWnd) {
        DestroyWindow(hWnd);
    }
}

/// <summary>
/// Frame
/// </summary>
/// <param name="parent"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="width"></param>
/// <param name="height"></param>
/// <param name="type"></param>
Frame::Frame(HWND parent, int x, int y, int width, int height, FrameType type)
    : hwndParent(parent), x(x), y(y), width(width), height(height), type(type), hWnd(nullptr) {
    CreateFrameWindow();
}

HWND Frame::GetHandle() const {
    return hWnd;
}

void Frame::AddControl(std::unique_ptr<UIElement> control) {
    controls.push_back(std::move(control));
}

void Frame::SetType(FrameType type) {
    type = type;
}

void Frame::CreateFrameWindow() {
    hWnd = CreateWindowEx(0, WC_STATIC, "", WS_CHILD | WS_VISIBLE | SS_OWNERDRAW,
        x, y, width, height, hwndParent, nullptr, GetModuleHandle(nullptr), nullptr);
}

void Frame::ArrangeControls(const ArrangeSettings& settings) {
    int currentX = settings.startX, currentY = settings.startY;
    int controlHeight = settings.controlHeight;

    int elementsCounter = 0;

    for (auto& control : controls) {
        RECT controlRect;
        GetWindowRect(control->GetHandle(), &controlRect);
        int controlWidth = controlRect.right - controlRect.left;

        // Adjust width to not exceed the container's width
        if (controlWidth > settings.containerWidth - 2 * settings.startX) {
            controlWidth = settings.containerWidth - 2 * settings.startX;
        }

        switch (settings.direction) {
        case ArrangeSettings::Direction::Row:
            // Overlap of frame
            controlWidth = settings.stretch ? 
                (settings.containerWidth - settings.startX * 2 - settings.spacing * (settings.elementsPerRow - 1)) / settings.elementsPerRow : controlWidth;

            if (currentX + controlWidth > settings.containerWidth - settings.startX && elementsCounter > 0) {
                currentX = settings.startX;
                currentY += controlHeight + settings.spacing;
                elementsCounter = 0; // Reset counter for new row
            }
            break;
        case ArrangeSettings::Direction::Column:
            // Overlap of frame
            controlWidth = settings.stretch ? settings.containerWidth - 2 * settings.startX : controlWidth;

            if (currentY + controlHeight > settings.containerHeight - settings.startY) {
                //TODO: Handle overflow for column direction
                break;
            }
            break;
        case ArrangeSettings::Direction::Diagonal:
            //TODO: Diagonal display
            break;
        }

        SetWindowPos(control->GetHandle(), HWND_TOP, currentX, currentY, controlWidth, controlHeight, SWP_NOZORDER);

        switch (settings.direction) {
        case ArrangeSettings::Direction::Row:
            currentX += controlWidth + settings.spacing;
            elementsCounter++;
            break;
        case ArrangeSettings::Direction::Column:
            if (settings.stretch) {
                // For Column direction when stretch is true, control stretches to full width
                currentY += controlHeight + settings.spacing;
            }
            else {
                // For Column direction when stretch is false, behave as per existing logic
                currentY += controlHeight + settings.spacing;
            }
            break;
        }
    }

    //TODO: Gravity process
}


Frame::~Frame() {
    if (hWnd) {
        DestroyWindow(hWnd);
    }
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