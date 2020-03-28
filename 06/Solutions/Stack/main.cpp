#include "Stack.hpp"

int main()
{
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('f');
    s.push('g');
    s.push('c');

    while (s.getSize() != 0)
    {
        std::cout << s.pop() << std::endl;
    }

    return 0;
}