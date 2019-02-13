#include <iostream>
#include <string>
#include "addressType.h"
using namespace std;
//further defines each function declared in the addressType header file

//prints out full address of a person
void addressType::print() const
{
	cout << streetAddress << endl;
	cout << city << ", " << state << " - " << zip << endl;
}

//sets person's address to a different address.
void addressType::setAddress(string sAddress, string c,
	string s, string z)
{
	streetAddress = sAddress;
	city = c;
	state = s;
	zip = z;
}

//fetches address of a person
void addressType::getAddress(string& sAddress, string& c,
	string& s, string& z)
{
	sAddress = streetAddress;
	c = city;
	s = state;
	z = zip;
}

//addressType constructor.
addressType::addressType(string sAddress, string c,
	string s, string z)
{
	streetAddress = sAddress;
	city = c;
	state = s;
	zip = z;
}