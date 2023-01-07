#include <iostream>

void move_zero(int array[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (array[j] == 0)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    int n;
    std::cout << "Enter a value" << std::endl;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
    std::cout << std::endl;
    move_zero(array, n);
    return 0;
}
