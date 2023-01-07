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

    void addNode(char data);
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
    Node *traverser = head;
    string reverse;
    cout << "forward" << endl;
    while (traverser != NULL)
    {
        cout << traverser->data;
        reverse.push_back(traverser->data);
        traverser = traverser->nextptr;
    }
    cout << "\nreverse" << endl;
    for (int i = reverse.length() - 1; i >= 0; i--)
    {
        cout << reverse[i];
    }
}

int main()
{
    LinkedList l1;
    l1.addNode('h');
    l1.addNode('e');
    l1.addNode('l');
    l1.addNode('l');
    l1.addNode('o');
    l1.traverser();
    // cout << "hello" << endl;
    return 0;
}