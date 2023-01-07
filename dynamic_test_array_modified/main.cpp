#include <iostream>
#include <string>
std::string *testSorted(std::string, int[], int);
int main()
{
    int size = 3;
    std::string studentName[size];
    int testScore[size];
    std::cout << "Enter the student name: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> studentName[i];
    }
    std::cout << "Enter the student score: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> testScore[i];
    }
    std::string *testSortedPtr = testSorted(studentName, testScore, size);
    std::cout << "after string sort: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << *(testSortedPtr + i) << " ";
    }

    // std::cout << "Enter the test score: " << std::endl;
    // for (int i = 0; i < size; i++)
    // {
    //     std::cin >> testScore[i];
    // }
    // std::cout << "Before Sort" << std::endl;
    // int *testSortedPtr = testSorted(testScore, size);
    // for (int i = 0; i < size; i++)
    // {
    //     std::cout << *(testSortedPtr + i) << " ";
    // }
    // return 0;
}

std::string *testSorted(std::string studentArray[], int testArray[], int size)
{
    std::string studentNameHeap = new std::string[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (testArray[i] < testArray[j])
            {
                int temp = testArray[i];
                testArray[i] = testArray[j];
                testArray[j] = temp;
                studentNameHeap[i] = studentArray[j];
            }
        }
    }
    return studentNameHeap;
}
