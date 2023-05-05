#include "ui_elements.h"
#include <iostream>

int main()
{
    // Create window
    HWND hWnd = CreateAppWindow(GetModuleHandle(nullptr), SW_SHOWDEFAULT, "Flipwiz Dev", DefaultWndProc);

    // Create the button
    Button myButton(hWnd, "Click me!", 50, 50, 100, 30);
    ApplyStyle(myButton.GetHandle(), "");

    // Create the slider
    Slider mySlider(hWnd, 50, 100, 200, 30, 0, 100);
    ApplyStyle(mySlider.GetHandle(), "");

    // Message processor
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}