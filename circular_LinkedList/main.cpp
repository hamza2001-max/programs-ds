#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
    Node()
    {
        data = 0;
        next = nullptr;
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

    void insertNode(int);
    void traverseNodes();
    void deleteNode(int);
};

void LinkedList::insertNode(int data)
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
        if (temp->next == head)
            break;
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void LinkedList::traverseNodes()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        if (temp->next->data == head->data)
        {
            cout << "[circle complete]" << ' ';
            cout << temp->next->data;
            cout << endl;
            return;
        }
        temp = temp->next;
    }
}

void LinkedList::deleteNode(int position)
{
    Node *temp1 = head;
    Node *temp2 = NULL;
    if (position == 1)
    {
        temp1 = temp1->next;
        head = temp1;
        delete temp1;
        return;
    }
    while (position-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete temp1;
    temp1 = NULL;
}

int main()
{
    LinkedList l1;
    l1.insertNode(22);
    l1.insertNode(23);
    l1.insertNode(24);
    l1.insertNode(7);
    l1.insertNode(9);
    l1.insertNode(2);
    l1.traverseNodes();
    l1.deleteNode(4);
    l1.traverseNodes();
    return 0;
}