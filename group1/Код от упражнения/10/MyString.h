//
// Created by lyubo on 23.04.20 г..
//

#ifndef CPP_MYSTRING_H
#define CPP_MYSTRING_H
#include <iostream>
#include <cstring>
#include <assert.h>

/*
 * Напишете собствена имлементация на класа `String`, която да бъде с име `MyString`.
 * `MyString` трябва да може да съдържа текст и да поддържа инициализиране с низ, добавяне на символ в края на низа,
 * принтиране, както и оператори за сравнение (`==`, `!=`, `>`, `<`) (подобна на strcmp)
 *
 * MyString:
 *  - MyString("abc")
 *  - append('a')
 *  - print()
 *  - operator==
 *  - operator!=
 *  - operator>
 *  - operator<
 */


class MyString {
public:
    MyString();
    MyString(const char* text); // TODO if it works
    MyString(const MyString& from);
    MyString& operator=(const MyString& from);
    MyString& operator=(const char* from);
    ~MyString();


    void append(const char& to_append);
    void print() const;

    bool operator==(const MyString& second) const;
    bool operator!=(const MyString& second) const;
    bool operator>(const MyString& second) const;
    bool operator<(const MyString& second) const;

    friend void run_tests();
    friend std::ostream& operator<<(std::ostream& out, const MyString& obj);
private:
    char* data;

    void copy_data(const char* from);
};

inline void run_tests()
{
    std::cout << "Starting tests..." << std::endl;

    {
        MyString first;
        assert(strcmp(first.data, "\0") == 0);
        std::cout << "Constructor test passed !" << std::endl;
    }

    {
        MyString first("Hello");
        assert(strcmp(first.data, "Hello") == 0);
        std::cout << "Constructor with parameters passed !" << std::endl;
    }

    {
        MyString first("Hello world");
        MyString second(first);

        assert(strcmp(second.data, first.data) == 0);
        std::cout << "Copy constructor passed !" << std::endl;
    }

    {
        MyString first("Hello");
        MyString second(first);
        MyString third("World!");

        second = third;
        assert(strcmp(second.data, third.data) == 0);
        assert(strcmp(second.data, first.data) != 0);
        std::cout << "Operator= passed !" << std::endl;
    }

    {
       MyString first("Hello");
       first.append('!');

       assert(strcmp(first.data, "Hello!") == 0);
       std::cout << "Append() passed !" << std::endl;
    }

    {
        MyString first("Hello");
        MyString second("Hello");
        MyString third("Heloo");

        assert(first == second);
        assert(first != third);

        std::cout << "Operator== and operator!= passed !" << std::endl;
    }

    {
        MyString first("aa");
        MyString second("ab");
        MyString third("aa");
        MyString forth("ba");

        assert(first > second);
        assert(second < first);
        assert(!(first > third));
        assert(second > forth);

        std::cout << "Operator> and operator< passed !" << std::endl;
    }
}

inline std::ostream& operator<<(std::ostream& out, const MyString& obj)
{
    out << obj.data;
    return out;
}

#endif //CPP_MYSTRING_H
