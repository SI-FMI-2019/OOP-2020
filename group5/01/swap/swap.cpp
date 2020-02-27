#include <iostream>

void swapByValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swapByRefs(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swapByPointers(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 6;
    int b = 8;

    swapByValue(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;

    swapByRefs(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;

    swapByPointers(&a, &b);
    std::cout << "a = " << a << " b = " << b << std::endl;

    return 0;
}