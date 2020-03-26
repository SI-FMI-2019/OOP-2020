#ifndef MAIN
#define MAIN

template<typename T>
void myswap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

#endif // MAIN