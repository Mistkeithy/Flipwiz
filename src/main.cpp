#include "ui_elements.h"
#include "ui_proc.h"
#include "ui_styles.h"
#include "ui_set.h"
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

    // Create Textbox
    TextBox textbox(hWnd, 380, 40, 150, 20, false);
    TextBox textboxMultiLine(hWnd, 380, 80, 150, 256, true);

    // Create Listview
    ListView listview(hWnd, 580, 120, 150, 256);

    // Create Tab Control
    TabControl tabcontrol(hWnd, 150, 10, 200, 22, TABCONTROL_ID);
    tabcontrol.AddTab("Tab 1");
    tabcontrol.AddTab("Tab 2");
    tabcontrol.AddTab("Tab 3");
    tabcontrol.AddTab("Tab 4");
    tabcontrol.AddTab("Tab 5");

    // Message processor
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (!IsDialogMessage(hWnd, &msg)) { // Добавьте эту строку перед TranslateMessage
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}