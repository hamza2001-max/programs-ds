#include <iostream>

int getProdNum(int[], int, int);
void displayProd(int, int);
int main()
{
    int size = 9, value;
    int NUM_PRODS[size] = {914, 915, 916, 917, 918, 919, 920,
                           921, 922};
    std::cout << "Enter product number: " << std::endl;
    std::cin >> value;
    int prodIndex = getProdNum(NUM_PRODS, size, value);
    displayProd(prodIndex, size);
}

int getProdNum(int array[], int size, int value)
{
    int first = 0, last = size - 1, position;
    bool found = false;
    while (found != true)
    {
        int middle = (first + last) / 2;
        if (array[middle] == value)
        {
            position = middle;
            found = true;
        }
        if (value > array[middle])
        {
            first = middle + 1;
        }
        if (value < array[middle])
        {
            last = middle - 1;
        }
    }
    return position;
}

void displayProd(int index, int size)
{
    std::string title[size] =
        {"Six Steps to Leadership",
         "Six Steps to Leadership",
         "The Road to Excellence",
         "Seven Lessons of Quality",
         "Seven Lessons of Quality",
         "Seven Lessons of Quality",
         "Teams Are Made, Not Born",
         "Leadership for the Future",
         "Leadership for the Future"};
    std::string description[size] =
        {"Book", "Audio CD", "DVD",
         "Book", "Audio CD", "DVD",
         "Book", "Book", "Audio CD"};
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            std::cout << "Title: " << title[index] << "\ndescritption: " << description[index] << std::endl;
        }
    }
}