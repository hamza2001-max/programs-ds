#include <iostream>

int *duplicateArray(int *, int);
int main()
{
    int array[] = {2, 5, 3, 77, 335, 74};
    int size = sizeof(array) / sizeof(array[0]);
    int *arrayptr = nullptr;
    arrayptr = duplicateArray(array, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << *arrayptr << " ";
        arrayptr++;
    }
    delete [] arrayptr;
    arrayptr = nullptr;
    return 0;
}

int *duplicateArray(int *array, int num)
{
    int *copyarray = new int[num];
    for (int i = 0; i < num; i++)
    {
        copyarray[i] = array[i];
    }
    return copyarray;
}