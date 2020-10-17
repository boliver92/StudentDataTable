
#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>

class Student
{
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string email;
	int age;
	int daysToComplete[3];
	DegreeProgram degree;

public:
	Student();
	Student(std::string studentID, std::string firstName, std::string lastName, std::string email,
		int age, int daysToComplete[], std::string degreeProgram);
	Student(std::string studentID, std::string firstName, std::string lastName, std::string email,
		int age, int daysToComplete[], DegreeProgram degreeProgram);

	const std::string GetStudentID();
	void SetStudentID(std::string ID);
	
	const std::string GetFirstName();
	void SetFirstName(std::string firstName);
	
	const std::string GetLastName();
	void SetLastName(std::string lastName);
	
	const std::string GetEmail();
	void SetEmail(std::string email);
	
	const int GetAge();
	void SetAge(int* age);
	
	std::string GetDaysToComplete();
	void SetDaysToComplete(int daysToComplete[]);
	
	std::string GetDegreeProgram();
	void SetDegreeProgram(DegreeProgram degree);
	void SetDegreeProgram(std::string degreeProgram);

	const void Print();

};


#endif // !STUDENT_H

