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

class Stack
{
public:
    Node *head;
    Stack()
    {
        head = NULL;
    }
    void push(int);
    void pop();
    void traverse();
};

class Queue
{
public:
    Node *head;
    Queue()
    {
        head = NULL;
    }
    void enqueue(int);
    void dequeue();
    void traverse();
};

void Stack::push(int data)
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

void Stack::pop()
{
    Node *temp1 = head;
    Node *temp2 = NULL;
    while (temp1->next != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = nullptr;
    delete temp1;
    temp1 = nullptr;
}

void Stack::traverse()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Queue::enqueue(int data)
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

void Queue::dequeue()
{
    Node *temp1 = head;
    Node *temp2 = head;
    temp1 = temp1->next;
    head = temp1;
    delete temp2;
    temp2 = NULL;
}

void Queue::traverse()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;

    }
    cout << endl;
}

int main()
{
    int option1, option2, data;
    Queue q1;
    Stack s1;

    while (true)
    {
        cout << "1) Use Stack." << endl;
        cout << "2) Use Queue." << endl;
        cin >> option1;

        switch (option1)
        {

        case 1:
            cout << "Stack." << endl;
            cout << "1) add Node." << endl;
            cout << "2) delete Node." << endl;
            cout << "3) traverse." << endl;
            cout << "4) Exit." << endl;
            cin >> option2;

            switch (option2)
            {
            case 1:
                cout << "Enter data: " << endl;
                cin >> data;
                s1.push(data);
                break;
            case 2:
                s1.pop();
                break;
            case 3:
                s1.traverse();
                break;
            case 4:
                return false;
            default:
                cout << "wrong input." << endl;
                break;
            }
            break;

        case 2:
            cout << "Queue." << endl;
            cout << "1) add Node." << endl;
            cout << "2) delete Node." << endl;
            cout << "3) traverse." << endl;
            cin >> option2;

            switch (option2)
            {
            case 1:
                cout << "Enter data: " << endl;
                cin >> data;
                q1.enqueue(data);
                break;
            case 2:
                q1.dequeue();
                break;
            case 3:
                q1.traverse();
                break;
            case 4:
                return false;
            default:
                cout << "wrong input." << endl;
                break;
            }
            break;
        }
    }
    return 0;
}
