#include <iostream>
using namespace std;

void insertionSort(int array[], int n){
    for(int i = 1; i< n; i++){
        int key = array[i];
        int j = i-1;
        while(j >=0  && key < array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
    for(int i = 0; i< n; i++){
        cout << array[i] << ' ';
    }
}
int main(){
    int array[] = {2, 43, 1, 65, 22, 12, 12};
    int size = sizeof(array)/sizeof(array[0]);
    insertionSort(array, size);
    return 0;
}