#include <iostream>
enum ProductType{
	perishable,
	packaged,
	heat_resistable,
	stagnated
};

class Product{
public:
    double calculate_profit();
    void create_product(int count, double buy, double sell, ProductType type);
    void print_product();
private:
    ProductType convert_int_to_product_type(const int& user_input);
	int count;
	double buy_price;
	double sell_price;
	ProductType type;
};