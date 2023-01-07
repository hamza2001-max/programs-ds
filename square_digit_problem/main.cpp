#include <iostream>

int square_digits(int num)
{
    int diviser = 1;
    int mod = 10;
    int singleDigit, square = 0;
    std::string result, squareString;
    while (diviser <= num)
    {
        singleDigit = (num / diviser) % mod;
        square = singleDigit * singleDigit;
        squareString = std::to_string(square);
        result.insert(0, squareString);
        diviser *= 10;
    }
    int c = std::stoi(result);
    return c;
};

int main()
{
    int num;
    std::cout << "enter a number" << std::endl;
    std::cin >> num;
    int resultant = square_digits(num);
    std::cout << "The result is " << resultant;
    return 0;
}

