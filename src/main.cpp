#include "ui_elements.h"
#include "ui_messages.h"
#include <iostream>
#include <utility>

int UIExamples()
{
    // Create window
    HWND hWnd = CreateAppWindow(GetModuleHandle(nullptr), SW_SHOWDEFAULT, "Flipwiz Dev", DefaultWndProc);

    // Create the button
    //Button myButton(hWnd, "&Click me!", 50, 50, 100, 30);

    // Create the slider
    //Slider mySlider(hWnd, 50, 100, 200, 30, 0, 5);

    // Create the label
    //Label myLabel(hWnd, "Label:", 10, 10, 50, 20);
    
    // Create a Checkbox
    //CheckBox myCheckBox(hWnd, "Check m&e!", 10, 30, 100, 20);

    // Create the Combobox
    //ComboBox myComboBox(hWnd, 50, 250, 200, 200, false, "&Select an option:");
    //myComboBox.AddItem("Option 1");
    //myComboBox.AddItem("Option 2");
    //myComboBox.AddItem("Option 3");

    // Create Radio Buttons
    //Radio myRadioButton1(hWnd, "Option &1", 10, 150, 100, 20);
    //Radio myRadioButton2(hWnd, "Option &2", 10, 180, 100, 20);

    // Create scrollbar
    ScrollBar scrollbar(hWnd, false, 350, 40, 16, 500);

    // Create Status bar
    StatusBar statusbar(hWnd);

    // Create ListBox
    //ListBox myListbox(hWnd, 50, 300, 200, 100);
    //SendMessage(myListbox.GetHandle(), LB_ADDSTRING, 0, (LPARAM)"Option 1");
    //SendMessage(myListbox.GetHandle(), LB_ADDSTRING, 0, (LPARAM)"Option 2");
    //SendMessage(myListbox.GetHandle(), LB_ADDSTRING, 0, (LPARAM)"Option 3");

    // Create the frame
    Frame myFrame(hWnd, 400, 0, 300, 300);
    
    // Create some buttons
    std::unique_ptr<UIElement> button1 = std::make_unique<Button>(myFrame.GetHandle(), "&Click me!", 10, 10, 510, 30);
    std::unique_ptr<UIElement> chck = std::make_unique<CheckBox>(myFrame.GetHandle(), "Check m&e!", 10, 30, 100, 20);
    std::unique_ptr<UIElement> lbx = std::make_unique<ListBox>(myFrame.GetHandle(), 50, 300, 200, 100);
    SendMessage(dynamic_cast<ListBox*>(lbx.get())->GetHandle(), LB_ADDSTRING, 0, (LPARAM)"Option 1");
    SendMessage(dynamic_cast<ListBox*>(lbx.get())->GetHandle(), LB_ADDSTRING, 0, (LPARAM)"Option 2");
    SendMessage(dynamic_cast<ListBox*>(lbx.get())->GetHandle(), LB_ADDSTRING, 0, (LPARAM)"Option 3");
    std::unique_ptr<UIElement> lbl = std::make_unique<Label>(myFrame.GetHandle(), "Label:", 10, 10, 50, 20);
    std::unique_ptr<UIElement> combotest = std::make_unique<ComboBox>(myFrame.GetHandle(), 50, 250, 200, 200, false, "&C");
    dynamic_cast<ComboBox*>(combotest.get())->AddItem("Option 1");
    dynamic_cast<ComboBox*>(combotest.get())->AddItem("Option 2");
    dynamic_cast<ComboBox*>(combotest.get())->AddItem("Option 3");
    std::unique_ptr<UIElement> sldr = std::make_unique<Slider>(myFrame.GetHandle(), 50, 100, 200, 30, 0, 5);
    std::unique_ptr<UIElement> button7 = std::make_unique<Button>(myFrame.GetHandle(), "Button 7", 10, 30, 100, 30);

    // Add the buttons to the frame
    myFrame.AddControl(std::move(button1));
    myFrame.AddControl(std::move(chck));
    myFrame.AddControl(std::move(lbx));
    myFrame.AddControl(std::move(lbl));
    myFrame.AddControl(std::move(combotest));
    myFrame.AddControl(std::move(sldr));
    myFrame.AddControl(std::move(button7));

    // Set the frame params
    ArrangeSettings settings;
    settings.direction = ArrangeSettings::Direction::Column;
    settings.stretchWidth = true;
    settings.stretchHeight = false;
    settings.gapX = 10;
    settings.gapY = 5;
    settings.elementsPerRow = 3;
    settings.containerWidth = 300;
    settings.containerHeight = 300;

    // Apply new frame settings
    myFrame.ArrangeControls(settings);

    // Message processor
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

int main() {
    return UIExamples();
}