#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *rightNode;
    Node *leftNode;

    Node(int data)
    {
        this->data = data;
        leftNode = nullptr;
        rightNode = nullptr;
    }
};

Node *insertNode(Node *rootNode, int data)
{
    if (rootNode == NULL)
    {
        rootNode = new Node(data);
        return rootNode;
    }
    if (rootNode->data >= data)
    {
        rootNode->leftNode = insertNode(rootNode->leftNode, data);
    }
    else if (rootNode->data < data)
    {
        rootNode->rightNode = insertNode(rootNode->rightNode, data);
    }
    return rootNode;
}

void preorderTraversal(Node *rootNode)
{
    if (rootNode != NULL)
    {
        cout << rootNode->data << " ";
        preorderTraversal(rootNode->leftNode);
        preorderTraversal(rootNode->rightNode);
    }
}

void inorderTraverse(Node *rootNode)
{
    if (rootNode != NULL)
    {
        inorderTraverse(rootNode->leftNode);
        cout << rootNode->data << " ";
        inorderTraverse(rootNode->rightNode);
    }
}

void postorderTraversal(Node *rootNode)
{
    if (rootNode != NULL)
    {
        postorderTraversal(rootNode->leftNode);
        postorderTraversal(rootNode->rightNode);
        cout << rootNode->data << " ";
    }
}
int main()
{
    int option, data;
    Node *bt = NULL;
    while (true)
    {
        cout << "1.Insert Node in tree." << endl;
        cout << "2.Traverse Tree through preorder traversal." << endl;
        cout << "3.Traverse Tree through inorder traversal." << endl;
        cout << "4.Traverse Tree through postorder traversal." << endl;
        cout << "5.Exit." << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "Enter data: " << endl;
            cin >> data;
            bt = insertNode(bt, data);
            break;
        case 2:
            if (bt == NULL)
            {
                cout << "No tree to traverse" << endl;
                break;
            }
            cout << "The binary tree contains." << endl;
            preorderTraversal(bt);
            break;
        case 3:
            if (bt == NULL)
            {
                cout << "No tree to traverse" << endl;
                break;
            }
            cout << "The binary tree contains." << endl;
            inorderTraverse(bt);
            break;
        case 4:
            if (bt == NULL)
            {
                cout << "No tree to traverse" << endl;
                break;
            }
            cout << "The binary tree contains." << endl;
            postorderTraversal(bt);
            break;
        case 5:
            return false;
        default:
            cout << "Wrong input." << endl;
            break;
        }
    }
    return 0;
}