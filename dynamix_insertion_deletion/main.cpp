#include <iostream>
// int dyInDe();
int main(int argc, char const *argv[])
{
    int choice, size, element;
    int *array = nullptr;
    std::cout << "Enter the size of the array" << std::endl;
    std::cin >> size;
    array = new int[size];
    std::cout << "Enter the numbers in the array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> *(array + i);
    }
    std::cout << "The array elements are: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << *(array + i) << " ";
    }
    std::cout << '\n';
    std::cout << "Choose[1/2]...." << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        std::cout << "INSERTION: " << std::endl;
        std::cout << "Enter an element to this array: " << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << *(array + i) << " ";
        }

        std::cout << '\n';
        std::cin >> element;

        for (int i = 1; i < size - 1; i++)
        {
            array[i] = array[i+1];
        }
        array[0] = element;

        std::cout << "The new array is: " << std::endl;
        for (int i = 0; i < size; i++)
        {
            std::cout << *(array + i) << " ";
        }

        break;

        default:
        break;
    }
    return 0;
}
