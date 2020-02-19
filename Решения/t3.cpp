#include <iostream>

enum ProductType{
	perishable,
	packaged,
	heat_resistable,
	stagnated
};

struct Product{
	int count;
	double buy_price;
	double sell_price;
	ProductType type;
};

double calculate_profit(const Product& product)
{
	return (product.sell_price - product.buy_price) * product.count;
}

void create_product(Product& product, int count, double buy, double sell, ProductType type)
{
	product.count = count;
	product.buy_price = buy;
	product.sell_price = sell;
	product.type = type;
}

ProductType convert_int_to_product_type(const int& user_input)
{
	return (ProductType)user_input;
}

void print_product(const Product& product)
{
	std::cout << "Count: " << product.count << std::endl
			  << "Buy price: " << product.buy_price << std::endl
			  << "Sell price: " << product.buy_price << std::endl;
	
	if(product.type == ProductType::perishable)
	{
		std::cout << "Perishable" << std::endl;
	}
	if(product.type == ProductType::packaged)
	{
		std::cout << "Packaged" << std::endl;
	}
	if(product.type == ProductType::heat_resistable)
	{
		std::cout << "Heat resistable" << std::endl;
	}
	if(product.type == ProductType::stagnated)
	{
		std::cout << "Stagnated" << std::endl;
	}
}
int main()
{	
	Product products[10];
	return 0;
}
