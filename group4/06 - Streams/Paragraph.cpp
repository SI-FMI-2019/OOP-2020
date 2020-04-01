#include <cstring>
#include <fstream>
#include <iostream>
#include "Paragraph.h"

Paragraph::Paragraph(const char* data) {
    len = strlen(data);
    this->data = new char[len + 1];
    strcpy(this->data, data);
}

Paragraph::Paragraph(const Paragraph& rhs) {
    len = strlen(rhs.data);
    this->data = new char[len + 1];
    strcpy(this->data, rhs.data);
}

Paragraph& Paragraph::operator=(const Paragraph& rhs) {
    if (this != &rhs) {
        delete[] data;

        len = strlen(rhs.data);
        this->data = new char[len + 1];
        strcpy(this->data, rhs.data);
    }
    return *this;
}

Paragraph::~Paragraph() {
    delete[] data;
}

std::ostream& operator<<(std::ostream& out, const Paragraph& para) {
    out << para.len << ":";
    out << para.data;
    return out;
}

// Implementation 1, works just like cin

// std::istream& operator>>(std::istream& in, Paragraph& para) {
//     // I suppose the input will be < 1000 length
//     char buffer[1000];
//     in >> buffer;

//     delete[] para.data;

//     para.len = strlen(buffer);
//     para.data = new char[para.len + 1];
//     strcpy(para.data, buffer);

//     return in;
// }

// Implementation 2, works like cin.getline() (reads the whole line until new line symbol)
// std::istream& operator>>(std::istream& in, Paragraph& para) {
//     // I suppose the input will be < 1000 length
//     char buffer[1000];
//     int currentChar = 0;
//     char ch;

//     while (in.get(ch)) {
//         if (ch == '\n') {
//             break;
//         } else {
//             buffer[currentChar] = ch;
//             currentChar++;
//         }
//     }
//     buffer[currentChar] = '\0';

//     delete[] para.data;

//     para.len = strlen(buffer);
//     para.data = new char[para.len + 1];
//     strcpy(para.data, buffer);

//     return in;
// }

// Implementation 3, reads custom format (the same that we use to write the data with operator<<)
std::istream& operator>>(std::istream& in, Paragraph& para) {
    // I suppose the input will be < 1000 length
    // Read length from 5:hello
    in >> para.len;

    // Read : from 5:hello
    in.get();

    // Read hello from 5:hello
    char buffer[1000];
    in >> buffer;

    delete[] para.data;

    para.data = new char[para.len + 1];
    strcpy(para.data, buffer);

    return in;
}
