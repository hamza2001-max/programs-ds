#include <iostream>

int* arraylin(int [], int);
int main()
{
    int size = 10, first = 0, last = size - 1, middle, value, position;
    int beArray[size] = {10, 20, 89, 21, 45, 32, 211, 9, 2, 3};
    int* array = arraylin(beArray, size);
    bool found = false;
    std::cin >> value;
    
    while (found == false && first <= last)
    {
        middle = (first + last) / 2;
        std::cout << middle << " ";
        if (array[middle] == value)
        {
            found = true;
            position = middle;
            std::cout << "The value is present at " << position << std::endl;
        }
        else if (value > array[middle])
        {
            first = middle + 1;
        }
        else if (value < array[middle])
        {
            last = middle - 1;
        }
    }
    if (found == true)
    {
        std::cout << "Value found" << std::endl;
    }
    else
    {
        std::cout << "The value is not present" << std::endl;
    }
    return 0;
}

int* arraylin(int array[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            if(array[j] > array[i]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}