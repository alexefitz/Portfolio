//extPersonTypeImp.cpp
#include <iostream>
#include <string>
#include "extPersonType.h"
//further defines each function declared in the extPersonType header file

//prints address of person
void extPersonType::printAddress() const
{
	personType::print();
	cout << endl;
	address.print();
}
//prints personal information
void extPersonType::printInfo() const
{
	personType::print();
	cout << endl;
	cout << "Date of Birth: ";
	dob.printDate();
	cout << endl;
	cout << "Phone Number: " << phoneNumber << endl;
	cout << "Person Type: " << personStatus << endl;
	address.print();
	cout << endl;
}
//sets parameter variables to input file's data.
void extPersonType::setInfo(string fName, string lName,
	int month, int day, int year,
	string street, string c, string s,
	string z, string phone, string pStatus)
{
	personType::setName(fName, lName);
	dob.setDate(month, day, year);
	address.setAddress(street, c, s, z);
	phoneNumber = phone;
	personStatus = pStatus;
}
//same thing as last function with different parameters instead.
void extPersonType::setInfo(string fName, string lName,
	dateType d, addressType ad,
	string phone, string pStatus)
{
	personType::setName(fName, lName);
	dob = d;
	address = ad;
	phoneNumber = phone;
	personStatus = pStatus;
}

//checks if two last names are the same
bool extPersonType::isLastName(string lName) const
{
	return(getLastName() == lName);
}

//fetches the address of a person
void extPersonType::getAddress(string& sAddress, string& c,
	string& s, string& z)
{
	address.getAddress(sAddress, c, s, z);
}

//fetches phone number of a person
string extPersonType::getPhoneNumber() const
{
	return phoneNumber;
}

//fetches status of a person
string extPersonType::getStatus() const
{
	return personStatus;
}

//checks if two statuses are the same.
bool extPersonType::isStatus(string status)
{
	return (status == personStatus);
}

//checks if two DOB's are the same
bool extPersonType::isDOB(int month, int day, int year)
{
	return(dob.getMonth() == month && dob.getDay() == day
		&& dob.getYear() == year);
}

//fetches DOB of a person
void extPersonType::getDOB(int& month, int& day, int& year)
{
	month = dob.getMonth();
	day = dob.getDay();
	year = dob.getYear();
}
bool extPersonType::isMonth(int month) const
{
	return(dob.getMonth() == month);
}

//extPersonType constructor.
extPersonType::extPersonType(string fName, string lName,
	int month, int day, int year,
	string street, string c, string s,
	string z, string phone, string pStatus)
{
	personType::setName(fName, lName);
	dob.setDate(month, day, year);
	address.setAddress(street, c, s, z);
	phoneNumber = phone;
	personStatus = pStatus;
}