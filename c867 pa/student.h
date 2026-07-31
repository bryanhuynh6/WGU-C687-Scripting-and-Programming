#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

#ifndef student_h
#define student_h

class Student
{
public:
	const static int numCourses = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[numCourses];
	DegreeProgram degreeProgram;

public:
	//Parameterless constructor (sets default values)
	Student();

	//d.2.d. constructor using all of the input parameters provided in the table
	Student(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse[numCourses], DegreeProgram degreeProgram);

	//Destructor
	~Student();

	//d.2.a. an accessor (i.e., getter) for each instance variable from part D1
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	//d.2.b. a mutator (i.e., setter) for each instance variable from part D1
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int* daysInCourse[]);
	void setDegreeProgram(DegreeProgram getDegreeProgram);

	static void printHeader();

	//d.2.e. print() to print specific student data
	void print();

};

#endif