#include <iostream> 
#include "MyArray.hpp" //hpp е по-правилния начин (защото hpp e C++ header, а .h е C header)

int main() {

	MyArray temp, temp2, temp4;

	for(int i = 0; i < 5; i++)
	{
		temp.insert_at(i * 3, i);  //0 3 6 9 12
		temp2.insert_at(i * 2, i); //0 2 4 6 8
	}
	
	/*MyArray temp3 = temp + temp2;

	for(int i = 0; i < 5; i++)
	{
		std::cout << temp3.get_at(i) << " ";
	}*/
	//Какво ще се изведе ?

	//0 5 10 15 20
	return 0;
}