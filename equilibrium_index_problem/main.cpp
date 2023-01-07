#include <iostream>

int equilibrium_index(int array[], int n)
{
    int caseZ = 0, caseN = 0;
    int lhs, rhs, index;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            for (int l = 1; l < n; l++)
            {
                caseZ += array[l];
            }
            if (array[0] == caseZ)
            {
                std::cout << "equilibrium exists at index 0" << std::endl;
                return caseZ;
            }
        }
        if (i == n - 1)
        {
            for (int m = n - 2; m >= 0; m--)
            {
                caseN += array[m];
            }
            if (array[n - 1] == caseN)
            {
                std::cout << "equilibrium exists at index n" << std::endl;
                return caseN;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        lhs = 0, rhs = 0;
        for (int j = 0; j <= i; j++)
        {
            if (i == n - 2 || i > n - 3)
            {
                break;
            }
            lhs += array[j];
        }

        for (int k = i + 2; k < n; k++)
        {
            rhs += array[k];
        }
        if (lhs == rhs)
        {
            return i;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cout << "Enter a value" << std::endl;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }
    std::cout << std::endl;
    int result = equilibrium_index(array, n);
    std::cout << "equilibrium exists at " + result;
    return 0;
}
