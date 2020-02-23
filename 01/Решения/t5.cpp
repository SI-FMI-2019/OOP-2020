#include <iostream>

struct Rectangle {
	int length;
	int width;
};

void print_rectangle(Rectangle r) {
	std::cout << "Length is: " << r.length << "\n";
	std::cout << "Width is: " << r.width << "\n";
	std::cout << "\n";
}

void init_rectangle(Rectangle & r) {
	do {
		std::cout << "Enter length: ";
		std::cin >> r.length;
		std::cout << "Enter width: ";
		std::cin >> r.width;
		std::cout << "\n";
	} while (r.length <= 0 || r.width <= 0);
}

Rectangle create_rectangle() {
	Rectangle r;
	init_rectangle(r);
	return r;
}


int main()
{
	std::cout << "Rectangle r\n";
	Rectangle r;
	init_rectangle(r);
	print_rectangle(r);

	std::cout << "Rectangle d\n";
	Rectangle d = create_rectangle();
	print_rectangle(d);
}
