#include <iostream>
using namespace std;

void combination(int array[], int size)
{
    static int traverser = 0;
    int limit = traverser+1;
    for (limit; limit < size; limit++)
    {
        cout << '{' << array[traverser] << " " << array[limit] << "}" << endl;
    }
    traverser++;
    if (traverser == size - 1)
    {
        return;
    }
    combination(array, size);
}

int main()
{
    int array[] = {1, 28, 43, 334, 90};
    int size = sizeof(array) / sizeof(array[0]);
    combination(array, size);
    return 0;
}