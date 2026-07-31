#include "student.h"

//Parameterless constructor (sets default values)
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < numCourses; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;

}
//d.2.d constructor using all of the input parameters provided in the table
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse[numCourses], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	int i = 0;
	for (i = 0; i < numCourses; i++) { this->daysInCourse[i] = daysInCourse[i]; }
	this->degreeProgram = degreeProgram;
}

//d.2.a. an accessor (i.e., getter) for each instance variable from part D1
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//d.3.b. a mutator (i.e., setter) for each instance variable from part D1
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int* daysInCourse[])
{
	for (int i = 0; i < numCourses; i++) this->daysInCourse[i] = *daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader()
{
	cout << "Output format:\nStudent ID | First and Last name | Email address | Age | Average days in course | Degree program\n";
}

//d.2.e. print() to print specific student data
void Student::print()
{
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse()[0] << ',';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; //degreeprogram to string}
}

// Destructor
Student::~Student() {}


