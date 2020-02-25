#include "timestamp.hpp"

int Timestamp::get_hours_from_seconds(int seconds)
{
    return seconds / SECONDS_IN_AN_HOUR;
}
int Timestamp::get_minutes_from_seconds(int seconds)
{
    return (seconds % SECONDS_IN_AN_HOUR) / SECONDS_IN_A_MINUTE;
}
int Timestamp::get_seconds_from_seconds(int seconds)
{
    return (seconds % SECONDS_IN_AN_HOUR) % SECONDS_IN_A_MINUTE;
}

void Timestamp::set_time(const int& total_seconds)
{

    this->hours = get_hours_from_seconds(total_seconds);
    this->minutes = get_minutes_from_seconds(total_seconds);
    this->seconds = = get_seconds_from_seconds(total_seconds);
}
void print_time() const
{
    /*...*/
}
Timestamp add(const Timestamp& second_time) const
{
    /*...*/
}
int to_total_seconds() const
{
    /*...*/
}