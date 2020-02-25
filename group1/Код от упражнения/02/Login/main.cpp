#include <iostream>
#include "Login.hpp"
int main()
{	
    Login a("lyubo", "password");
    std::cout << a.login("lyubo", "one1");
	return 0;
}
