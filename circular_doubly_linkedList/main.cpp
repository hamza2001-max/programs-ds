#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class CDoubleLinkedList
{
public:
    Node *head;
    CDoubleLinkedList()
    {
        head = NULL;
    }

    void addNode(int);
    void traverse();
    void reverseTraverse();
};

void CDoubleLinkedList::addNode(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        head->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next == head)
            break;
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = head;
}

void CDoubleLinkedList::traverse()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        if (temp->next == head)
        {
            cout << "[circle complete]" << ' ';
            cout << temp->next->data << ' ';
            cout << endl;
            return;
        }
        temp = temp->next;
    }
}

void CDoubleLinkedList::reverseTraverse()
{
    Node *reverse = head;
    while (reverse->next != NULL)
    {
        reverse = reverse->next;
    }

    while (reverse != head)
    {
        cout << reverse->data << ' ';
        reverse = reverse->prev;
    }
    cout << endl;
}

int main()
{
    CDoubleLinkedList cdl1;
    cdl1.addNode(23);
    cdl1.addNode(29);
    cdl1.addNode(2);
    cdl1.addNode(3);
    cdl1.traverse();
    cdl1.reverseTraverse();
    return 0;
}