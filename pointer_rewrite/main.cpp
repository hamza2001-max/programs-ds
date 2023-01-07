#include <iostream>

int doSomething(int *, int *);
int main(int argc, char const *argv[])
{
    int m = 1, *x = &m, *y = &m;
    m = doSomething(x, y);
    std::cout << m;
    return 0;
}

int doSomething(int *x, int *y){
    int temp = *x;
    *x= *y*10;
    *y=temp*10;
    return *x+*y;
}
