#include <iostream>
#include <cmath>
using namespace std;

class Node
{
public:
    int data;
    Node *leftNode;
    Node *rightNode;
    Node(int data)
    {
        this->data = data;
        this->leftNode = nullptr;
        this->rightNode = nullptr;
    }
};

int SearchInorder(int inorder[], int start, int end, int currentElement)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] = currentElement)
        {
            return i;
        }
    }
    return -1;
}

Node *buildATree(int preorder[], int inorder[], int start, int end)
{
    static int index = 0;
    if (start > end)
    {
        return NULL;
    }
    int currentElement = preorder[index];
    index++;
    Node *newNode = new Node(currentElement);

    if (start == end)
    {
        return newNode;
    }
    int position = SearchInorder(inorder, start, end, currentElement);
    newNode->leftNode = buildATree(preorder, inorder, start, position - 1);
    newNode->rightNode = buildATree(preorder, inorder, position + 1, end);
    return newNode;
}

void traverseNodes(Node *rootNode)
{
    if (rootNode == NULL)
    {
        return;
    }
    traverseNodes(rootNode->leftNode);
    cout << rootNode->data << " ";
    traverseNodes(rootNode->rightNode);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *rootNode = buildATree(preorder, inorder, 0, 4);
    traverseNodes(rootNode);
    return 0;
}