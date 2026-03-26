#include "Store.h"

#include "Store.h"

Store::Store()
{
    items.push_back({ "포션", 30 });

    items.push_back({ "나무검", 50 });
    items.push_back({ "철검", 100 });
    items.push_back({ "강철검", 180 });

    items.push_back({ "천갑옷", 40 });
    items.push_back({ "가죽갑옷", 120 });
    items.push_back({ "사슬갑옷", 220 });
}

void Store::ItemList()
{
    std::cout << "\n==================================================\n";
    std::cout << "                      SHOP\n";
    std::cout << "==================================================\n";
    std::cout << "상인 : 필요한 물건이 있으면 골라보게.\n";
    std::cout << "--------------------------------------------------\n";

    for (int i = 0; i < (int)items.size(); i++)
    {
        std::cout << "[" << i + 1 << "] "
            << items[i].name
            << "  -  "
            << items[i].price << " G\n";
    }

    std::cout << "[" << items.size() + 1 << "] 상점을 나간다\n";
    std::cout << "==================================================\n";
}

void Store::EnterShop(Player& player)
{
    int input = 0;

    while (true)
    {
        ItemList();
        std::cout << "구매할 아이템을 선택하세요\n -> ";
        std::cin >> input;

        if (input >= 1 && input <= items.size())
        {
            Item selectedItem = items[input - 1];

            if (player.Removemoney(selectedItem.price))
            {
                player.GetInventory().AddItem(selectedItem.name);
                std::cout << selectedItem.name << " 구매 완료!\n";
            }
            else
            {
                std::cout << "돈이 부족합니다.\n";
            }
        }
        else if (input == items.size() + 1)
        {
            std::cout << "상점을 나갑니다.\n";
            break;
        }
        else
        {
            std::cout << "잘못된 입력입니다.\n";
        }
    }
}