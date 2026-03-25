#include "Inventory.h"
#include <iostream>

void Inventory::AddItem(const std::string& itemName) {
	items.push_back(itemName);
	std::cout << itemName << "을(를)  인벤토리에 추가했습니다.\n";

		
}

void Inventory::ShowItems() {
	std::cout << "\n========= 인벤토리 =============\n";

	if (items.empty()) {
		std::cout << "인벤토리가 비어 있습니다\n";
		return;
	}
	
	for (int i = 0; i < items.size(); i++) {
		std::cout << i + 1 << ". " << items[i] << '\n';
	}
}

bool Inventory::IsEmpty() {
	return items.empty();
}

int Inventory::GetItemCount() {
	return (int)items.size();
}

bool Inventory::HasItem(const std::string& item) const
{
    for (const auto& it : items)
    {
        if (it == item)
        {
            return true;
        }
    }
    return false;
}

bool Inventory::RemoveItem(const std::string& item)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (*it == item)
        {
            items.erase(it);
            return true;
        }
    }
    return false;
}

std::string Inventory::GetItem(int index)
{
    if (index < 0 || index >= items.size())
        return "";

    return items[index];
}