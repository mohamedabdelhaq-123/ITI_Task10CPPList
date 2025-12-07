#include "funcsHeader.h"
using namespace std;


struct Item {
    string type;
    int intVal;
    float floatVal;
    string stringVal;
    bool boolVal;
};


bool isInteger(string str) {    // Function to check if a string is an integer
    if (str.empty())
        return false;

    int start = 0;
    if (str[0] == '-')
    {
        if (str.length() == 1)
        return false;
        start = 1;
    }

    for (int i = start; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}


Item createItem(string input) {                    // Function to determine type and create an Item
    Item newItem;


    if (input == "true" || input == "false")    // Check if it's a boolean
    {
        newItem.type = "bool";
        newItem.boolVal = (input == "true");
    }
    else if (input.find('.') != string::npos)  // Check if it's a float (contains a decimal point)
    {
        newItem.type = "float";
        newItem.floatVal = stof(input);
    }
    else if (isInteger(input))                  // Check if it's an integer
    {
        newItem.type = "int";
        newItem.intVal = stoi(input);
    }
    else                                               // else it's a string
    {
        newItem.type = "string";
        newItem.stringVal = input;
    }

    return newItem;
}


Item* expandList(Item* oldList, int oldCapacity, int newCapacity, int size)   // Function to expand the list capacity
{
    Item* newList = new Item[newCapacity];
    // Copy old items to new array
    for (int i = 0; i < size; i++) {
        newList[i] = oldList[i];
    }

    delete[] oldList;  // Free old memory
    return newList;
}


void addItem(Item*& list, int& Size, int& capacity, string input)              // Function to add an item to the list
{
    // Check if we need to expand the array
    if (Size == capacity)
    {
        capacity *= 2;  // Double the capacity
        list = expandList(list, capacity / 2, capacity, Size);
    }

    // Create and add the new item
    list[Size] = createItem(input);
    Size++;
}


void printItem(Item item)
{
    if (item.type == "int")
    {
        cout << item.intVal;
    }
    else if (item.type == "float")
    {
        cout << item.floatVal;
    }
    else if (item.type == "string")
    {
        cout << "'" << item.stringVal << "'";
    }
    else if (item.type == "bool")
    {
        cout << (item.boolVal ? "true" : "false");
    }
}

// Function to print the entire list
void printList(Item* list, int size) {
    cout <<endl<< "=== The List ==="<<endl;
    cout << "[";

    for (int i = 0; i < size; i++)
    {
        printItem(list[i]);
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << "]"<<endl;
}


void getUserInput(Item*& list, int& size, int& capacity)
{
    cout << "Enter values (type 'exit' to stop):"<<endl;
    cout << "You can enter your list "<<endl;

    string input;

    while (true)
    {
        cout << "Enter value: ";
        cin >> input;
        if(input == "exit")
            break;
        addItem(list, size, capacity, input);
    }
}
