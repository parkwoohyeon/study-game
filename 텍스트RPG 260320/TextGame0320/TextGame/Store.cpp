#include "Store.h"

Store::Store()
{
    items.push_back({ "포션", 30 });
    items.push_back({ "철검", 100 });
    items.push_back({ "가죽 갑옷", 120 });
}

void Store::ItemList()
{
    std::cout << "\n========== 상점 ==========\n";

    for (int i = 0; i < items.size(); i++)
    {
        std::cout << i + 1 << ". " << items[i].name
                  << " - " << items[i].price << " Gold\n";
    }

    std::cout << items.size() + 1 << ". 나가기\n";
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