#include <iostream>
using namespace std;

string infixToPostfix(string);
string infixToPrefix(string);

void push(char[], char, int &, int);
char pop(char[], int &);

void evaluatePush(int[], int &, int);
int evaluatePop(int[], int &);
void evaluate(string);

bool isFull(int, int);
bool isEmpty(int);

bool operatorChecker(char);
int precedence(char);

int main()
{
    string infixExpression;
    int top = -1, size = 30;
    char stack[size];

    cout << "Enter the expression" << endl;
    getline(cin, infixExpression);
    string postfixExpression = infixToPostfix(infixExpression);
    string prefixExpression = infixToPrefix(infixExpression);

    cout << "The postfix expression is: " << endl;
    cout << postfixExpression << endl;
    cout << "The prefix expression is: " << endl;
    cout << prefixExpression << endl;
    evaluate(postfixExpression);
    return 0;
}

string infixToPostfix(string infixExpression)
{
    int top = -1, size = 30;
    string postfixExpression;
    char stack[size];
    for (int i = 0; i < infixExpression.length(); i++)
    {
        if (infixExpression[i] == '(')
        {
            push(stack, infixExpression[i], top, size);
        }

        else if (infixExpression[i] == ')')
        {
            while ((stack[top] != '('))
            {
                postfixExpression += stack[top];
                pop(stack, top);
            }
            pop(stack, top);
        }

        else if (!operatorChecker(infixExpression[i]))
        {
            postfixExpression += infixExpression[i];
        }

        else if (operatorChecker(infixExpression[i]))
        {
            while (!isEmpty(top) && precedence(infixExpression[i]) <= precedence(stack[top]))
            {
                postfixExpression += stack[top];
                pop(stack, top);
            }
            push(stack, infixExpression[i], top, size);
        }
    }

    while (!isEmpty(top))
    {
        postfixExpression += stack[top];
        pop(stack, top);
    }
    return postfixExpression;
}

string infixToPrefix(string infixExpression)
{
    int top = -1, size = 30;
    string prefixExpression, reverse;
    string tempExpression;
    char stack[size];
    for(int i = infixExpression.length() - 1; i >= 0; i--)
    {
        tempExpression += infixExpression[i];
    }
    for (int i = 0; i < tempExpression.length(); i++)
    {
        if (tempExpression[i] == ')')
        {
            push(stack, tempExpression[i], top, size);
        }

        else if (tempExpression[i] == '(')
        {
            while ((stack[top] != ')'))
            {
                prefixExpression += stack[top];
                pop(stack, top);
            }
            pop(stack, top);
        }

        else if (!operatorChecker(tempExpression[i]))
        {
            prefixExpression += tempExpression[i];
        }

        else if (operatorChecker(tempExpression[i]))
        {
            while (!isEmpty(top) && precedence(tempExpression[i]) <= precedence(stack[top]))
            {
                prefixExpression += stack[top];
                pop(stack, top);
            }
            push(stack, tempExpression[i], top, size);
        }
    }

    while (!isEmpty(top))
    {
        prefixExpression += stack[top];
        pop(stack, top);
    }

    for(int i = prefixExpression.length() - 1; i >= 0; i--)
    {
      	reverse += prefixExpression[i];
    }

    return reverse;
}

void push(char stack[], char alphabet, int &top, int size)
{
    if (isFull(top, size))
    {
        cout << "Stack overflow." << endl;
        return;
    }

    top++;
    stack[top] = alphabet;
}

char pop(char stack[], int &top)
{
    if (isEmpty(top))
    {
        cout << "Stack underflow." << endl;
        exit(0);
    }
    char item = stack[top];
    top--;
    return item;
}

void evaluatePush(int stack[], int element, int &top, int size)
{
    if (isFull(top, size))
    {
        cout << "Stack overflow." << endl;
        return;
    }

    top++;
    stack[top] = element;
}

int evaluatePop(int stack[], int &top)
{
    if (isEmpty(top))
    {
        cout << "Stack underflow." << endl;
        exit(0);
    }
    int item = stack[top];
    top--;
    return item;
}

void evaluate(string expression)
{
    int size = 30, top = -1, temp;
    int element1, element2, calculate;
    int stack[size];
    for (int i = 0; i < expression.length(); i++)
    {
        if (!operatorChecker(expression[i]))
        {
            temp = expression[i] - 48;
            evaluatePush(stack, temp, top, size);
        }
        if (operatorChecker(expression[i]))
        {
            element2 = evaluatePop(stack, top);
            element1 = evaluatePop(stack, top);
            switch (expression[i])
            {
            case '+':
                calculate = element1 + element2;
                break;
            case '-':
                calculate = element1 - element2;
                break;
            case '*':
                calculate = element1 * element2;
                break;
            case '/':
                calculate = element1 / element2;
                break;
            default:
                cout << "Invalid operator. Try again." << endl;
                break;
            }
            evaluatePush(stack, calculate, top, size);
        }
    }
    cout << "The evaluation of the expression results into " << endl;
    cout << stack[top];
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

bool operatorChecker(char alphabet)
{
    if (alphabet == '+' || alphabet == '-' || alphabet == '*' || alphabet == '/')
    {
        return true;
    }
    return false;
}

int precedence(char alphabet)
{
    switch (alphabet)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
    return 0;
}
