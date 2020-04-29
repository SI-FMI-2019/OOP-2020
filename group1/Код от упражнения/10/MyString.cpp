//
// Created by lyubo on 23.04.20 г..
//

#include "MyString.h"



MyString::MyString() {
    this->data = new char[1];
    this->data[0] = '\0';
}

MyString::MyString(const char *text): MyString() {
    this->copy_data(text);
}

MyString::MyString(const MyString &from): MyString() {
    this->copy_data(from.data);
}

MyString& MyString::operator=(const MyString &from) {
    if(this != &from)
    {
        this->copy_data(from.data);
    }
    return *this;
}

MyString::~MyString() {
    delete[] this->data;
}


void MyString::append(const char &to_append) {
    int size = strlen(this->data);
    char* new_string = new char[size + 2]; //за новия символ и за \0

    for(int i = 0; i < size; i++)
    {
        new_string[i] = this->data[i];
    }

    new_string[size] = to_append;
    new_string[size + 1] = '\0';

    delete[] this->data;
    this->data = new_string;
}

void MyString::print() const{
    std::cout << this->data;
}

bool MyString::operator==(const MyString &second) const {
    //return strcmp(this->data, second.data) == 0;

    int len_first = strlen(this->data);
    int len_second = strlen(second.data);

    if(len_first == len_second)
    {
        for(int i = 0; i < len_first; i++)
        {
            if(this->data[i] != second.data[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool MyString::operator!=(const MyString &second) const {
    return !this->operator==(second);
}

bool MyString::operator>(const MyString &second) const {
    //return strcmp(this->data, second.data) > 0;

    int len_first = strlen(this->data);
    int len_second = strlen(second.data);

    //aa > ab
    //b > c;
    //aa > aaa
    //aaa > aa (false)
    //aab > ab (true)
    //aa > aa (false)

    if(this->operator==(second)){
        return false;
    }

    if(len_first < len_second)
    {
        for(int i = 0; i < len_first; i++)
        {
            if(this->data[i] != second.data[i])
            {
                return this->data[i] < second.data[i];
            }
        }
        return true;
    }
    else
    {
        for(int i = 0; i < len_second; i++)
        {
            if(this->data[i] != second.data[i])
            {
                return this->data[i] < second.data[i];
            }
        }
        return false;
    }
}

bool MyString::operator<(const MyString &second) const {
    //(! > && ! ==)
    // !(> || ==)

    //return !(this->operator>(second) || this->operator==(second));
    return !this->operator>(second) && !this->operator==(second);
}

void MyString::copy_data(const char *from) {
    int size = strlen(from);

    delete[] this->data;
    this->data = new char[size + 1]; //заради \0

    strcpy(this->data, from);
    this->data[size] = '\0';
}

