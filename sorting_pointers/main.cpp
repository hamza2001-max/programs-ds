#include <iostream>

void sortArray(int *[], int);
int main(){
    const int size = 5;
    int donations[size] = {20, 5, 32, 6, 5};
    int* donationsPtr[size] = {nullptr, nullptr, nullptr, nullptr, nullptr};
    for(int i = 0; i< size; i++){
        donationsPtr[i] = &donations[i];
    }
    sortArray(donationsPtr, size);
    for(int i = 0; i< size; i++){
        std::cout << donationsPtr[i] << " ";
    }
}

void sortArray(int *array[], int size){
    // int temp = 0;
    // for(int i =0; i< size; i++){
    //     for(int j = 0; j<size; j++){
    //         if()
    //         temp = array[i];
    //         array[i] = array[j];
    //         array[j] = temp;
    //     }
    // }
}