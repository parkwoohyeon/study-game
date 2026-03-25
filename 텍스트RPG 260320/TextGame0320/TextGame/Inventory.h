#pragma once
#include <string>
#include <vector>
#include <iostream>

class Inventory
{
private:
    std::vector<std::string> items;

public:
    void AddItem(const std::string& itemName);
    void ShowItems();
    bool IsEmpty();
    int GetItemCount();

    bool HasItem(const std::string& item) const;
    bool RemoveItem(const std::string& item);
    std::string GetItem(int index);
};