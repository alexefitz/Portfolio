//personTypeImp.cpp
#include <iostream>
#include <string>
#include "personType.h"
using namespace std;
//further defines each function declared in personType header file

//prints out name
void personType::print() const
{
	cout << firstName << " " << lastName;
}

//sets name to a different name
void personType::setName(string first, string last)
{
	firstName = first;
	lastName = last;
}

//fetches first name of a person
string personType::getFirstName() const
{
	return firstName;
}

//fetches last name of a person
string personType::getLastName() const
{
	return lastName;
}
//personType constructor
personType::personType(string first, string last)
{
	firstName = first;
	lastName = last;
}