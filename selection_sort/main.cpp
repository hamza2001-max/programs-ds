#include <iostream>
using namespace std;

void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

void selectionSort(int array[], int n){
    for(int i =0; i< n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(min != i){
            swap(&array[i], &array[min]);
        }
    }
    for(int i = 0; i < n; i++){
        cout << array[i] << ' ';
    }
}
int main(){
    int array[] = {2, 43, 1, 65, 22, 12, 12};
    int size = sizeof(array)/sizeof(array[0]);
    selectionSort(array, size);
    return 0;
}