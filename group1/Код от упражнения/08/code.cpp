#include <iostream>
#include <cstring>

class Vehicle
{
public:
    Vehicle()
    {
        this->maker = new char[1];
        this->maker[0] = '\0';

        this->model = new char[1];
        this->model[0] = '\0';

        this->horsepower = 0;
    }
    Vehicle(const char* maker, const char* model, const int& horsepower)
    {
        int size = strlen(maker);

        this->maker = new char[size + 1];
        strcpy(this->maker, maker);
        this->maker[size] = '\0';

        size = strlen(model);

        this->model = new char[size + 1];
        strcpy(this->model, model);
        this->model[size] = '\0';

        this->horsepower = horsepower;
    }
    Vehicle(const Vehicle& from)
    {
        int size = strlen(from.maker);

        this->maker = new char[size + 1];
        strcpy(this->maker, from.maker);
        this->maker[size] = '\0';

        size = strlen(from.model);

        this->model = new char[size + 1];
        strcpy(this->model, from.model);
        this->model[size] = '\0';

        this->horsepower = from.horsepower;
    }
    Vehicle& operator= (const Vehicle& from)
    {
        if(this != &from)
        {
            delete [] this->maker;
            delete [] this->model;

            int size = strlen(from.maker);

            this->maker = new char[size + 1];
            strcpy(this->maker, from.maker);
            this->maker[size] = '\0';

            size = strlen(from.model);

            this->model = new char[size + 1];
            strcpy(this->model, from.model);
            this->model[size] = '\0';

            this->horsepower = from.horsepower;
        }
        return *this;
    }
    ~Vehicle()
    {
        delete[] this->maker;
        delete[] this->model;
    }

    char* get_maker() const {
        return this->maker;
    }
    char* get_model() const {
        return this->model;
    }
    int get_horsepower() const {
        return this->horsepower;
    }

    void print() const
    {
        std::cout << "Maker: " << this->maker << std::endl;
        std::cout << "Model: " << this->model << std::endl;
        std::cout << "Horsepower: " << this->horsepower << std::endl;
    }

protected:
    int a;
private:
    char* maker;
    char* model;
    int horsepower;
};

class Car: public Vehicle
{
private:
    char* engine_type;
    int seats;
public:
    Car()
    {
        this->seats = 0;
        this->engine_type = new char[1];
        this->engine_type[0] = '\0';
    }

    Car(const char* maker, const char* model, const int& horsepower, const int& seats, const char* engine): Vehicle(maker, model, horsepower)
    {
        this->seats = seats;

        int size = strlen(engine);

        this->engine_type = new char[size + 1];
        strcpy(this->engine_type, engine); //(dst, src)
        this->engine_type[size] = '\0';
    }

    Car(const Car& from): Vehicle(from)
    {
        this->seats = from.seats;

        int size = strlen(from.engine_type);

        this->engine_type = new char[size + 1];
        strcpy(this->engine_type, from.engine_type); //(dst, src)
        this->engine_type[size] = '\0';
    }

    Car& operator=(const Car& from)
    {
        if(this != &from)
        {
            this->Vehicle::operator=(from);
            this->seats = from.seats;

            delete[] this->engine_type;
            int size = strlen(from.engine_type);

            this->engine_type = new char[size + 1];
            strcpy(this->engine_type, from.engine_type); //(dst, src)
            this->engine_type[size] = '\0';
        }
        return *this;
    }
    void print() const
    {
        this->Vehicle::print();
        std::cout << "Seats: " << this->seats << std::endl;
    }
};
class Motorcycle: public Vehicle
{
public:
    Motorcycle()
    {
        this->luggage_capacity = 0;
    }
    Motorcycle(const char* maker, const char* model, const int& horsepower, const int& luggage): Vehicle(maker, model, horsepower)
    {
        this->luggage_capacity = luggage;
    }
    Motorcycle(const int& luggage)
    {
        this->luggage_capacity = luggage;
    }

    void print() const
    {
        this->Vehicle::print();
        std::cout << "Luggage capacity: " << this->luggage_capacity << std::endl;
    }
private:
    int luggage_capacity;
};

class Scooter: public Motorcycle
{
    Scooter(): Motorcycle("", "", 30, 10) {}
    Scooter(const char* maker, const char* model, const int& luggage): Motorcycle(maker, model, 30, luggage){}
};
int main()
{
    Car my_car("Mazda", "6", 140, 5, "I4");
    Car not_my_car("Audi", "A3", 86, 5, "I4");
    Car not_my_second_car = not_my_car;

    not_my_car.print();
    not_my_second_car.print();

    return 0;
}