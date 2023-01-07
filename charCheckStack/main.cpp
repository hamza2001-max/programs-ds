#include <iostream>
using namespace std;
void push(char[], char, int &, int);
void pop(int &);
bool isValid(char[], string, int &, int);
bool isFull(int, int);
bool isEmpty(int);
int main()
{
    int size = 20, top = -1;
    string expression;
    char stack[size];
    char alphabet;
    cout << "Enter an expression:" << endl;
    cin >> expression;
    bool validity = isValid(stack, expression, top, size);
    if (validity)
    {
        cout << "Valid expression" << endl;
    }
    else
    {
        cout << "Invalid expression" << endl;
    }
    return 0;
}

void push(char stack[], char alphabet, int &top, int size)
{
    cout << alphabet << endl;
    if (isFull(top, size))
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    if (!isFull(top, size))
    {
        top++;
        stack[top] = alphabet;
    }
}

void pop(int &top)
{
    if (isEmpty(top))
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    top--;
}

bool isValid(char stack[], string expression, int &top, int size)
{
    char alphabet;
    for (int i = 0; i < expression.length(); i++)
    {
        alphabet = expression[i];
        if (alphabet == '(')
        {
            push(stack, alphabet, top, size);
        }
        else if (isEmpty(top))
        {
            return false;
        }
        else if (alphabet == ')')
        {
            pop(top);
        }
    }
    return true;
}

bool isFull(int top, int size)
{
    if (top == size)
    {
        return true;
    }
    return false;
}

bool isEmpty(int top)
{
    if (top < 0)
    {
        return true;
    }
    return false;
}

// #include <iostream>
// using namespace std;

// void push(char[], char, int &, int);
// bool checkExpression(char[], int, int);
// void pop(char[], int &, int);
// bool isEmpty(int);
// bool isFull(int, int);

// int main(int argc, char **argv)
// {
//     int top = -1;
//     int size = 10;
//     char token;
//     char stack[size];

//     bool valid = checkExpression(stack, top, size);
//     if (valid)
//     {
//         std::cout << "Valid expression";
//     }
//     else
//     {
//         std::cout << "In valid expression";
//     }
//     return 0;
// }

// bool checkExpression(char stack[], int top, int size)
// {
//     char token;
//     string expression;
//     std::cout << "Enter the expression: ";
//     std::cin >> expression;

//     for (int i = 0; i < expression.length(); i++)
//     {
//         token = expression[i];
//         if (token == '(')
//         {
//             push(stack, token, top, size);
//         }
//         else if (isEmpty(top))
//         {
//             return false;
//         }
//         else
//         {
//             pop(stack, top, size);
//         }
//     }
//     return true;
// }

// void push(char stack[], char item, int &top, int size)
// {
//     if (!isFull(top, size) == true)
//     {
//         top++;
//         stack[top] = item;
//     }
//     else
//     {
//         cout << "Stack overflow" << endl;
//     }
// }

// bool isFull(int top, int size)
// {
//     if (top < size - 1)
//     {
//         return false;
//     }
//     return true;
// }

// void pop(char stack[], int &top, int size)
// {
//     if (isEmpty(top))
//     {
//         cout << "stack underflow" << endl;
//         // return 0;
//         exit(0);
//     }

//     char item = stack[top];
//     top--;
// }

// bool isEmpty(int top)
// {
//     if (top < 0)
//     {
//         return true;
//     }
//     return false;
// }