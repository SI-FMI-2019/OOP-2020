#include <iostream>

enum ProductType
{
    PERISHABLE,     // 0
    PACKED,         // 1
    HEAT_ENDURABLE, // 2
    STAGNANT        // 3
};

struct Product
{
    int number;
    double priceForBuying;
    double priceForSelling;
    ProductType type;
};

double calculateProfit(const Product& product)
{
    return (product.priceForSelling - product.priceForBuying) * product.number;
}

void input(Product& product)
{
    std::cout << "Enter number: ";
    std::cin >> product.number;
    std::cout << "Enter buying price: ";
    std::cin >> product.priceForBuying;
    std::cout << "Enter selling price: ";
    std::cin >> product.priceForSelling;
    
    std::cout << "1) PERISHABLE" << std::endl;
    std::cout << "2) PACKED" << std::endl;
    std::cout << "3) HEAT_ENDURABLE" << std::endl;
    std::cout << "4) STAGNANT" << std::endl;
    std::cout << "Enter type: " << std::endl; 
    
    int type = 0;
    std::cin >> type;
    product.type = (ProductType) (type - 1);
}

int main()
{
    Product product;
    input(product);

    std::cout << calculateProfit(product) << std::endl;

    Product products[20];

    return 0;
}