#include "chapter6Task1.h"

enum class itemTypes {
    HEALTHPOTION,
    TORCH,
    ARROW,
    MAX_ITEMS
};

int countTotalItems(const int *items) {
    int itemsTotal(0);
    for (int i = 0; i < static_cast<int>(itemTypes::MAX_ITEMS); ++i)
        itemsTotal += items[i];
    return itemsTotal;
}

void chapter6Task1() {
    int items[static_cast<int>(itemTypes::MAX_ITEMS)] { 3, 6, 12 };

    std::cout << "Items total: " << countTotalItems(items);
}

