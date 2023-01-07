#include <iostream>

void pairing(int num[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (num[i] + num[j] == 10)
            {
                std::cout << "(" << num[i] << ", "  << num[j] << ")" << std::endl;
            }
        }
    }
}

int main()
{
    int n;
    std::cout <<  "enter a value" << std::endl;
    std::cin >> n;
    int array[n];
    for(int i = 0; i <= n; i++){
        std::cin >> array[i];
    }
    pairing(array, n);
    return 0;
}