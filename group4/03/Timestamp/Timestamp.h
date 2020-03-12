#pragma once

class Timestamp {
   private:
    int year;
    int month;
    int day;

   public:
    //Constructors
    Timestamp();
    Timestamp(int year, int month, int day);

    // Getters
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    //Setters
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
};
