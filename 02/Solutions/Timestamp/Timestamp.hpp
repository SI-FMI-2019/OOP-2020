#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

class Timestamp
{
public:
    void convertToTimestamp(const unsigned);
    void print() const; // HH:MM:SS
    void add(const Timestamp&);
    unsigned convertToSeconds() const;

private:
    unsigned hours;
    unsigned minutes;
    unsigned seconds;

    // helper methods do not need to be exposed :)
    void printHours() const;
    void printMinutes() const;
    void printSeconds() const;
};

#endif /* TIMESTAMP_HPP */