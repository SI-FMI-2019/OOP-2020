#ifndef CPP_PERSON_H
#define CPP_PERSON_H

#include <cstring>
class person{
public:
    person();
    person(const person& from);
    person& operator= (const person& from);
    ~person();

    void set_name(const char* new_name);
    void set_age(const int& new_age);
    void print() const;

    char* get_name() const;
    int get_age() const;

    friend std::ostream& operator<<(std::ostream& out, const person& to_print);
    friend std::istream& operator>>(std::istream& in, person& to_write);
;private:
    char* name;
    int age;
    void copy_char_array(const char*);
};

#endif //CPP_PERSON_H
