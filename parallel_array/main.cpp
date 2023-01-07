#include <iostream>

int main(){
    int size = 4, sum =0;
    int midarray[size] = {23, 34, 56, 75};
    int finalarray[size] = {45, 67, 88, 22};
    int totalarray[size];
    for(int i = 0; i< size; i++){
        sum = midarray[i] + finalarray[i];
        totalarray[i] = sum;
    }
    for(int i = 0; i< size; i++){
        std::cout << totalarray[i] << " ";
    }
    return 0;
}