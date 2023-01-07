#include <iostream>
#include <cstdlib>
#include <ctime>

int *allocate_array(int);
int *sorted_array(int[], int);
int array_average(int[], int);

int main()
{
    int size;
    int *arrayPtr = nullptr;
    int *sortedPtr = nullptr;
    std::cout << "Enter the size of the array: " << std::endl;
    std::cin >> size;
    arrayPtr = allocate_array(size);
    std::cout << "Before sorting " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << *(arrayPtr + i) << " ";
    }
    std::cout << std::endl;
    sortedPtr = sorted_array(arrayPtr, size);
    std::cout << "After sorting: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << *(sortedPtr + i) << " ";
    }
    std::cout << std::endl;
    std::cout << "The average is: " << array_average(sortedPtr, size);
}

int *allocate_array(int size)
{
    int *arrayPtr = new int(size);
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        *(arrayPtr + i) = rand() % 50 + 1;
    }
    return arrayPtr;
}

int *sorted_array(int array[], int size)
{
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (*(array + j) > *(array + i))
            {
                temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
    }
    return array;
}

int array_average(int array[], int size)
{
    int sum = 0, minimum = array[0], found = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < minimum)
        {
            minimum = array[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i] == minimum)
        {
            for (int j = i; j < (size - 1); j++)
            {
                array[j] = array[j + 1];
            }
            i--;
            size--;
        }
    }
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum / size;
}