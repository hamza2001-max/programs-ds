#include <iostream>
using namespace std;

class Node
{
public:
    char data;
    Node *nextptr;
    Node(char data)
    {
        this->data = data;
        nextptr = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = NULL;
    }

    void addNode(char);
    void traverser();
};

void LinkedList::addNode(char data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *traverser = head;
    while (traverser->nextptr != NULL)
    {
        traverser = traverser->nextptr;
    }
    traverser->nextptr = newNode;
}

void LinkedList::traverser()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->nextptr;
    }
}

Node *copyLinkedList(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *newLinkedList = new Node(head->data);
    // newLinkedList->data = ;
    newLinkedList->nextptr = copyLinkedList(head->nextptr);

    return newLinkedList;
}

int main()
{
    LinkedList l1;
    l1.addNode('e');
    l1.addNode('b');
    l1.addNode('v');
    l1.addNode('c');
    l1.traverser();
    LinkedList l2;
    cout << endl;
    l2.head = copyLinkedList(l1.head);
    l2.traverser();
    return 0;
}