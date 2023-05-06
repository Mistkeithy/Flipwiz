#include "ui_elements.h"
#include <iostream>

int main()
{
    // Create window
    HWND hWnd = CreateAppWindow(GetModuleHandle(nullptr), SW_SHOWDEFAULT, "Flipwiz Dev", DefaultWndProc);

    // Create the button
    Button myButton(hWnd, "Click me!", 50, 50, 100, 30);

    // Create the slider
    Slider mySlider(hWnd, 50, 100, 200, 30, 0, 100);

    // Create the label
    Label myLabel(hWnd, "Label:", 10, 10, 50, 20);
    
    // Create a Checkbox
    CheckBox myCheckBox(hWnd, "Check me!", 10, 30, 100, 20);

    // Create Radio Buttons
    Radio myRadioButton1(hWnd, "Option 1", 10, 150, 100, 20);
    Radio myRadioButton2(hWnd, "Option 2", 10, 180, 100, 20);

    // Message processor
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}