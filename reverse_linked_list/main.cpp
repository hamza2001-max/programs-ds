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
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }
    void insertNode(int);
    void reverseLinkedList(Node*);
    void print();
};

void LinkedList::insertNode(int value)
{
    Node *newNode = new Node(value);
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

void LinkedList::reverseLinkedList(Node* value){
    Node* temp1 = value;
    if(temp1->next == NULL){
        head = temp1;
        return;
    }
    reverseLinkedList(temp1->next);
    Node* temp2 = temp1->next;
    temp2->next = temp1;
    temp1->next = NULL; 
    // print(head);
    // print();
}

void LinkedList::print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    LinkedList chain;
    chain.insertNode(1);
    chain.insertNode(2);
    chain.insertNode(1);
    chain.insertNode(5);
    cout << "The values in chain are: " << endl;
    chain.print();
    cout << "\nThe reversed linked list is: " << endl;
    chain.reverseLinkedList(chain.head);
    chain.print();
    return 0;
}