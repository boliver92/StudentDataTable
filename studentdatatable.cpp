/*
*   Brian Oliver, ID# 001321694
*   WGU C867- Scripting and Programming - Applications
*   10/08/2020
*   
*   The program must contain two classes (Student and Roster)
*   The program within maintain a roster of students within a given course.
*
*/

#include <iostream>
#include <string>
#include <vector>
#include "roster.h"
#include "degree.h"

int main()
{
    std::cout << "Course ID: C867 - Scripting and Programming - Applications" << std::endl;
    std::cout << "Programming Language: C++" << std::endl;
    std::cout << "WGU Student ID: 001321694" << std::endl;
    std::cout << "Student Name: Brian Oliver" << std::endl << std::endl;

    const std::string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Brian,Oliver,boliv64@wgu.edu,28,60,5,22,SOFTWARE", 
        };
    std::vector<std::string> parsedString;
    Roster* classRoster = new Roster();
    
    //Parses each string in studentData and splits at each ',' and puts it into parsedString.
    for (int i = 0; i < 5; ++i) {
        int lastIndex = 0;
        std::string strToParse = studentData[i] + ',';
        for (unsigned j = 0; j < strToParse.length(); ++j) {
            if (strToParse[j] == ',') {
                std::string parsed = strToParse.substr(lastIndex, j - lastIndex);
                parsedString.push_back(parsed);
                lastIndex = j + 1;
            }
        }
    }

    //Used to sort the parsed vector to create the roster. Starting the index at 4 since it is the midpoint of each set of strings.
    unsigned index = 4;
    while (index <= parsedString.size()) {
        std::string id = parsedString.at(index - 4);
        std::string firstName = parsedString.at(index - 3);
        std::string lastName = parsedString.at(index - 2);
        std::string email = parsedString.at(index - 1);
        int age = std::stoi(parsedString.at(index));
        int day1 = std::stoi(parsedString.at(index + 1));
        int day2 = std::stoi(parsedString.at(index + 2));
        int day3 = std::stoi(parsedString.at(index + 3));
        if (parsedString.at(index + 4) == "SOFTWARE") {
            DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
            classRoster->add(id, firstName, lastName, email, age, day1, day2, day3, degreeProgram);
        }
        if (parsedString.at(index + 4) == "SECURITY") {
            DegreeProgram degreeProgram = DegreeProgram::SECURITY;
            classRoster->add(id, firstName, lastName, email, age, day1, day2, day3, degreeProgram);
        }
        if (parsedString.at(index + 4) == "NETWORK") {
            DegreeProgram degreeProgram = DegreeProgram::NETWORK;
            classRoster->add(id, firstName, lastName, email, age, day1, day2, day3, degreeProgram);
        }
        index += 9;
    }
    
    classRoster->printAll();
    classRoster->printInvalidEmails();
    std::cout << "Printing the average days in each course student: " << std::endl;
    for (int i = 0; i < classRoster->getStudentVector().size(); ++i) {
        classRoster->printAverageDaysInCourse(classRoster->getStudentVector().at(i)->GetStudentID());
    }
    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");
    delete classRoster;
    

}

