#include <iostream>
#include <chrono>
#include <thread>
#include <stack>
#include <stdexcept>
#ifdef RASPBERRY_PI_PICO
#include "pico/stdlib.h"
#endif
#include "Menu.h"

using namespace std;

int main_test()
{
    int optionSelected;

    // Put welcome message on the screen
    cout << "Temperature control application\n";
#ifndef RASPBERRY_PI_PICO
    this_thread::sleep_for(chrono::milliseconds(1000));
#else
    sleep_ms(1000);
#endif
    system("reset");
        
    // Sample menu
    MenuItem mainMenuItem("Main");
    MenuItem   toolMenuItem("Tools", &mainMenuItem);
    MenuItem   notesMenuItem("Notes", &mainMenuItem);
    MenuItem     subjectsMenuItem("Subjects", &notesMenuItem);
    MenuItem       mathMenuItem("Math", &subjectsMenuItem);
    MenuItem       sciencesMenuItem("Sciences", &subjectsMenuItem);
    MenuItem       humanMenuItem("Humanities", &subjectsMenuItem);
    MenuItem   flashCardsMenuItem("Flash Cards", &mainMenuItem);

    Menu* menu = new Menu(&mainMenuItem);
    /*
    if (MenuItemStack.empty())
    {
        cout << "MenuItem items not found";
        return -1;
    }
    */
    while (true)
    {
        // Show MenuItem
        menu->display();

        // Read & validate MenuItem item number
        menu->getUserSelection(&optionSelected);

        while (optionSelected < 1 || optionSelected > menu->menuItemSize())
        {
            cout << "Enter number [1.." << menu->menuItemSize() << "]\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            menu->getUserSelection(&optionSelected);
        }
        
        cout << "Correct input " << optionSelected << "\n";

        // Change Menu based on user selection
        menu->selectItem(optionSelected);

    }
}