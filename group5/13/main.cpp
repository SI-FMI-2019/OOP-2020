#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

namespace pesho
{
    void swap(const int& a, const int& b);
};

class Plus
{
public:
    int operator()(const int& a, const int& b)
    {
        return a + b;
    }
};

int sum(const int& a, const int& b)
{
    return a + b;
}

void printSum(const int& a, const int& b, int (*sumPtr)(const int&, const int&))
{
    std::cout << "Im executing " << sumPtr(a, b) << std::endl;
}

int main()
{
    int x = 9;
    int y = 10;
    auto sumPtr = sum;
    std::cout << sumPtr(6, 9) << std::endl;
    printSum(5, 3, [] (const int& a, const int& b) -> int
    {
        return a + b;
    });

    [] (const int& a, const int& b) -> int
    {
        std::cout << "I've invoked myself" << std::endl;
        return a + b;
    }(4 ,3);

    int arr [3] = {4, 6, 2};
    std::sort(arr, arr + 3, std::greater<int>());

    // The correct lambda for sorting arr takes predicate as last argument:
    std::sort(arr, arr + 3, [](const int& a, const int& b) { return a > b; });
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::swap(x, y); // fully qualified name

    std::vector<int> numbers {1, 2, 3};
    std::cout << numbers.size() << std::endl;
    numbers[0] = 5;
    std::cout << numbers[0] << std::endl;

    for (std::vector<int>::reverse_iterator iter = numbers.rbegin(); 
        iter != numbers.rend();
        iter++)
    {
        std::cout << ++*iter << ", ";
    }
    
    std::string myString("asdf");
    myString.length();
    myString = "asdf";
    myString = "123.20";
    myString[3] = 'a';
    myString.substr(0, 10);
    int num = std::stod(myString);

    std::cin >> myString;
    std::cout << myString;

    std::string other = myString + "iuewryr";
    myString += "iuewryr";
    myString.find('w');
    myString.c_str();

    Plus plus;
    std::cout << plus(3, 9) << std::endl;
    return 0;
}