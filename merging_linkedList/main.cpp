#include <iostream>
using namespace std;

class Node
{
public:
    int value;
    Node *nextptr;
    Node()
    {
        value = 0;
        nextptr = nullptr;
    }
    Node(int data)
    {
        this->value = data;
        nextptr = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }

    void addNode(int);
    void travelNodes();
};

void LinkedList::addNode(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *traverseNode = head;
    while (traverseNode->nextptr != NULL)
    {
        traverseNode = traverseNode->nextptr;
    }
    traverseNode->nextptr = newNode;
}

void LinkedList::travelNodes()
{
    Node *traverseNode = head;
    if (traverseNode == NULL)
    {
        cout << "No Elements in this linked list" << endl;
        return;
    }
    while (traverseNode != NULL)
    {
        cout << traverseNode->value << " ";
        traverseNode = traverseNode->nextptr;
    }
    cout << endl;
}

void merge(Node *first, Node *second)
{
    if (first == NULL && second == NULL)
    {
        cout << "Both are null." << endl;
        return;
    }
    if (first == NULL || second == NULL)
    {
        cout << "One of the linked list is null." << endl;
        return;
    }

    LinkedList mergedLinkedList;
    Node *traverse1 = first;
    Node *traverse2 = second;

    while (traverse1 != NULL)
    {
        mergedLinkedList.addNode(traverse1->value);
        traverse1 = traverse1->nextptr;
        if (traverse2 != NULL)
        {
            mergedLinkedList.addNode(traverse2->value);
            traverse2 = traverse2->nextptr;
        }
    }
    while (traverse2 != NULL)
    {
        mergedLinkedList.addNode(traverse2->value);
        traverse2 = traverse2->nextptr;
    }
    cout << endl;
    cout << "The new linked list is: " << endl;
    mergedLinkedList.travelNodes();
}

int main()
{
    LinkedList first, second;
    int option, data;
    while (true)
    {
        cout << "1. Insert a node into the first linked list: " << endl;
        cout << "2. Insert a node into the second linked list: " << endl;
        cout << "3. Traverse the linked lists" << endl;
        cout << "4. Merge the two linked lists" << endl;
        cout << "5. Exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter a new node into the first linkedlist: " << endl;
            cin >> data;
            first.addNode(data);
            break;
        case 2:
            cout << "Enter a new node into the second linkedlist: " << endl;
            cin >> data;
            second.addNode(data);
            break;
        case 3:
            cout << "The First linked list is: " << endl;
            first.travelNodes();
            cout << "The second linked list is: " << endl;
            second.travelNodes();
            break;
        case 4:
            merge(first.head, second.head);
            break;
        case 5:
            exit(0);
        default:
            cout << "Wrong option" << endl;
            break;
        }
    }
    return 0;
}