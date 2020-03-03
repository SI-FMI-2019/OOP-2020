#include <iostream>
#include "Timestamp.hpp"

void Timestamp::convertToTimestamp(const unsigned seconds)
{
    const unsigned SECONDS_IN_HOUR = 3600;
    this->hours = seconds / SECONDS_IN_HOUR;
    unsigned remainingSeconds = seconds % SECONDS_IN_HOUR;

    const unsigned SECONDS_IN_MINUTE = 60;
    this->minutes = remainingSeconds / SECONDS_IN_MINUTE;

    remainingSeconds %= SECONDS_IN_MINUTE;
    this->seconds = remainingSeconds;
}

void Timestamp::print() const
{
    this->printHours();
    this->printMinutes();
    this->printSeconds();
}

void Timestamp::add(const Timestamp& other)
{
    this->hours += other.hours;
    this->minutes += other.minutes;
    this->seconds += other.seconds;
}

unsigned Timestamp::convertToSeconds() const
{
    unsigned seconds = 0;
    const unsigned SECONDS_IN_HOUR = 3600;
    seconds += this->hours * SECONDS_IN_HOUR;

    const unsigned SECONDS_IN_MINUTE = 60;
    seconds += this->minutes * SECONDS_IN_MINUTE;

    seconds += this->seconds;
    return seconds;
}

void Timestamp::printHours() const
{
    if (this->hours < 10)
    {
        std::cout << "0" << this->hours;
    }
    else
    {
        std::cout << this->hours;
    }

    std::cout << ":";
}

void Timestamp::printMinutes() const
{
    if (this->minutes < 10)
    {
        std::cout << "0" << this->minutes;
    }
    else
    {
        std::cout << this->minutes;
    }

    std::cout << ":";
}

void Timestamp::printSeconds() const
{
    if (this->seconds < 10)
    {
        std::cout << "0" << this->seconds;
    }
    else
    {
        std::cout << this->seconds;
    }

    std::cout << std::endl;   
}