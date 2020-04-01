#include <iostream>
#include "person.h"
#include <fstream>

int main()
{
    std::ifstream testFile;
    testFile.open("myfile.txt", std::ios::in);
    if(testFile.is_open()) // -> is_open() == true
    {
        //Do something
        char c;
        while(testFile.get(c)) //returns bool дали четенето е успешно
        {
            std::cout << c;
        }
    }
    else
    {
        std::cout << "Unable to open file!" << std::endl;
    }

    testFile.close();

    std::ofstream writeToFile;
    writeToFile.open("myfile.txt", std::ios::out | std::ios::app);

    if(writeToFile.is_open())
    {
        writeToFile << "This is written from the program !\n";
    }
    else
    {
        std::cout << "Unable to open file!" << std::endl;
    }
    return 0;
}