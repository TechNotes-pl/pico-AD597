#pragma once

#include <string>
#include <vector>

using namespace std;

class MenuItem
{
private:
    vector<MenuItem *> children;

public:
    const string name;

    MenuItem(const string &name, MenuItem *parent = nullptr) : name(name)
    {
        if (parent)
        {
            parent->children.push_back(this);
        }
    }

    MenuItem *getChild(int i)
    {
        return children[i];
    }

    vector<MenuItem *> getChildren()
    {
        return children;
    }

    int size()
    {
        return (int)children.size();
    }
};
