#include <iostream>
#include <memory> 
#include <string>
#include "class.hpp"


int main()
{
	std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>("Teacher");

	std::shared_ptr<Student> student1 = std::make_shared<Student>("Stud_1");

	std::shared_ptr<Student> student2 = std::make_shared<Student>("Stud_2");
	
	TEACHING(teacher, student1);
	TEACHING(teacher, student2);

	return 0;
}