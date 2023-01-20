#include <iostream>
using namespace std;

void merge(int array[], int begin, int midPoint, int end)
{
    int tempArray[end-begin+1];
    int i = begin, j = midPoint + 1, k = 0;
    while (i <= midPoint && j <= end)
    {
        if (array[i] <= array[j])
        {
            tempArray[k++] = array[i++];
        }
        else
        {
            tempArray[k++] = array[j++];
        }
    }
    while (i <= midPoint)
    {
        tempArray[k++] = array[i++];
    }
    while (j <= end)
    {
        tempArray[k++] = array[j++];
    }
    for (k = 0, i = begin; i <= end; ++i, ++k)
    {
        array[i] = tempArray[k];
    }
}

void mergeSort(int array[], int begin, int end)
{
    if (begin >= end)
        return;
    int midPoint = (begin + end) / 2;
    mergeSort(array, begin, midPoint);
    mergeSort(array, midPoint + 1, end);
    merge(array, begin, midPoint, end);
}

void printArray(int array[], int sizeOfArray)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << array[i] << ' ';
    }
}

int main()
{
    int array[] = {6, 2, 9, 1, 8, 15, 32, 2};
    int sizeOfArray = sizeof(array) / sizeof(array[0]);
    mergeSort(array, 0, sizeOfArray);
    printArray(array, sizeOfArray);
    return 0;
}