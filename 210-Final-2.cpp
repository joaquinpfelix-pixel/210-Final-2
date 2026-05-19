// COMSC-210 | Final 2 | Joaquin Felix

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>

using namespace std;

struct Node 
{
    string customer_name;
    string drink_order;
    Node* next;
};

const int NAME_COUNT = 10;
const int DRINK_COUNT = 10;
const int ROUNDS = 10;

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

// Generated using an llm
string muffins[5] = {
    "Blueberry",
    "Chocolate Chip",
    "Banana Nut",
    "Pumpkin",
    "Cinnamon"
};

int main()
{
    srand(time(0));

    Node* head = nullptr;
    Node* tail = nullptr;

    deque<string> muffin_queue;

    for (int i = 0; i < 3; i++)
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

    for (int i = 0; i < 3; i++)
    {
        string customer =
            names[rand() % NAME_COUNT];
        
        string muffin =
            muffins[rand() % 5];
        
        muffin_queue.push_back(
            customer + " ordered " + muffin
        );
    }

    for (int round = 1; round <= ROUNDS; ++round)
    {
        cout << "Round " 
             << round
             << endl;
        
        if (head != nullptr)
        {
            cout << head->customer_name
                 << " received "
                 << head->drink_order
                 << endl;
            
            Node* temp = head;
            head = head->next;
            delete temp;

            if (head == nullptr)
            {
                tail = nullptr;
            }
        }
        else
        {
            cout << "No customer to serve."
                 << endl;
        }

        if (rand() % 2 == 0)
        {
            Node* new_node = new Node;

            new_node->customer_name =
                names[rand() % NAME_COUNT];

            new_node->drink_order =
                drinks[rand() % DRINK_COUNT];
            
            new_node->next = nullptr;

            cout << new_node->customer_name
                 << " joined the coffee line."
                 << endl;

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

        cout << endl;

        cout << "Muffin Booth:"
             << endl;

        if (!muffin_queue.empty())
        {
            cout << muffin_queue.front()
                 << endl;

            muffin_queue.pop_front();
        }
        else
        {
            cout << "No muffin customer."
                 << endl;
        }

        if (rand() % 2 == 0)
        {
            string customer =
                names[rand() % NAME_COUNT];
            
            string muffin = 
                muffins[rand() % 5];

            muffin_queue.push_back(
                customer + " ordered " + muffin
            );

            cout << customer
                 << " joined muffin line."
                 << endl;
        }

        cout << endl;
    }

    return 0;
}