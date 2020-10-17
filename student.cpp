#include "student.h"
#include <iomanip>
#include <iostream>
#include <sstream>

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email,
	int age, int daysToComplete[], std::string degreeProgram) {
	
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}

	//Sorts through degreeProgram string to make sure all characters are uppercase.
	for (auto& c : degreeProgram) {
		c = std::toupper(c);
	}

	this->SetDegreeProgram(degreeProgram);
}

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string email,
	int age, int daysToComplete[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degree = degreeProgram;
}

const std::string Student::GetStudentID() {
	return studentID;
}

void Student::SetStudentID(std::string ID) {
	this->studentID = ID;
	return;
}

const std::string Student::GetFirstName() {
	return firstName;
}

void Student::SetFirstName(std::string firstName) {
	this->firstName = firstName;
	return;
}

const std::string Student::GetLastName() {
	return lastName;
}

void Student::SetLastName(std::string lastName) {
	this->lastName = lastName;
	return;
}

const std::string Student::GetEmail() {
	return email;
}

void Student::SetEmail(std::string email) {
	this->email = email;
	return;
}

const int Student::GetAge() {
	return age;
}

void Student::SetAge(int* age) {
	this->age = *age;
}

std::string Student::GetDaysToComplete() {
	std::string str;
	for (int i : daysToComplete) {
		str += std::to_string(i) + " ";
	}
	return str;
}

void Student::SetDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < 3; ++i) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	return;
}

std::string Student::GetDegreeProgram() {
	
	switch (this->degree) {
	case DegreeProgram::SOFTWARE:
		return "SOFTWARE";
		break;

	case DegreeProgram::SECURITY:
		return "SECURITY";
		break;

	case DegreeProgram::NETWORK:
		return "NETWORK";
		break;

	default:
		return "";
		break;
	}
	return "";
}

void Student::SetDegreeProgram(DegreeProgram degree) {
	this->degree = degree;
	return;
}

void Student::SetDegreeProgram(std::string degreeProgram) {
	if (degreeProgram == "SECURITY") {
		this->degree = DegreeProgram::SECURITY;
		return;
	}

	if (degreeProgram == "SOFTWARE") {
		this->degree = DegreeProgram::SOFTWARE;
		return;
	}

	if (degreeProgram == "NETWORK") {
		this->degree = DegreeProgram::NETWORK;
		return;
	}

	return;
}

const void Student::Print() {
	std::cout << std::setw(4) << std::left << this->GetStudentID();
	std::cout << std::setw(13) << std::left << this->GetFirstName();
	std::cout << std::setw(13) << std::left << this->GetLastName();
	std::cout << std::setw(6) << std::left << this->GetAge();
	std::cout << std::setw(18) << std::left << this->GetDaysToComplete();
	std::cout << std::setw(18) << std::left << this->GetDegreeProgram();
	std::cout << std::endl;
}