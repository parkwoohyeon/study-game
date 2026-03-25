#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

struct Item
{
    std::string name;
    int price;
};

class Store
{
private:
    std::vector<Item> items;

public:
    Store();
    void ItemList();
    void EnterShop(Player& player);
};