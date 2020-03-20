#ifndef CPP_PERSON_H
#define CPP_PERSON_H

#include <cstring>
class person{
public:
    person(); //Всеки клас е хубаво default-ен конструктор
    person(const person& from);
    person& operator= (const person& from);
    ~person();

    void set_name(const char* new_name);
    char* get_name() const;

private:
    char* name; //Имаме динамична памет
    void copy_char_array(const char*);
};

#endif //CPP_PERSON_H
