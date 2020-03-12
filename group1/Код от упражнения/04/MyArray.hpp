#pragma once //Ще говорим после за това

//Ще направим клас, собствен масив, към който ще може да добавяме елементи
//Масива ще е динамичен, тоест ще се разширява когато ни трябва
class MyArray
{
public:
    MyArray();
    MyArray(const MyArray&); //Не е нужно да пишете име на променливите тук
    ~MyArray(); //Защото трябва да си трием паметта
    MyArray& operator=(const MyArray&); //ще го говорим по-късно
    
    //Какво ще ни трябва като методи ?
    void insert_at(int element, int position);
    void remove_at(int position);
    int get_at(int position);

    //[2 3 4 5] + [1 2 3 1] = [3 5 7 6]

    MyArray& operator+(const MyArray& second); //+ приема два аргумента, но единия вече го имаме: this
    void say_hello();
private:
    int* array;
    int size; //Колко елемента имаме в масива
};