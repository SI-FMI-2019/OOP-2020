#include <iostream>
// strlen(str)
// strcmp(first, second) -> first < second => -1
                            // first == second => 0
                            // second < first => 1

// strcpy(destination, source)
// strcat(first, second) -> first . second

int strlen(const char* str)
{
    if (str == nullptr)
    {
        return -1;
    }
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int strcmp(const char* str1, const char* str2)
{
    if (str1 == nullptr || str2 == nullptr)
    {
        return -2;
    }
    int length;
    for (length = 0;  str1[length] != '\0' && str2[length] != '\0'; length++)
    {
        if (str1[length] < str2[length])
        {
            return -1;
        }
        else if (str1[length] > str2[length])
        {
            return 1;
        }
    }
    if (str1[length] == '\0' && str2[length] != '\0')
    {
        return -1;
    }   
    else if (str1[length] != '\0' && str2[length] == '\0')
    {
        return 1;
    }
    return 0;
}

void strcpy(char* destination, const char* source)
{
    
    if (destination == nullptr || source == nullptr)
    {
        return;
    }

    if (strlen(destination) < strlen(source))
    {
        return;
    }

    int length = 0;
    while (source[length] != '\0')
    {
        destination[length] = source[length];
        length++;
    }
    destination[length] = '\0';
}

int main()
{
    const char* name = "abc";
    const char* second = "abc";

    std::cout << strlen(name) << std::endl;
    std::cout << strcmp(name, second) << std::endl;

    char* destination = new char[strlen(name) + 1];
    std::cout << (void*) destination << std::endl;
    strcpy(destination, name);
    std::cout << destination << std::endl;

    return 0;
}