#include <iostream>

struct Student {
	int faculty_number;
	char* name;
	char egn[10];
};

void set_faculty_number(Student& student)
{
	int faculty_num = 0;
	std::cin >> faculty_num;
	student.faculty_number = faculty_num;
}

int get_faculty_number(const Student& student)
{
	return student.faculty_number;
}

int main()
{
	Student temp;
	set_faculty_number(temp);

	std::cout << get_faculty_number(temp);
	return 0;
}