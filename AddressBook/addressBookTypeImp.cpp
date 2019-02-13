//addressBookTypeImp.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "addressBookType.h"

using namespace std;
//further defines each function declared in the addressBookType header file.

//prints all info in the address book
void addressBookType::print() const
{
	for (int i = 0; i < length; i++)
		list[i].printInfo();
}

//prints names based on birth month
void addressBookType::printNameInTheMonth(int month)
{
	for (int i = 0; i < length; i++)
	{
		if (list[i].isMonth(month))
		{
			list[i].print();
			cout << endl;
		}
	}
}

//prints personal info of a single person
void addressBookType::printInfoOf(string lName)
{
	int i = search(lName);
	if (i != -1)
		list[i].printInfo();
	else
		cout << lName << " is not in address book." << endl;
}

//prints names based on their status.
void addressBookType::printNamesWithStatus(string status)
{
	for (int i = 0; i < length; i++)
		if (list[i].isStatus(status))
		{
			list[i].print();
			cout << endl;
		}
}

//prints name at a certain position in the address book
void addressBookType::printAt(int i)
{
	if (i < length)
		list[i].printInfo();
	else
		cout << "No such person" << endl;
}

//prints range of names between two different last names
void addressBookType::printNamesBetweenLastNames(string last1, string last2)
{
	string lName;
	for (int i = 0; i < length; i++)
	{
		lName = list[i].getLastName();
		if (last1 <= lName && lName <= last2)
		{
			list[i].print();
			cout << endl;
		}
	}
}

//inserts data into a position in the extPersonType array
void addressBookType::insertAt(const extPersonType& eP, int i)
{
	list[i] = eP;
	if (i == length)
		length++;
}

//inserts data into the last position of the extPersonType array.
void addressBookType::insertLast(const extPersonType& eP)
{
	list[length] = eP;
	length++;
}

//searches address book for a certain person, and returns true if function finds that person
int addressBookType::search(string lName)
{
	bool found = false;
	int i;
	for (i = 0; i < length; i++)
		if (list[i].isLastName(lName))
		{
			found = true;
			break;
		}
	if (found && i < length)
		return i;
	else
		return -1;
}

//sorts data from input file alphabetically
void addressBookType::sort()
{
	string str1;
	string str2;
	int i, j;
	extPersonType temp;
	int minIndex;
	for (i = 0; i < length - 1; i++)
	{
		minIndex = i;
		str1 = list[minIndex].getLastName();
		for (j = i + 1; j < length; j++)
		{
			str2 = list[j].getLastName();
			str1 = list[minIndex].getLastName();
			if (str1 > str2)
				minIndex = j;
		}
		temp = list[minIndex];
		list[minIndex] = list[i];
		list[i] = temp;
	}
}

//default constructor
addressBookType::addressBookType()
{
	length = 0;
}

//saves data in output file
void addressBookType::saveData(ofstream& outFile)
{
	int month;
	int day;
	int year;
	string street;
	string city;
	string state;
	string zip;
	string phone;
	string pStatus;
	for (int i = 0; i < length; i++)
	{
		list[i].getDOB(month, day, year);
		list[i].getAddress(street, city, state, zip);
		outFile << list[i].getFirstName() << " "
			<< list[i].getLastName() << endl;
		outFile << month << " " << day << " " << year << endl;
		outFile << street << endl << city << endl << state
			<< endl << zip << endl;
		outFile << list[i].getPhoneNumber() << endl
			<< list[i].getStatus() << endl;
	}
}