class Timestamp
{
private:
    int hours;
    int minutes;
    int seconds;

    const int SECONDS_IN_AN_HOUR = 3600;
    const int SECONDS_IN_A_MINUTE = 60;
    
    int get_hours_from_seconds(int seconds);
    int get_minutes_from_seconds(int seconds);
    int get_seconds_from_seconds(int seconds);
public:
    void set_time(int total_seconds);
    void print_time() const;
    Timestamp add(const Timestamp& second_time) const;
    int to_total_seconds() const;
};