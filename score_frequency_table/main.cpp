#include <iostream>
#include <cstdlib>
#include <ctime>

void print_frequency(int size)
{
    if (size == 0 || size < 0)
    {
        std::cout << "";
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    int size, rangeSize = 10, minimumScore = INT_MAX, maximumScore = INT_MIN;
    std::cout << "Enter the size: ";
    std::cin >> size;
    int midTerm[size], finalTerm[size], totalArray[size], range[rangeSize] = {0};
    srand(time(NULL));
    std::cout << "Student\t\tMid\tFinal\tTotal" << std::endl;
    for (int i = 0; i < size; i++)
    {
        midTerm[i] = rand() % 30 + 1;
        finalTerm[i] = rand() % 50 + 1;
        totalArray[i] = midTerm[i] + finalTerm[i];

        if (minimumScore > totalArray[i])
        {
            minimumScore = totalArray[i];
        }
        if (maximumScore < totalArray[i])
        {
            maximumScore = totalArray[i];
        }

        if (totalArray[i] >= 0 && totalArray[i] <= 10)
        {
            range[0]++;
        }
        if (totalArray[i] >= 11 && totalArray[i] <= 20)
        {
            range[1]++;
        }
        if (totalArray[i] >= 21 && totalArray[i] <= 30)
        {
            range[2]++;
        }
        if (totalArray[i] >= 31 && totalArray[i] <= 40)
        {
            range[3]++;
        }
        if (totalArray[i] >= 41 && totalArray[i] <= 50)
        {
            range[4]++;
        }
        if (totalArray[i] >= 51 && totalArray[i] <= 60)
        {
            range[5]++;
        }
        if (totalArray[i] >= 61 && totalArray[i] <= 70)
        {
            range[6]++;
        }
        if (totalArray[i] >= 71 && totalArray[i] <= 80)
        {
            range[7]++;
        }
        if (totalArray[i] >= 82 && totalArray[i] <= 90)
        {
            range[8]++;
        }
        if (totalArray[i] >= 90 && totalArray[i] <= 100)
        {
            range[9]++;
        }
        std::cout << "Student[" << i << "]\t " << midTerm[i] << "\t" << finalTerm[i] << "\t" << totalArray[i] << "\n";
    }
    std::cout << "*====================================*" << std::endl;
    std::cout << "The minimum score is " << minimumScore << std::endl;
    std::cout << "The maximum score is " << maximumScore << std::endl;
    std::cout << "*====================================*" << std::endl;

    int j = 0, k = 10;
    for (int i = 0; i < rangeSize; i++)
    {
        std::cout << "Score(" << j << "-" << k << ")\t";
        print_frequency(range[i]);
        j += 11;
        k += 10;
    }
    std::cout << "*====================================*" << std::endl;
    return 0;
}
