#ifndef AUTOMOBILE_HPP
#define AUTOMOBILE_HPP

class Automobile
{
public:
	Automobile();
	Automobile(const unsigned, const char*, const unsigned, const double);
	Automobile(const Automobile&);
	Automobile& operator=(const Automobile&);
	~Automobile();

	void upgrade(const unsigned);
	unsigned getHp() const;
private:
	unsigned hp;
	char* model;
	unsigned year;
	double price;

	void copyData(const unsigned, const char*, const unsigned, const double);
};

#endif // !AUTOMOBILE_HPP
