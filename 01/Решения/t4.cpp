#include <iostream>
#include <cstring>
struct Course{
	char name[100];
	double grade;
};
struct Student{
	int faculty_number;
	Course courses[10];
};

void enter_grades(Student& student, char names[10][100], double grades[10])
{
	for(int i = 0; i < 10; i++)
	{	
		strcpy(student.courses[i].name,names[i]);
		student.courses[i].grade = grades[i];
	}
}
int main()
{	
	Student students[10];
	return 0;
}
