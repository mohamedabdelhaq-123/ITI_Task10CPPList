#include <iostream>
#include <string>
#include "funcsHeader.h"

int main() {
    Item* list = nullptr;
    int size = 0;
    int capacity = 10;

    list = new Item[capacity];
    getUserInput(list, size, capacity);
    printList(list, size);
    delete[] list;

    return 0;
}
