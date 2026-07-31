// c867 pa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

int main()
{
	const int numStudents = 5;
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Bryan,Huynh,hhuyn35@wgu.edu,27,40,30,35,SOFTWARE"
	};

	/* f.1.Print out to the screen, via your application, the course title, the programming language used,
	 your WGU student ID, and your name. */
	cout << "C867 - Scripting and Programming Applications" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU Student ID: 011920597" << endl;
	cout << "Bryan Huynh\n" << endl;

	//f.2. Create an instance of the Roster class called classRoster.
	Roster classRoster;

	//f.3. Add each student to classRoster.
	int i = 0;
	for (i - 0; i < numStudents; i++)
	{
		classRoster.parseStudentData(studentData[i]);
	}

	/* f.4 Convert the following pseudo code to complete the rest of the  main() function:
	classRoster.printAll(); classRoster.printInvalidEmails(); */
	cout << "Class roster " << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Invalid emails: " << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	cout << "Student average days in course: " << endl;
	for (int i = 0l; i < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	cout << "Students in Software program: " << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Remove student A3" << endl;
	classRoster.remove("A3");
	cout << endl;

	cout << "Updated class roster:" << endl;
	classRoster.printAll();
	cout << endl;

	// should return "student not found"
	cout << "Remove student A3 again" << endl;
	classRoster.remove("A3");
	cout << endl;
}
