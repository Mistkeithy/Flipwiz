#include "ui_elements.h"
#include "ui_messages.h"
#include <iostream>

int main()
{
    // Create window
    HWND hWnd = CreateAppWindow(GetModuleHandle(nullptr), SW_SHOWDEFAULT, "Flipwiz Dev", DefaultWndProc);

    // Create the button
    Button myButton(hWnd, "&Click me!", 50, 50, 100, 30);

    // Create the slider
    Slider mySlider(hWnd, 50, 100, 200, 30, 0, 5);

    // Create the label
    Label myLabel(hWnd, "Label:", 10, 10, 50, 20);
    
    // Create a Checkbox
    CheckBox myCheckBox(hWnd, "Check m&e!", 10, 30, 100, 20);

    // Create the Combobox
    ComboBox myComboBox(hWnd, 50, 250, 200, 200, false, "&Select an option:");
    myComboBox.AddItem("Option 1");
    myComboBox.AddItem("Option 2");
    myComboBox.AddItem("Option 3");

    // Create Radio Buttons
    Radio myRadioButton1(hWnd, "Option &1", 10, 150, 100, 20);
    Radio myRadioButton2(hWnd, "Option &2", 10, 180, 100, 20);

    // Create scrollbar
    ScrollBar scrollbar(hWnd, false, 350, 40, 16, 500);

    // Create Status bar
    StatusBar statusbar(hWnd);

    // Create ListBoxû
    ListBox myListbox(hWnd, 50, 300, 200, 100);
    SendMessage(myListbox.GetHandle(), LB_ADDSTRING, 0, (LPARAM)"Option 1");
    SendMessage(myListbox.GetHandle(), LB_ADDSTRING, 0, (LPARAM)"Option 2");
    SendMessage(myListbox.GetHandle(), LB_ADDSTRING, 0, (LPARAM)"Option 3");

    // Message processor
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}