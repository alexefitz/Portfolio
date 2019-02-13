
//This main program gives user the choice to save the data in the address book.

#include <iostream>
#include <fstream>
#include <string>
#include "addressBookType.h"

using namespace std;

void loadAddressBook(addressBookType& adBook);
void saveData(addressBookType& adBook);

void showMenu();

int main()
{
	//local variables will be set to values in input file
	addressBookType addressBook;
	string str;
	string str1;
	string str2;
	int choice;
	int loc;
	int month;
	int hold;

	//loads in data from input file
	loadAddressBook(addressBook);

	//sorts the data from input file alphabetically
	addressBook.sort();

	//prints out menu of choices user can choose.
	showMenu();

	cin >> choice;
	//makes sure user has inputted correct input
	while (!cin || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 &&
		choice != 7 && choice != 9))
	{
		cout << "Invalid choice. Enter a valid option please: ";
		cin.clear();
		cin.ignore();
		cin >> choice;
	}
	cin.ignore(100, '\n');

	//loops until user wants to quit program.
	while (choice != 9)
	{
		switch (choice)
		{
			//first case that checks if a certain last name is in program. Returns basically true/false.
			case 1:
				cout << "Enter the last name of the person: ";
				getline(cin, str);
				cout << endl;

				loc = addressBook.search(str);

				if (loc != -1)
					cout << str << " is in the address book" << endl;
				else
					cout << str << " is not in the address book" << endl;
				break;
			//second case prints out data of a certain person in address book
			case 2:
				cout << "Enter the last name of the person: ";
				getline(cin, str);
				cout << endl;

				loc = addressBook.search(str);

				if (loc != -1)
					addressBook.printAt(loc);
				else
					cout << str << " is not in the address book" << endl;
				break;
			//third case returns people based on birth month.
			case 3:
				cout << "Enter the month number: ";
				cin >> month;
				cin.ignore(100, '\n');
				cout << endl;

				addressBook.printNameInTheMonth(month);
				break;
			//fourth case returns every person in a certain range of last names.
			case 4:
				cout << "Enter starting last name: ";
				getline(cin, str1);
				cout << endl;
				cout << "Enter ending last name: ";
				getline(cin, str2);
				cout << endl;

				addressBook.printNamesBetweenLastNames(str1, str2);
				break;
			//fifth case returns people with a certain status
			case 5:
				cout << "Enter person type (Family, Friend, or Business): ";
				getline(cin, str);
				cout << endl;
				addressBook.printNamesWithStatus(str);
				break;
			//prints the whole address book
			case 6:
				addressBook.print();
				break;
			//saves current data in the output file
			case 7:
				saveData(addressBook);
				break;
			default:
				cout << "Invalid choice" << endl;
		}
		showMenu();
		cin >> choice;
		cin.ignore(100, '\n');
	}
	cin >> hold;
	return 0;
}

//function to load in data from input file into separate variables.
void loadAddressBook(addressBookType& adBook)
{
	ifstream infile;
	//char fileName[50];
	string fileName;
	string first;
	string last;
	int month;
	int day;
	int year;
	string street;
	string city;
	string state;
	string zip;
	string phone;
	string pStatus;
	extPersonType temp;
	cout << "Enter file name: ";
	cin >> fileName;
	fileName = "C:/Users/afitzmaurice625/Desktop/" + fileName + ".txt";
	cout << endl;
	infile.open(fileName);
	if (!infile)
	{
		cout << "Input file does not exists. "
			<< "Program terminates!!!" << endl;
		exit(0);
	}

	int i = 0;
	infile >> first >> last >> month >> day >> year;
	infile >> street >> city >> state;
	infile >> zip >> phone >> pStatus;
	while (infile)
	{
		temp.setInfo(first, last, month, day, year, street, city,
			state, zip, phone, pStatus);
		adBook.insertAt(temp, i);
		i++;
		infile >> first >> last >> month >> day >> year;
		infile >> street >> city >> state;
		infile >> zip >> phone >> pStatus;
	}
}

//saves current data into output file.
void saveData(addressBookType& adBook)
{
	ofstream outfile;
	//char fileName[50];
	string fileName;
	cout << "Enter file name: ";
	cin >> fileName;
	fileName = "C:/Users/afitzmaurice625/Desktop/" + fileName + ".txt";
	cout << endl;
	outfile.open(fileName);
	if (!outfile)
	{
		cout << "Unable to create the output file. "
			<< "Program terminates!!!" << endl;
		return;
	}
	adBook.saveData(outfile);
}

//prints out menu of choices available to user.
void showMenu()
{
	cout << "Welcome to the address book program." << endl;
	cout << "Choose among the following options:" << endl;
	cout << "1: To see if a person is in the address book"
		<< endl;
	cout << "2: Print the information of a person" << endl;
	cout << "3: Print the names of person having birthday in "
		<< "a particular month" << endl;
	cout << "4: Print the names of persons between two "
		<< "last names" << endl;
	cout << "5: Print the names of persons having a "
		<< "particular status" << endl;
	cout << "6: Print the address book" << endl;
	cout << "7: Save data" << endl;
	cout << "9: Terminate the program" << endl;
}