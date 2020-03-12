#include "MyArray.hpp"

MyArray::MyArray()
{
    //this->array = new int[0]; //окей е

    //Трябва да си сложим някакви начални стойности на нашия клас
    this->array = nullptr; //nullptr = 0
    this->size = 0;
}
MyArray:: MyArray(const MyArray& from)
{
    //Трябва да копираме паметта от from в this

    //1. Заделим нова памет
    this->array = new int[from.size];

    //2. Копираме другите член-данни
    this->size = from.size;

    //3. Копираме динамичната памет
    for(int i = 0; i < this->size; i++)
    {
        this->array[i] = from.array[i];
    }

}
MyArray::~MyArray()
{
    //Трием динамичната памет! (Трием само динамичната памет)
    delete[] this->array;
}

MyArray& MyArray::operator=(const MyArray& from)
{
    if(this != &from)
    {
        delete[] this->array;

        //Трябва да копираме паметта от from в this

        //1. Заделим нова памет
        this->array = new int[from.size];

        //2. Копираме другите член-данни
        this->size = from.size;

        //3. Копираме динамичната памет
        for(int i = 0; i < this->size; i++)
        {
            this->array[i] = from.array[i];
        }
    }
    return *this;
}

//MyArray& operator=(const MyArray&); //ще го говорим по-късно
    
void MyArray::insert_at(int element, int position)
{
    //Какво ще правим тук ?

    //3 5 2 7 8 9 12
    //числото -1, на позиция 5

    //3 5 2 7 8 -1 9 12

    //1. Заделяме нова, по-голяма памет (защото нямаме място къде да добавяме нови числа)
    int* new_array = new int[this->size + 1];

    //2. Копираме от стария в новия масив
    for(int i = 0; i < position; i++)
    {
        new_array[i] = this->array[i];
    }

    new_array[position] = element;

    for(int i = position + 1; i < size + 1; i++) // i <= size
    {
        new_array[i] = this->array[i - 1]; //Защо ? -> ние слагаме елемента от оригиналния масив, който е на позиция i, в новия
        //масив на позиция i + 1
    }

    //3. Заменяме паметта
    delete[] this->array; //Изтриваме старата памет
    this->array = new_array; //Слагаме новата на нейно място

    //4. Да си променим размера
    this->size++;

}

void MyArray::remove_at(int position)
{
    //1. Заделяме нова памет
    int* new_array = new int[this->size-1];

    //2. Копираме си паметта
    for(int i = 0; i < position; i++)
    {
        new_array[i] = this->array[i];
    }

    for(int i = position + 1; i < this->size; i++)
    {
        new_array[i - 1] = this->array[i];
    }

    //3. Заменяме паметта
    delete[] this->array; //Изтриваме старата памет
    this->array = new_array; //Слагаме новата на нейно място

    //4. Да си променим размера
    this->size--;
}
int MyArray::get_at(int position)
{
    return this->array[position];
}

MyArray& MyArray::operator+(const MyArray& second) //+ приема два аргумента, но единия вече го имаме: this
    {
        if(this->size != second.size)
        {
            return *this; //Това е малко tricky
        }

        for(int i = 0; i < this->size; i++)
        {
            this->array[i] += second.array[i]; //Важно да отбележа - методите имат достъп до private частите
        }

        return *this;
    }
