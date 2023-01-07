#include <iostream>

void maximum_pro(int array[], int n)
{
    int max = INT_MIN;
    int product, max_one, max_two;
    max =1;
    for (int i = n-2; i < n ; i++)
    {
            max *= array[i];
            if(i = n-2){
                max_one = array[i];
            }
            if(i = n-1){
                max_two = array[i];
            }
    }
    std::cout << "max product is " << max << " of "  << max_one << " and " << max_two;
}

int main()
{
    int n, num, temp;
    std::cout << "enter a value" << std::endl;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
    int size_of_array = sizeof(array) / sizeof(array[0]);

    for(int i = 0; i < size_of_array; i++){
        for(int j = i+1; j < size_of_array; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    maximum_pro(array, size_of_array);
    return 0;
}
