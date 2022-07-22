#pragma once

#include <iostream>
#include <stack>
#include <stdexcept>
#include "MenuItem.h"

class Menu
{
private:
	// The menuItemsStack is to keep track of which (sub)MenuItem you are in,
	// and menuItem tells you which item in the current MenuItem is selected.
	// Navigating them becomes a matter of incrementing/decrementing menuItem
	// to go up and down the currently selected MenuItem,
	// and pushing/popping MenuItems to the stack to go deeper or going out of MenuItems.
	stack<MenuItem *> menuItemsStack;

	MenuItem *menuItemPtr = nullptr;

public:
	/*
	*	C++11 allows constructor chaining (partially).
	*	This feature is called "delegating constructors", ex.:

			Menu(string name, Menu* prev, Menu* up, Menu* down, Menu* right) :
				name(name), prev(prev), right(right), down(down), up(up) {}

			Menu(string name) : Menu(name, nullptr, nullptr, nullptr, nullptr) {}
	*/

	// Constructor
	Menu(MenuItem *rootItem)
	{
		menuItemsStack.push(rootItem);
	}

	int menuItemSize()
	{
		return menuItemPtr->size();
	}

	static bool getUserSelection(int *);

	void display();

	void selectItem(int itemNumber)
	{
		menuItemsStack.push(menuItemPtr->getChild(itemNumber - 1));
	}
};