//
// Created by lyubo on 25.03.20 г..
//

#ifndef CPP_QUEUE_H
#define CPP_QUEUE_H

//Какво за Бога е Queue = опашка

template<class T>
class Queue {
public:
    Queue();

    Queue(const Queue &from);

    Queue<T> &operator=(const Queue &from);

    ~Queue();

    void append(const T &item); //Добавя в края
    T get_first() const; //Проверява кой е първия елемент и го връща
    T pop(); //Връща първия и го маха от опашката

    T *elements;
private:
    int capacity; //Колко побира опашката
    int size; //Колко има в даден момент

    int start; //Къде се намира първия елемент в масива
    int end; //Къде се намира последния елемент от масива

    void double_array();
};


template<class T>
Queue<T>::Queue(): capacity(1), size(0), start(0), end(-1) //Това е по-бързо
{
    this->elements = new T[1];

    //Това също става
    //    this->capacity = 1;
    //    this->size = 0;
    //    this->start = 0;
    //    this->end = 0;
}

template<class T>
Queue<T>::Queue(const Queue &from): capacity(from.capacity), size(from.size), start(from.start), end(from.end) {
    this->elements = new T[from.capacity]; // ЧСГ1 <- пишете [from.size]

    for (int i = this->start; i < this->end; i++) {
        this->elements[i] = from.elements[i];
    }
}

template<class T>
Queue<T> &Queue<T>::operator=(const Queue<T> &from){
    if(this != &from)
    {
        delete[] this->elements;

        this->capacity = from.capacity;
        this->size = from.size;
        this->start = from.start;
        this->end = from.end;

        this->elements = new T[this->capacity]; // ЧСГ1 <- пишете [from.size]

        for (int i = this->start; i < this->end; i++) {
            this->elements[i] = from.elements[i];
        }
    }
    return *this;
}

template<class T>
Queue<T>::~Queue() {
    delete[] this->elements;
}

template<class T>
void Queue<T>::append(const T &item) {

    if(this->size == this->capacity)
    {
        this->double_array();
    }
    this->end += 1;
    if(this->end == this->capacity)
    {
        this->end = 0;
    }

    this->elements[this->end] = item;
    this->size += 1;
}

template<class T>
T Queue<T>::get_first() const {
    return this->elements[start];
}

template <class T>
T Queue<T>::pop(){
    this->start += 1;
    this->size -= 1;
    return this->elements[this->start - 1];
}

template <class T>
void Queue<T>::double_array() {
    T* new_array = new T[this->capacity * 2];

    for(int i = this->start; i <= this->end; i++)
    {
        new_array[i] = this->elements[i];
    }

    delete[] this->elements;
    this->elements = new_array;
    this->capacity *= 2;
}
#endif //CPP_QUEUE_H
