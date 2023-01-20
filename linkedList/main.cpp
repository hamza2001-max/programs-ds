#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insertNodeAtStart(int);
    void insertNodeAtEnd(int);
    void insertNodeAtIndex(int, int);
    void deleteNode(int);
    void traverse();
};

void LinkedList::insertNodeAtStart(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    newNode->next = temp;
    head = newNode;
}

void LinkedList::insertNodeAtEnd(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::insertNodeAtIndex(int data, int position)
{
    Node *newNode = new Node(data);
    Node *temp1 = head, *temp2 = nullptr;
    int counter = 0;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    if (position == 1)
    {
        newNode->next = temp1;
        head = newNode;
        return;
    }
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        counter++;
    }
    counter += 1;
    if (position > counter)
    {
        cout << "No position does not exist yet, insert in the range of " << counter << " nodes." << endl;
        return;
    }
    temp1 = head;
    while (position-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    newNode->next = temp1;
    temp2->next = newNode;
}

void LinkedList::deleteNode(int position)
{
    Node *temp1 = head, *temp2 = nullptr;
    int counter = 0;
    if (head == NULL)
    {
        cout << "No nodes to delete." << endl;
        return;
    }
    while (temp1 != NULL)
    {
        temp1 = temp1->next;
        counter++;
    }
    if (position > counter)
    {
        cout << "No node exists at this position." << endl;
        return;
    }

    temp1 = head;
    if (position == 1)
    {
        cout << "First node deleted." << endl;
        head = head->next;
        delete temp1;
        temp1 = nullptr;
        return;
    }

    cout << "Node at position " << position << " deleted." << endl;
    while (position-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete temp1;
    temp1 = nullptr;
}

void LinkedList::traverse()
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "No nodes to traverse." << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int option, data, position;
    LinkedList l1;
    while (true)
    {
        cout << "1. Insert a node in the start of a linked list." << endl;
        cout << "2. Insert a node in the end of a linked list." << endl;
        cout << "3. Insert a node at any index of a linked list." << endl;
        cout << "4. Delete a node in the linked list." << endl;
        cout << "5. Traverse the linked list." << endl;
        cout << "6. Exit." << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter data for the node: " << endl;
            cin >> data;
            l1.insertNodeAtStart(data);
            break;
        case 2:
            cout << "Enter data for the node: " << endl;
            cin >> data;
            l1.insertNodeAtEnd(data);
            break;
        case 3:
            cout << "Enter data for the node: " << endl;
            cin >> data;
            cout << "Enter the position where you want to insert the node" << endl;
            cin >> position;
            l1.insertNodeAtIndex(data, position);
            break;
        case 4:
            cout << "Enter the position of a node you want to delete." << endl;
            cin >> position;
            l1.deleteNode(position);
            break;
        case 5:
            cout << "The nodes in the linked list are." << endl;
            l1.traverse();
            break;
        case 6:
            return 0;
        default:
            cout << "Wrong input." << endl;
            ;
            break;
        }
    }
    return 0;
}