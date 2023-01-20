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
        next = NULL;
        prev = NULL;
    }
};

class DoubleLinkedList
{
public:
    Node *head;
    DoubleLinkedList()
    {
        head = NULL;
    }
    void insertNodeAtEnd(int);
    void insertNodeAtStart(int);
    void insertNodeInMiddleAfter(int, int);
    void insertNodeInMiddleBefore(int, int);
    void traverseNodes();
    void reverseTraverseNodes();
};

void DoubleLinkedList::insertNodeAtEnd(int data)
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
    newNode->prev = temp;
    newNode->next = NULL;
    temp->next = newNode;
}

void DoubleLinkedList::insertNodeAtStart(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    newNode->next = temp;
    newNode->prev = NULL;
    temp->prev = newNode;
    head = newNode;
}

void DoubleLinkedList::insertNodeInMiddleAfter(int data, int position)
{
    Node *traverse = head;
    Node *newNode = new Node(data);
    if (traverse == NULL)
    {
        cout << "positioned node does not exist, as the linked list is currently empty." << endl;
        return;
    }
    while (traverse != NULL)
    {
        if (traverse->data != position)
        {
            traverse = traverse->next;
        }
        else
        {
            if (traverse->next == NULL && traverse->data == position)
            {
                traverse->next = newNode;
                newNode->prev = traverse;
                newNode->next = NULL;
                return;
            }
            else
            {
                Node *nextElement = traverse->next;
                newNode->next = nextElement;
                newNode->prev = traverse;
                nextElement->prev = newNode;
                traverse->next = newNode;
                return;
            }
        }
    }
    if (traverse == NULL)
    {
        cout << "Node does not exit" << endl;
    }
}

void DoubleLinkedList::insertNodeInMiddleBefore(int data, int position)
{
    Node *traverse = head;
    Node *newNode = new Node(data);
    if (traverse == NULL)
    {
        cout << "positioned node does not exist, as the linked list is currently empty." << endl;
        return;
    }
    else if (traverse->data == position)
    {
        insertNodeAtStart(data);
        return;
    }
    while (traverse != NULL)
    {
        if (traverse->data != position)
        {
            traverse = traverse->next;
        }
        else
        {
            Node *previousElement = traverse->prev;
            newNode->prev = previousElement;
            newNode->next = traverse;
            previousElement->next = newNode;
            traverse->prev = newNode;
            return;
        }
    }
}

void DoubleLinkedList::traverseNodes()
{
    Node *traverse = head;
    if (traverse == NULL)
    {
        cout << "No nodes to traverse" << endl;
        return;
    }
    cout << "The nodes in the linked list are." << endl;
    while (traverse != NULL)
    {
        cout << traverse->data << " ";
        traverse = traverse->next;
    }
    cout << endl;
}

void DoubleLinkedList::reverseTraverseNodes()
{
    Node *reverse = head;
    while (reverse->next != NULL)
    {
        reverse = reverse->next;
    }

    while (reverse != head)
    {
        cout << reverse->data << " ";
        reverse = reverse->prev;
    }
    reverse = reverse->prev;
    cout << reverse->data << " ";
    cout << endl;
}
int main(int argc, char **argv)
{
    DoubleLinkedList dl1;
    int option, data, position;
    while (true)
    {
        cout << "1. Insert a node at the end of a linked list." << endl;
        cout << "2. Insert a node in the start of a linked list." << endl;
        cout << "3. Insert a node at an after index of a linked list." << endl;
        cout << "4. Insert a node at an before index of a linked list." << endl;
        cout << "5. Traverse the linked list." << endl;
        cout << "6. Reverse traverse the linked list." << endl;
        cout << "7. Exit." << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter data for the node: " << endl;
            cin >> data;
            dl1.insertNodeAtEnd(data);
            break;
        case 2:
            cout << "Enter data for the node: " << endl;
            cin >> data;
            dl1.insertNodeAtStart(data);
            break;
        case 3:
            cout << "Enter data for the node: " << endl;
            cin >> data;
            cout << "Enter the node after which you want to insert." << endl;
            cin >> position;
            dl1.insertNodeInMiddleAfter(data, position);
            break;
        case 4:
            cout << "Enter data for the node: " << endl;
            cin >> data;
            cout << "Enter the node before which you want to insert." << endl;
            cin >> position;
            dl1.insertNodeInMiddleBefore(data, position);
            break;
        case 5:
            dl1.traverseNodes();
            break;
        case 6:
            dl1.reverseTraverseNodes();
            break;
        case 7:
            return 0;
        default:
            cout << "Wrong input." << endl;
            break;
        }
    }
    return 0;
}