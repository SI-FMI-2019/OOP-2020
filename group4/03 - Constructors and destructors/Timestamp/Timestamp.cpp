/**
 * TODO: Write a class which represents a timestamp
 * TODO: with year, month, day
 */

#include "Timestamp.h"

#include <iostream>

int Timestamp::getDay() const {
    return this->day;
}

int Timestamp::getYear() const {
    return this->year;
}

int Timestamp::getMonth() const {
    return this->month;
}

void Timestamp::setYear(int year) {
    if (year < 0) {
        year = 0;
    }
    this->year = year;
}
void Timestamp::setMonth(int month) {
    if (month > 12 || month < 1) {
        month = 1;
    }

    this->month = month;
}
void Timestamp::setDay(int day) {
    if (day < 0 || day > 30) {
        day = 1;
    }
    this->day = 1;
}

Timestamp::Timestamp() {
    setYear(1);
    setMonth(1);
    setDay(1);
}

Timestamp::Timestamp(int year1, int month1, int day1) : year(year1),
                                                        month(month1),
                                                        day(day1) {
}
