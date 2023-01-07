#include <iostream>

int mode_function(int[], int);
int main(int argc, char const *argv[])
{
    int size = 9;
    int array[size] = {1, 2, 2, 2, 2, 4, 4, 4, 3};
    int z = mode_function(array, size);
    std::cout << "max: " << z;
    return 0;
}
int mode_function(int array[], int size)
{
    int temp, max = INT_MIN, frequency;
    for (int i = 0; i < size; i++)
    {
        temp = 0;
        if (array[i] == array[i - 1])
        {
            continue;
        }
        for (int j = i; j < size; j++)
        {
            if (array[i] == array[j])
            {
                temp++;
                if (temp > max)
                {
                    std::cout << "When temp greater than max: " << array[j] << " " << temp << std::endl;
                    max = j;
                    frequency = temp;
                }
            }
        }
    }
    if (max == 1)
    {
        return -1;
    }
    std::cout << "frequency: " << frequency << std::endl;
    return array[max];
}