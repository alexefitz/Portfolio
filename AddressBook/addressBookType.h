//addressBookType.

#ifndef H_addressBookType
#define H_addressBookType


#include <string>
#include <fstream>
#include "extpersonType.h"

using namespace std;

//main class that inherits all functions from extPersonType class.
class addressBookType
{
	public:
		void print() const;

		void printNameInTheMonth(int month);
		void printInfoOf(string lname);
		void printNamesWithStatus(string status);
		void printAt(int i);

		void printNamesBetweenLastNames(string last1, string last2);

		void insertAt(const extPersonType& eP, int i);

		void insertLast(const extPersonType& eP);

		int search(string lname);

		void sort();

		void saveData(ofstream&);

		addressBookType();

	private:
		extPersonType list[500];

		int length;
};
#endif