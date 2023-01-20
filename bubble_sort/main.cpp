#include <iostream>
using namespace std;

void swap(int *first, int * second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(int array[], int n){
    bool swapped = false;
    for(int i =0; i< n-1; i++){
        swapped = false;
        for(int j = 0; j < n-i-1; j++){
            if(array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            break;
        }
    }

    for(int i = 0;i < n; i++){
        cout << array[i] << " ";
    }
}

int main()
{
    int array[] = {1, 5, 4, 2, 8};
    int n = sizeof(array)/sizeof(array[0]);
    bubbleSort(array, n);
    return 0;
}