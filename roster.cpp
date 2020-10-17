#include "roster.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>

Roster::~Roster() {
	std::cout << "Deconstructor called: Deleting student pointer (Roster object)" << std::endl;;
	delete student;
	return;
}
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int DaysInCourse3, DegreeProgram degreeprogram) {

	int daysInCourse[3] = { daysInCourse1, daysInCourse2, DaysInCourse3 };
	student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
	this->classRosterArray.push_back(student);
	
}

void Roster::remove(std::string studentID) {
	for (unsigned i = 0; i < classRosterArray.size(); ++i) {
		if (classRosterArray.at(i)->GetStudentID() == studentID) {
			std::cout << std::endl << "Removing student with ID: " << studentID << std::endl << std::endl;
			classRosterArray.erase(classRosterArray.begin() + i);
			return;
		}
	}
	std::cout << std::endl<< "A student with this ID (" << studentID << ") was not found." << std::endl;
	return;
}

void Roster::printAll() {
	std::cout << std::setw(4) << std::left << "ID";
	std::cout << std::setw(13) << std::left << "First Name";
	std::cout << std::setw(13) << std::left << "Last Name";
	std::cout << std::setw(6) << std::left << "Age";
	std::cout << std::setw(18) << std::left << "Days in Course";
	std::cout << std::setw(18) << std::left << "Degree Program";
	std::cout << std::endl;

	for (unsigned i = 0; i < classRosterArray.size(); ++i) {
		classRosterArray.at(i)->Print();
	}
}

void Roster::printAverageDaysInCourse(std::string studentID) {
	std::string strToParse;
	std::vector<int> daysToComplete;
	for (unsigned i = 0; i < classRosterArray.size(); ++i) {
		if (classRosterArray.at(i)->GetStudentID() == studentID) {
			strToParse = classRosterArray.at(i)->GetDaysToComplete();
			break;
		}
	}
	if (strToParse.length() > 0) {
		int lastIndex = 0;
		for (unsigned j = 0; j < strToParse.length(); ++j) {
			if (strToParse[j] == ' ') {
				std::string parsed = strToParse.substr(lastIndex, j - lastIndex);
				int parsedInt = std::stoi(parsed);
				daysToComplete.push_back(parsedInt);
				lastIndex = j + 1;
			}
		}
	}

	int sum = std::accumulate(daysToComplete.begin(), daysToComplete.end(), 0);
	double average = static_cast<double>(sum) / static_cast<double>(daysToComplete.size());
	std::cout << studentID << ": " << average << std::endl;
	
	return;
}

void Roster::printInvalidEmails() {
	std::cout << std::endl << "Printing invalid emails: " << std::endl;
	for (int i = 0; i < classRosterArray.size(); ++i) {
		std::string email = classRosterArray.at(i)->GetEmail();
		bool hasAt = false;
		bool hasDot = false;
		for (int j = 0; j < email.length(); ++j) {
			char c = email[j];
			if (std::isspace(c)) {
				std::cout << email << std::endl;
				break;
			}
			if (c == '.') {
				hasDot = true;
			}
			if (c == '@') {
				hasAt = true;
			}
			if (j == email.length() - 1) {
				if (hasDot == false) {
					std::cout << email << std::endl;
				}
				if (hasAt == false) {
					std::cout << email << std::endl;
				}
			}
		}
	}
	std::cout << std::endl;
	return;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
	if (degreeProgram == DegreeProgram::SOFTWARE) {
		std::cout << std::endl << "Printing students enrolled in Software degree: " << std::endl << std::endl;
	}
	if (degreeProgram == DegreeProgram::SECURITY) {
		std::cout << std::endl << "Printing students enrolled in Security degree: " << std::endl << std::endl;
	}
	if (degreeProgram == DegreeProgram::NETWORK) {
		std::cout << std::endl << "Printing students enrolled in Network degree: " << std::endl << std::endl;
	}

	std::cout << std::setw(4) << std::left << "ID";
	std::cout << std::setw(13) << std::left << "First Name";
	std::cout << std::setw(13) << std::left << "Last Name";
	std::cout << std::setw(6) << std::left << "Age";
	std::cout << std::setw(18) << std::left << "Days in Course";
	std::cout << std::setw(18) << std::left << "Degree Program";
	std::cout << std::endl;

	for (int i = 0; i < classRosterArray.size(); ++i) {
		std::string degreeProgramStr = classRosterArray.at(i)->GetDegreeProgram();
		if (degreeProgramStr == "SOFTWARE" && degreeProgram == DegreeProgram::SOFTWARE) {
			classRosterArray.at(i)->Print();
			continue;
		}
		if (degreeProgramStr == "SECURITY" && degreeProgram == DegreeProgram::SECURITY) {
			classRosterArray.at(i)->Print();
			continue;
		}
		if (degreeProgramStr == "NETWORK" && degreeProgram == DegreeProgram::NETWORK) {
			classRosterArray.at(i)->Print();
			continue;
		}
	}

	return;
}