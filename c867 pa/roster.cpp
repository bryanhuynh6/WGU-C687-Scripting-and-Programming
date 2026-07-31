#include "roster.h"
void Roster::parseStudentData(string studentData)
{
	// parse student ID
	int rhs = studentData.find(',');
	string sID = studentData.substr(0, rhs);

	// parse first name
	int lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	string sFirstName = studentData.substr(lhs, rhs - lhs);

	// parse last name
	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	string sLastName = studentData.substr(lhs, rhs - lhs);

	// parse email
	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	string sEmailAddress = studentData.substr(lhs, rhs - lhs);

	// parse age
	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	int sAge = stoi(studentData.substr(lhs, rhs - lhs));

	// parse days in course 1
	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	// parse days in course 2
	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	// parse days in course 3
	lhs = rhs + 1;
	rhs = studentData.find(',', lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);

	// parse degree program
	DegreeProgram sDegreeProgram = SECURITY;
	
	if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'E') sDegreeProgram = SECURITY;
	else if (studentData.at(lhs) == 'S' && studentData.at(lhs + 1) == 'O') sDegreeProgram = SOFTWARE;
	else if (studentData.at(lhs) == 'N') sDegreeProgram = NETWORK;

	add(sID, sFirstName, sLastName, sEmailAddress, sAge, daysInCourse1, daysInCourse2, daysInCourse3,
		sDegreeProgram);
}
// e.3.a public void add
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age,
		daysInCourse, degreeProgram);
}

//e.3.b public void remove
void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << " removed from roster." << std::endl;
	}
	else cout << "Student " << studentID << " not found." << std::endl << std::endl;
}

// e.3.c public void printAll()
void Roster::printAll()
{
	// call print() function for each student
	for (int i = 0; i <= Roster::lastIndex; i++)
		Roster::classRosterArray[i]->print();
}

// e.3.d public void printAverageDaysInCourse (string studentID)
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{

			cout << classRosterArray[i]->getStudentID() << ": ";
			cout << (classRosterArray[i]->getDaysInCourse()[0]
				+ classRosterArray[i]->getDaysInCourse()[1]
				+ classRosterArray[i]->getDaysInCourse()[2]) / 3.0 << std::endl;
		}
	}
}

// e.3.e. public void printInvalidEmails()
void Roster::printInvalidEmails()
{
	bool invalidEmail = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string emailToCheck = (classRosterArray[i]->getEmailAddress());

		if ((emailToCheck.find("@") == string::npos) || (emailToCheck.find(" ") != string::npos)
			|| (emailToCheck.find(".") == string::npos))
		{
			invalidEmail = true;
			cout << emailToCheck << ": " << classRosterArray[i]->getFirstName() << std::endl;
		}
	}
	if (!invalidEmail) cout << "No email found." << std::endl;
}

// e.3.f printByDegreeProgram(DegreeProgram degreeProgram	
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << std::endl;
}

// f.5. Implement the destructor to release the memory that was allocated dynamically in Roster.
Roster::~Roster()
{
	cout << "Roster has been cleared." << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Removing student" << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}