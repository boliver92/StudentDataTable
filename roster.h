#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <vector>
#include "degree.h"

class Roster
{
private:
	std::vector<Student*> classRosterArray;
	Student* student;

public:

	~Roster();
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int DaysInCourse3, DegreeProgram degreeprogram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	std::vector<Student*> getStudentVector() { return classRosterArray; };

};

#endif // !ROSTER_H

