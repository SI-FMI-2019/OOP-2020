#include <iostream>

struct Snake{
	int x;
	int y;
};

int get_x(const Snake& instance)
{
	return instance.x;
}
int get_y(const Snake& instance)
{
	return instance.y;
}

void set_x(Snake& instance, int new_x)
{
	instance.x = new_x;
}

void set_y(Snake& instance, int new_y)
{
	instance.y = new_y;
}

int main()
{
	
	return 0;
}
