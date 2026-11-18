#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

// functions prototype
void print_linked_list(Node *&list);
void insert_into_linked_list(Node *&list);
void bulid_linked_list(Node *&list, int size);
void free_linked_list(Node *&list);
void delete_from_linked_list(Node *&list);
void display();

int main(void)
{
    // list of nodes
    Node *list = nullptr;

    // user choice
    int choice = 0;

    // check if linked list exits or not
    bool is_linked_list = false;


    display();
    cout << "Please Choice a number: ";
    cin >> choice;

    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            if(!is_linked_list)
            {
                int size;
                cout << "enter the size: ";
                cin >> size;
                bulid_linked_list(list, size);
                is_linked_list = true;
            }

            else
                cout<<"linked List Already Implemented";

            break;

        case 2:
            if(list != nullptr)
                print_linked_list(list);

            else 
            {
                cout<<"Your Linked List is Empty Implement One" <<endl;
                is_linked_list = false;
            }

            break;

        case 3:
            if(list != nullptr)
                insert_into_linked_list(list);

            else 
            {
                cout<<"Your Linked List is Empty Implement One" <<endl;
                is_linked_list = false;
            }

            break;

        case 4:
            if(list != nullptr)
                delete_from_linked_list(list);

            else
            {
                cout<<"Your Linked List is Empty Implement One" <<endl;
                is_linked_list = false;
            }

            break;

        case 5:
            cout << "Bye!" << endl;
            free_linked_list(list);
            return 0;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }

        display();
        cout << "Please Choice a number: ";
        cin >> choice;
    }
}


void display()
{
    cout << endl;
    cout << "--- Welcome! ---" << endl;
    cout << "1. Implement Linked List" << endl;
    cout << "2. Display Linked List" << endl;
    cout << "3. Insert Into The Linked List" << endl;
    cout << "4. Delete From the Linked List" << endl;
    cout << "5. Exit The Program" << endl;
}


// create the linked list data structure
void bulid_linked_list(Node *&list, int size)
{
    // Timpe: O(n)

    // pass through the size
    for (int i = 0; i < size; i++)
    {
        // declare the node at the heap
        Node *node = new Node;

        // insert the value and the next node
        node->value = i + 1;
        node->next = nullptr;

        // if list is empty and does not point to a node
        if (list == nullptr)
        {
            // point to the first node
            list = node;
            continue;
        }

        // if the list already points to a node
        else
        {

            // seach for the itme that points to null (last item in the list)
            for (Node *tmp = list; tmp != nullptr; tmp = tmp->next)
            {
                if (tmp->next == nullptr)
                {
                    tmp->next = node;
                    break;
                }
            }
        }
    }
    cout << "Linked List Has Been Implemented" << endl;
}

// free the heap allocation
void free_linked_list(Node *&list)
{
    // Time: O(n)

    // declare a temporary pointer
    Node *tmp = list;

    // keep freeing until reaching the end of the list
    while (tmp != nullptr)
    {
        // update the list
        list = tmp;

        // update temporary pointer to point to the next item inside the list
        tmp = tmp->next;

        // free that location
        delete list;
    }
}

// print the values of the linked list
void print_linked_list(Node *&list)
{
    // Time: O(n)

    // declare a temporary pointer
    Node *tmp = list;

    // keep printing the values until reaching the end of the list
    while (tmp != nullptr)
    {
        cout << "value: " << tmp->value << endl;

        // update the while condtion
        tmp = tmp->next;
    }
}

// add a new number to the end of the linked list
void insert_into_linked_list(Node *&list)
{
    // Time O(n)

    // the new node that will be add
    Node *node = new Node;
    node->next = nullptr;

    // iterate until the last node of the list
    for (Node *tmp = list; tmp != nullptr; tmp = tmp->next)
    {

        if (tmp->next == nullptr)
        {
            // insert the value of the node
            node->value = tmp->value + 1;

            // link the inserted node
            tmp->next = node;
            cout << "number added" << endl;
            return;
        }
    }
}

// delete the last node from the list
void delete_from_linked_list(Node *&list)
{
    // Time: O(n)

    // keep track of the previous node
    Node *previous = list;

    // find the last node
    for (Node *tmp = list; tmp != nullptr; tmp = tmp->next)
    {
         if (tmp->next == nullptr)
        {
            // update the previous node to point to null (the last node)
            previous->next = nullptr;

            // if the node is the first one update the list to point to null
            if(tmp->value == 1)
                list = nullptr;

            // free memoery of the last node
            delete tmp;
            cout << "number deleted" << endl;
            return;
        }
        
        // update the previous node
        previous = tmp;
    }
}