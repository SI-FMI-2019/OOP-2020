#include <iostream> 

//Добавете се в аудио канала
//Щото вероятно няма да пиша в чата :D 
//От лявата страна, където е менюто, там трябва да идете, ще ви излезе информация кой е в чата
//По-долу, има и едно 'Audio Call Participants'


class Foo{
public:
	Foo()
	{
		std::cout << "Constructor called";
		this->a = new int[5]; //Ако заделим памет в конструктора
		//Винаги ако имаме new, трябва да имаме и delete
	}
	~Foo()
	{
		std::cout << "Destructor called";

		delete[] this->a; //То в деструктора трябва да си я освободим
	}
private:
	int* a;
};
int main() {

	Foo temp; //<- Колко време живее тя ? (Къде е видима ?) -> В целия score на main()
	//Какво се случва при нейното създаване ? (Функция която се извиква ?) -> Извиква се конструктора
	//Какво се случва при нейното "умиране" (когато спре да живее) ? -> Извиква се деструктор

	//Деструктора е метод, който се извиква, когато променливата "умира"

	//Синтаксиса на деструктора - пред името на класа се слага ~Име_на_класа()

	//За какво може да ни е нужен този деструктор ? (Свързано е с динамичната памет)
	//Ако няма деструктор, няма ли да се изтрие ? -> ще си се изтрие

	//Дотук някакви въпроси ?

	//Защо изтриваме ? Защото сме я заделили с new (винаги)
	//Други въпроси ?

	
	return 0;
}