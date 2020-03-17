#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

class Timestamp
{
public:
    Timestamp(const Timestamp&) = default;
    Timestamp(const unsigned seconds = 0);
    // void convertToTimestamp(const unsigned);
    void print() const;             // HH:MM:SS
    void add(const Timestamp&);
    unsigned convertToSeconds() const;
    ~Timestamp() = default;
private:
    unsigned hours;
    unsigned minutes;
    unsigned seconds;

    // helper methods do not need to be exposed :)
    void printHours() const;
    void printMinutes() const;
    void printSeconds() const;

    const unsigned SECONDS_IN_HOUR;
    const unsigned SECONDS_IN_MINUTE;
};

#endif /* TIMESTAMP_HPP */