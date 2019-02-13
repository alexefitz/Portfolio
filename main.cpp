//Name: Alex Fitzmaurice
//Creates a multiplication table based on parameters set by user, 
//then outputs data either to command terminal or a CSV file
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ofstream outFile; //output file that imports csv to desired file location

//function prototypes
void printTable(int rows, int cols);
void printTableWithCSV(int rows, int cols);

int main()
{
	//local variables
	int rows;
	int cols;
	int hold;

	char response;

	//asks the user for desired rows
	cout << "Enter number of rows: ";
	cin >> rows;
	cout << endl;

	//asks user for desired columns
	cout << "Enter number of cols: ";
	cin >> cols;
	cout << endl;

	//asks users if they would like data in a CSV file
	cout << "Would you like to enter data into CSV file? (y,Y/n,N) ";
	cin >> response;
	cout << endl;

	//if user wants data in CSV file, runs CSV function
	if (response == 'y' || response == 'Y')
	{
		printTableWithCSV(rows, cols);
	}
	//else, run regular function
	else
		printTable(rows, cols);

	cout << endl;
	//double backslash in quotes outputs the backslash without error
	cout << "\\" << "the end" << "\\" << endl;
	cin >> hold;
	return 0;
}

//regular function that outputs data in output stream
void printTable(int rows, int cols)
{
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			cout << i * j << "	";
		}
		cout << endl;
	}
}

//function to print data in CSV file
void printTableWithCSV(int rows, int cols)
{
	string filename;
	//asks user what the user wants to call file, in addition to the file path
	cout << "Enter desired file path (with desired file name): ";
	cin >> filename;
	cout << endl;

	//opens file in desired location
	outFile.open(filename);

	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			//outputs data into CSV file. Comma separates each number into a 
			//different cell
			outFile << i * j << ", ";
		}
		outFile << endl;
	}
}
