#pragma once

#include <iostream>
#include <memory> 
#include <string>
#define MY_DEBUG


class Teacher;

class Student
{
public:
	Student(const std::string& name)
	{
		m_name = name;
#ifdef MY_DEBUG
		std::cout << "Student constructor" << std::endl;
#endif
	}
	~Student()
	{
#ifdef MY_DEBUG
		std::cout << "Student destrucor" << std::endl;
#endif
	}

	std::string NAMESTUDENT()
	{
		return m_name;
	}

	std::shared_ptr<Student> GETTEACHER()
	{
		m_teacher;
	}

	friend void TEACHING(std::shared_ptr<Teacher>& teacher, std::shared_ptr<Student>& student);

private:
	std::string m_name;
	std::shared_ptr<Teacher> m_teacher;
};



class Teacher
{
public:
	Teacher(const std::string& name)
	{
		m_name = name;
		m_amount = 0;

#ifdef MY_DEBUG
		std::cout << "Teacher constructor" << std::endl;
#endif
	}
	~Teacher()
	{
#ifdef MY_DEBUG
		std::cout << "Teacher destructor" << std::endl;
#endif
	}

	std::string NAMETEACHER()
	{
		return m_name;
	}

	std::shared_ptr<Student> GETSTUDENT()
	{
		return (m_student[m_amount]);
	}

	void ALLSTUDENT()
	{
		for (int i = 0; i < m_amount; i++)
			std::cout << m_student[m_amount];
	}

	void ADDSTUDENT()
	{
		m_amount = m_amount + 1;
	}

	friend void TEACHING(std::shared_ptr<Teacher>& teacher, std::shared_ptr<Student>& student);

private:

	int m_amount; // количество учащихся
	std::string m_name;
	std::shared_ptr<Student> m_student[5];
};

void TEACHING(std::shared_ptr<Teacher>& teacher, std::shared_ptr<Student>& student)
{
	teacher->ADDSTUDENT();
	student->m_teacher = teacher;
	teacher->GETSTUDENT() = student;
	std::cout << teacher->m_name << "is teaching" << student->m_name << std::endl;
}