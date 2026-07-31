#pragma once
#include "student.h"
class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	

public:
	/* e.1.Create an array of pointers, classRosterArray, to hold the data provided in the
	“studentData Table.” */
	Student* classRosterArray[numStudents];

	// e.2. Create a student object for each student in the data table and populate classRosterArray.
	void parseStudentData(string studentData);

	/* e.3.a. public void add(string studentID, string firstName, string lastName, string emailAddress, 
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)  
	that sets the instance variables from part D1 and updates the roster.*/
	void add(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);

	/* e.3.b. public void remove(string studentID)  that removes students from the roster by student ID.
	If the student ID does not exist, the function prints an error message indicating that the student 
	was not found. */
	void remove(string studentID);

	/* e.3.c.public void printAll() that prints a complete tab-separated list of student data in the 
	provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: 
	{35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students 
	in classRosterArray and call the print() function for each student. */
	void printAll();

	/* e.3.d. public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s 
	average number of days in the three courses. The student is identified by the studentID parameter.*/
	void printAverageDaysInCourse(string studentID);

	/* e.3.e. public void printInvalidEmails() that verifies student email addresses and displays all 
	invalid email addresses to the user. */
	void printInvalidEmails();

	/* e.3.f. public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student 
	information for a degree program specified by an enumerated type. */
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};
