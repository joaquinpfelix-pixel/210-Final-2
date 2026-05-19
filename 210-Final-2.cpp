// COMSC-210 | Final 2 | Joaquin Felix

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node 
{
    string customer_name;
    string drink_order;
    Node* next;
};

const int NAME_COUNT = 10;
const int DRINK_COUNT = 10;

// Generated using an llm
string names[NAME_COUNT] = {
    "Alex",
    "Jordan",
    "Taylor",
    "Morgan",
    "Casey",
    "Jamie",
    "Riley",
    "Avery",
    "Cameron",
    "Parker"
};

// Generated using an llm
string drinks[DRINK_COUNT] = {
    "Latte",
    "Mocha",
    "Espresso",
    "Americano",
    "Cold Brew",
    "Cappuccino",
    "Macchiato",
    "Tea",
    "Hot Chocolate",
    "Iced Coffee"
};

int main()
{
    srand(time(0));

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < 10; ++i)
    {
        Node* new_node = new Node;

        new_node->customer_name =
            names[rand() % NAME_COUNT];
        new_node->drink_order =
            drinks[rand() % DRINK_COUNT];
        
        new_node->next = nullptr;

        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    cout << "Coffee Booth Queue:" << endl;
    
    Node* current = head;

    while (current != nullptr)
    {
        cout << current->customer_name
             << " ordered "
             << current->drink_order
             << endl;
        
        current = current->next;
    }

    return 0;
}