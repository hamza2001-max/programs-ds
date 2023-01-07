#include <iostream>
#include <cstdlib>
#include <ctime>

int *array_allocator(int);
int main()
{
    int size;
    int *ptr = nullptr;
    std::cout << "Enter a number: " << std::endl;
    std::cin >> size;
    ptr = array_allocator(size);
    std::cout << "Pointer in main " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;
    return 0;
}

int *array_allocator(int size)
{
    int *arrayPtr = new int(size);
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        *(arrayPtr + i) = rand() % 50 + 1;
    }
    std::cout << "Pointer in function " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << *(arrayPtr + i) << " ";
    }
    std::cout << std::endl;
    return arrayPtr;
}

