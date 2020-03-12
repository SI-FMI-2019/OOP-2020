#include "Product.hpp"

double Product::calculate_profit()
{
	return (this->sell_price - this->buy_price) * this->count;
}

void Product::create_product(int count, double buy, double sell, ProductType type)
{
	this->count = count;
	this->buy_price = buy;
	this->sell_price = sell;
	this->type = type;
}

ProductType Product::convert_int_to_product_type(const int& user_input)
{
	return (ProductType)user_input;
}

void Product::print_product()
{
	std::cout << "Count: " << this->count << std::endl
			  << "Buy price: " << this->buy_price << std::endl
			  << "Sell price: " << this->buy_price << std::endl;
	
	if(this->type == ProductType::perishable)
	{
		std::cout << "Perishable" << std::endl;
	}
	if(this->type == ProductType::packaged)
	{
		std::cout << "Packaged" << std::endl;
	}
	if(this->type == ProductType::heat_resistable)
	{
		std::cout << "Heat resistable" << std::endl;
	}
	if(this->type == ProductType::stagnated)
	{
		std::cout << "Stagnated" << std::endl;
	}
}