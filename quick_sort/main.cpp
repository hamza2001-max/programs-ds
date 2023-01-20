#include <iostream>
using namespace std;

int partition(int List[], int low, int high)
{
    int pivot, left, right, temp;
    left = low, right = high + 1, pivot = List[low];
    do
    {
        do
            left++;
        while (List[left] < pivot && left <= high);

        do
            right--;
        while (List[right] > pivot);

        if (left < right)
        {
            temp = List[left];
            List[left] = List[right];
            List[right] = temp;
        }
    } while (left < right);
    List[low] = List[right];
    List[right] = pivot;
    return right;
}

void quicksort(int List[], int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(List, low, high);
        quicksort(List, low, pi - 1);
        quicksort(List, pi + 1, high);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ' ';
    }
}

int main()
{
    int array[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int sizeOfArray = sizeof(array) / sizeof(array[0]);
    quicksort(array, 0, sizeOfArray);
    printArray(array, sizeOfArray);
    return 0;
}