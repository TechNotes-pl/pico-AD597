#include "Menu.h"

void Menu::display()
{
    menuItemPtr = menuItemsStack.top();
    cout << "'" << menuItemPtr->name << "' menu item:\n";

    int itemNumber = 0;
    for (auto item : menuItemPtr->getChildren())
    {
        cout << ++itemNumber << ": " << item->name << "\n";
    }
}

bool Menu::getUserSelection(int *itemNumber)
{
    string userInput;

    // Read & validate menu item number
    cin >> userInput;
    *itemNumber = 0;
    try
    {
        *itemNumber = stoi(userInput);
    }
    catch (std::invalid_argument &e)
    {
        // if no conversion could be performed
        cerr << "Number please\n";
        return false;
    }
    catch (std::out_of_range &e)
    {
        // if the converted value would fall out of the range of the result type
        // or if the underlying function (std::strtol or std::strtoull) sets errno
        // to ERANGE.
        cerr << "Out of range\n";
        return false;
    }
    catch (...)
    {
        // everything else
        cerr << "Error\n";
        return false;
    }

    return true;
}
