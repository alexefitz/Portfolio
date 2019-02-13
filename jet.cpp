/*
Name: Alex Fitzmaurice
Date: 10.09.2018
Description: Boeing Business Jet three-class (BBJ3)
*/

using namespace std;

#include <iostream>
#include <array>
#include <iomanip>

//global variables
char firstClass[3][4] = { {'*', '*', '*', '*'}, { '*', ' ', ' ', '*'}, {'*', '*', '*', '*'} };
char businessClass[2][4] = { { '*', '*', ' ', '*' }, { '*', '*', ' ', '*' } };
char economy[3][4] = { { '*', '*', '*', '*' },{ '*', '*', '*', '*' }, {'*', '*', '*', '*'} };
double totalPrice = 0.0;
int firstClassTickets = 0;
int businessTickets = 0;
int economyTickets = 0;
double firstClassPrice = 0.0;
double businessPrice = 0.0;
double economyPrice = 0.0;


//prototypes
void displayLayout();
void displayLayout(int section);
void chooseSeats();
void itemizeTicekts(int section);
void printReceipt(int totalPrice);
void selectionChange(int section);

int main()
{
	//variables
	int hold;
	int sectionChoice = 0;

	//user interaction
	cout << "This program is used to purchase tickets on a Boeing Business Jet 3. " << endl;
	cout << "The seat layout is as follows: " << endl << endl;
	chooseSeats();

	cin >> hold;
	return 0;
}

//function to display the entire plane layout, which shows if any seats have been purchased or not
void displayLayout()
{
	//this function uses 3 different nested for loops, in order to loop through each 2d array, for each different class on the plane.
	cout << "\t1 2 3 4" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Row  " << i + 1 << "  ";
		for (int j = 0; j < 4; j++)
			cout << firstClass[i][j] << ' ';
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 2; i++)
	{
		cout << "Row  " << i + 4 << "  ";
		for (int j = 0; j < 4; j++)
			cout << businessClass[i][j] << ' ';
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "Row  " << i + 6 << "  ";
		for (int j = 0; j < 4; j++)
			cout << economy[i][j] << ' ';
		cout << endl;
	}

	//these outputs describe which sections are what, in addition to a small description of each section
	cout << "Rows 1-3 are First Class seats in a conference room. " << endl
		<< "Rows 4-5 are Business Class seats with a couch on the side. " << endl
		<< "Rows 6-8 are Economy Class seats. " << endl;
	cout << endl << endl;
}

//this is an overloaded function of the last function, except it only prints out a certain section, instead of the entire layout.
void displayLayout(int section)
{
	switch (section)
	{
		case 1:
		{
			cout << "\t1 2 3 4" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << "Row  " << i + 1 << "  ";
				for (int j = 0; j < 4; j++)
					cout << firstClass[i][j] << ' ';
				cout << endl;
			}
			break;
		}//end case1
		case 2:
		{
			cout << "\t1 2 3 4" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout << "Row  " << i + 4 << "  ";
				for (int j = 0; j < 4; j++)
					cout << businessClass[i][j] << ' ';
				cout << endl;
			}
			break;
		}//end case2
		case 3:
		{
			cout << "\t1 2 3 4" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << "Row  " << i + 6 << "  ";
				for (int j = 0; j < 4; j++)
					cout << economy[i][j] << ' ';
				cout << endl;
			}
			break;
		}//end case3
		default:
		{
			break;
		}
	}
}

//function that asks the user which section they would like. It also calls upon two more functions: itemizeTickets and printReceipt.
void chooseSeats()
{
	int section = 0;
	char check = ' ';

	displayLayout();
	cout << "What section would you like to travel in today? "
		<< "\n(Select 1 for First Class, 2 for Business, "
		<< " 3 for Economy, or 99 to Exit): ";
	cin >> section;
	//this piece of code is replicated throughout the program, and it makes sure that the user actually inputs a correct input.
	while ((section != 1 && section != 2 && section != 3 && section != 99))
	{
		cout << "That was not a valid option! Please enter a valid option: ";
		cin.clear();
		cin.ignore();
		cin >> section;
	}//end while
	cout << endl;

	//this switch runs through each section, and it also has an exception handler in case the user wants to change their mind about what
	//section they actually want to browse.
	switch (section)
	{
		case 1:
		{
			cout << "You have selected 1 for First Class. These tickets have a cost of $1,299.99. "
				<< "Are you sure this is your selection? \n(Enter Y/y for Yes or N/n for No): ";
			cin >> check;
			cout << endl;

			if (check == 'Y' || check == 'y')
				itemizeTicekts(section);
			else
			{
				section = 0;
				cout << "Please select a section you would actually like to browse, please. "
					<< "\n(Select 1 for First Class, 2 for Business, 3 for Economy, or 99 to Exit): ";
				cin >> section;
				if (section == 99)
					printReceipt(totalPrice);
				else if (section == 1 || section == 2 || section == 3)
					itemizeTicekts(section);
				else
				{
					while ((section != 1 && section != 2 && section != 3 && section != 99))
					{
						cout << "That was not a valid option! Please enter a valid option: ";
						cin.clear();
						cin.ignore();
						cin >> section;
					}//end while
					itemizeTicekts(section);
				}//end else
				
			}//end else
			break;
		}//end case1
		case 2:
		{
			cout << "You have selected 2 for Business Class. These tickets have a cost of $499.99. "
				<< "Are you sure this is your selection? \n(Enter Y/y for Yes or N/n for No): ";
			cin >> check;
			cout << endl;

			if (check == 'Y' || check == 'y')
				itemizeTicekts(section);
			else
			{
				section = 0;
				cout << "Please select a section you would actually like to browse, please. "
					<< "\n(Select 1 for First Class, 2 for Business, 3 for Economy, or 99 to Exit): ";
				cin >> section;
				if (section == 99)
					printReceipt(totalPrice);
				else if (section == 1 || section == 2 || section == 3)
					itemizeTicekts(section);
				else
				{
					while ((section != 1 && section != 2 && section != 3 && section != 99))
					{
						cout << "That was not a valid option! Please enter a valid option: ";
						cin.clear();
						cin.ignore();
						cin >> section;
					}//end while
					itemizeTicekts(section);
				}//end else
			}//end else
			break;
		}//end case2
		case 3:
		{
			cout << "You have selected 3 for Economy. These tickets have a cost of $99.99. "
				<< "Are you sure this is your selection? \n(Enter Y/y for Yes or N/n for No): ";
			cin >> check;
			cout << endl;

			if (check == 'Y' || check == 'y')
				itemizeTicekts(section);
			else
			{
				section = 0;
				cout << "Please select a section you would actually like to browse, please. "
					<< "\n(Select 1 for First Class, 2 for Business, 3 for Economy, or 99 to Exit): ";
				cin >> section;
				if (section == 99)
					printReceipt(totalPrice);
				else if (section == 1 || section == 2 || section == 3)
					itemizeTicekts(section);
				else
				{
					while ((section != 1 && section != 2 && section != 3 && section != 99))
					{
						cout << "That was not a valid option! Please enter a valid option: ";
						cin.clear();
						cin.ignore();
						cin >> section;
					}//end while
					itemizeTicekts(section);
				}//end else
			}//end else
			break;
		}//end case3
		case 99:
		{
			printReceipt(totalPrice);
			break;
		}//end case99
		default:
		{
			cout << "Please select a valid option, please. ";
			break;
		}//end default
	}//end switch
}//end function


//this function asks the user how many tickets they want in a certain section, it lets the user choose what seat they want,
//and, if they want, they can keep choosing tickets after they are done with a certain section.
void itemizeTicekts(int section)
{
	int num = 0;
	char checkIfDone = ' ';
	//small switch, where a small output is changed based on what section the user has selected.
	switch (section)
	{
		case 1: 
		{
			cout << "Please enter how many tickets you would like to buy in this section (Max - 10): ";
			cin >> num;
			while (!cin || num < 0 || num > 10)
			{
				cout << "That was no valid number! Please enter a valid number: ";
				cin.clear();
				cin.ignore();
				cin >> num;
			}//end while
			break;
		}//end case1
		case 2:
		{
			cout << "Please enter how many tickets you would like to buy in this section (Max - 6): ";
			cin >> num;
			while (!cin || num < 0 || num > 6)
			{
				cout << "That was no valid number! Please enter a valid number: ";
				cin.clear();
				cin.ignore();
				cin >> num;
			}//end while
			break;
		}//end case2
		case 3:
		{
			cout << "Please enter how many tickets you would like to buy in this section (Max - 12): ";
			cin >> num;
			while (!cin || num < 0 || num > 12)
			{
				cout << "That was no valid number! Please enter a valid number: ";
				cin.clear();
				cin.ignore();
				cin >> num;
			}//end while
			break;
		}//end case3
	}//end switch
	cout << endl;

	//do...while encasing a switch, which runs a large portion of code that asks the user how many seats they want, as well
	//as a for loop that has the user input which seats they want. The switch modifies the portion of code for each section.
	do
	{
		switch (section)
		{
			case 1:
			{
				for (int i = 0; i < num; i++)
				{
					int row = 0;
					int col = 0;
					displayLayout(section);
					cout << "Please select which seat you would like to reserve: "
						<< "(Enter Row #, then a space, then the Column #): ";
					cin >> row >> col;

					while (!cin || row < 0 || col < 0)
					{
						cout << "That was no valid seat! Please enter a valid seat: ";
						cin.clear();
						cin.ignore();
						cin >> row >> col;
					}//end while

					//these ifs make sure that the row and column are correct. If the input is correct, then it makes the
					//item at that position in the right 2D array an 'X', in addition to adding the price of each ticket to 
					//the proper variables.
					if ((row <= 3 && row >= 0) && (col <= 4 && col >= 0))
					{
						if (firstClass[row - 1][col - 1] == 'X')
						{
							cout << "I'm sorry, that seats has already been purchased. Please try again. " 
								<< endl;
							i--;
						}//end if
						else if (row == 2 && (col == 2 || col == 3))
						{
							cout << "I'm sorry, that spot is part of the table. Please pick another seat: " << endl;
							i--;
						}//end elseif
						else
						{
							firstClass[row - 1][col - 1] = 'X';
							totalPrice += 1299.99;
							firstClassPrice += 1299.99;
							firstClassTickets++;
						}//end else
					}//end if
					else
					{
						cout << "I'm sorry, that is an invalid seat section. Please try again." << endl;
						i--;
					}//end else
				}//end for loop
				break;
			}//end case1
			case 2:
			{
				for (int i = 0; i < num; i++)
				{
					int row = 0;
					int col = 0;
					displayLayout(section);
					cout << "Please select which seat you would like to reserve: "
						<< "(Enter Row #, then a space, then the Column #): ";
					cin >> row >> col;

					while (!cin || row < 0 || col < 0)
					{
						cout << "That was no valid seat! Please enter a valid seat: ";
						cin.clear();
						cin.ignore();
						cin >> row >> col;
					}//end while

					if ((row <= 5 && row >= 4) && (col <= 4 && col >= 0))
					{
						if ((row == 4 || row == 5) && col == 3)
						{
							businessClass[row - 4][3] = 'X';
						}//end if
						else
						{
							if (businessClass[row - 1][col - 1] == 'X')
							{
								cout << "I'm sorry, that seats has already been purchased. Please try again. "
									<< endl;
								i--;
							}//end if
							else
								businessClass[row - 4][col - 1] = 'X';
						}//end else
						totalPrice += 499.99;
						businessPrice += 499.99;
						businessTickets++;
					}//end if
					else
					{
						cout << "I'm sorry, that is an invalid seat section. Please try again." << endl;
						i--;
					}//end else
				}//end for loop
				break;
			}//end case2
			case 3:
			{
				for (int i = 0; i < num; i++)
				{
					int row = 0;
					int col = 0;
					displayLayout(section);
					cout << "Please select which seat you would like to reserve: "
						<< "(Enter Row #, then a space, then the Column #): ";
					cin >> row >> col;

					while (!cin || row < 0 || col < 0)
					{
						cout << "That was no valid seat! Please enter a valid seat: ";
						cin.clear();
						cin.ignore();
						cin >> row >> col;
					}//end while

					if ((row <= 8 && row >= 6) && (col <= 4 && col >= 0))
					{
						if (economy[row - 1][col - 1] == 'X')
						{
							cout << "I'm sorry, that seats has already been purchased. Please try again. "
								<< endl;
							i--;
						}//end if
						else
						{
							economy[row - 6][col - 1] = 'X';
							totalPrice += 99.99;
							economyPrice += 99.99;
							economyTickets++;
						}//end else
					}
					else
					{
						cout << "I'm sorry, that is an invalid seat section. Please try again." << endl;
						i--;
					}//end else
				}//end for loop
				break;
			}//end case3
			default:
			{
				break;
			}//end default
		}//end switch

		//this input decides whether or not this code loops again or not. 
		cout << endl << "Layout so far: " << endl;
		displayLayout();
		cout << "Would you like to checkout, or continue selecting seats? "
			<< "(Enter Y/y to Checkout, or N/n to continue selecting): ";
		cin >> checkIfDone;
		cout << endl;
		
		if (checkIfDone == 'N' || checkIfDone == 'n')
		{
			chooseSeats();
			checkIfDone = ' ';
		}//end if
		else
		{
			printReceipt(totalPrice);
			checkIfDone = ' ';
		}//end else
	} while (checkIfDone == 'N' || checkIfDone == 'n');
}

void printReceipt(int totalPrice)
{
	char finalCheck = ' ';
	int sectionNum = 0;

	//this input prints out the semi-final receipt, with the decimals lined up. The input after the receipt asks the user if
	//they would like to change their mind about any of their selections. If they do wish to change their mind, the code
	//takes them through the process to change their selections. If they don't want to change their mind, then the program ends.
	cout << "You have chosen to checkout. This is your itemized receipt: " << endl;
	displayLayout();
	cout << endl;
	cout << fixed << showpoint << setprecision(2)
		<< "First Class Tickets:    x" << firstClassTickets << " ......... $" << setw(10) << right << firstClassPrice << endl
		<< "Business Class Tickets: x" << businessTickets << " ......... $" << setw(10) << right << businessPrice << endl
		<< "Economy Class Tickets:  x" << economyTickets << " ......... $" << setw(10) << right << economyPrice << endl;
		
	cout << "Before you leave, do you wish to change any of your selections? "
		<< "(Enter Y/y for Yes or N/n for No): ";
	cin >> finalCheck;
	while (finalCheck != 'Y' && finalCheck != 'y' && finalCheck != 'n' && finalCheck != 'N')
	{
		cout << "That's not a valid option! Please select again: " << endl;
		cin.clear();
		cin.ignore();
		cin >> finalCheck;
	}//end while

	if (finalCheck == 'Y' || finalCheck == 'y')
	{
		cout << "Which section would you like to change? "
			<< "\n(Select 1 for First Class, 2 for Business, 3 for Economy, or 99 to Exit): ";
		cin >> sectionNum;
		while ((sectionNum != 1 && sectionNum != 2 && sectionNum != 3 && sectionNum != 99))
		{
			cout << "That was not a valid option! Please enter a valid option: ";
			cin.clear();
			cin.ignore();
			cin >> sectionNum;
		}//end while

		selectionChange(sectionNum);
	}//end if
	else
	{ 
		cout << "Thank you. Have a nice day!";
	}//end else
}

void selectionChange(int section)
{
	char check1 = ' ';
	char check2 = ' ';
	int row = 0;
	int col = 0;
	int counterNum = 0;
	bool selectionChange = false;

	do
	{
		switch (section)
		{
			case 1:
			{
				cout << "Please enter how many seats you would like to change (Max - 10): ";
				cin >> counterNum;

				while (!cin || counterNum < 0)
				{
					cout << "That was not a valid number! Please enter a valid number: ";
					cin.clear();
					cin.ignore();
					cin >> counterNum;
				}

				for (int i = 0; i < counterNum; i++)
				{
					displayLayout(section);
					cout << "Please select which seat you would like to change: "
						<< "(Enter Row #, then a space, then the Column #): ";
					cin >> row >> col;

					while (!cin || row < 0 || col < 0)
					{
						cout << "That was no valid seat! Please enter a valid seat: ";
						cin.clear();
						cin.ignore();
						cin >> row >> col;
					}//end while

					if ((row <= 3 && row >= 0) && (col <= 4 && col >= 0))
					{
						if (firstClass[row - 1][col - 1] == 'X')
						{
							firstClass[row - 1][col - 1] = '*';
							totalPrice -= 1299.99;
							firstClassPrice -= 1299.99;
							firstClassTickets--;
						}
						else
						{
							firstClass[row - 1][col - 1] = 'X';
							totalPrice += 1299.99;
							firstClassPrice += 1299.99;
							firstClassTickets++;
						}
					}//end if
					else
					{
						cout << "I'm sorry, that is an invalid seat section. Please try again." << endl;
						i--;
					}//end else
				}//end for loop
				break;
			}//end case1
			case 2:
			{
				cout << "Please enter how many seats you would like to change (Max - 6): ";
				cin >> counterNum;

				while (!cin || counterNum < 0)
				{
					cout << "That was not a valid number! Please enter a valid number: ";
					cin.clear();
					cin.ignore();
					cin >> counterNum;
				}

				for (int i = 0; i < counterNum; i++)
				{
					int row = 0;
					int col = 0;
					displayLayout(section);
					cout << "Please select which seat you would like to reserve: "
						<< "(Enter Row #, then a space, then the Column #): ";
					cin >> row >> col;

					while (!cin || row < 0 || col < 0)
					{
						cout << "That was no valid seat! Please enter a valid seat: ";
						cin.clear();
						cin.ignore();
						cin >> row >> col;
					}//end while

					if ((row <= 5 && row >= 4) && (col <= 4 && col >= 0))
					{
						if (businessClass[row - 4][col - 1] == 'X')
						{
							if ((row == 4 || row == 5) && col == 3)
							{
								businessClass[row - 4][3] = '*';
							}//end if
							else
							{
								businessClass[row - 4][col - 1] = '*';
							}//end else
							totalPrice -= 499.99;
							businessPrice -= 499.99;
							businessTickets--;
						}
						else
						{
							if ((row == 4 || row == 5) && col == 3)
							{
								businessClass[row - 4][3] = 'X';
							}//end if
							else
							{
								businessClass[row - 4][col - 1] = 'X';
							}//end else
							totalPrice += 499.99;
							businessPrice += 499.99;
							businessTickets++;
						}
					}//end if
					else
					{
						cout << "I'm sorry, that is an invalid seat section. Please try again." << endl;
						i--;
					}//end else
				}//end for
				break;
			}//end case2
			case 3:
			{
				cout << "Please enter how many seats you would like to change (Max - 12): ";
				cin >> counterNum;

				while (!cin || counterNum < 0)
				{
					cout << "That was not a valid number! Please enter a valid number: ";
					cin.clear();
					cin.ignore();
					cin >> counterNum;
				}

				for (int i = 0; i < counterNum; i++)
				{
					int row = 0;
					int col = 0;
					displayLayout(section);
					cout << "Please select which seat you would like to reserve: "
						<< "(Enter Row #, then a space, then the Column #): ";
					cin >> row >> col;

					while (!cin || row < 0 || col < 0)
					{
						cout << "That was no valid seat! Please enter a valid seat: ";
						cin.clear();
						cin.ignore();
						cin >> row >> col;
					}//end while

					if ((row <= 8 && row >= 6) && (col <= 4 && col >= 0))
					{
						if (economy[row - 6][col - 1] == 'X')
						{
							economy[row - 6][col - 1] = '*';
							totalPrice -= 99.99;
							economyPrice -= 99.99;
							economyTickets--;
						}
						else
						{
							economy[row - 6][col - 1] = 'X';
							totalPrice += 99.99;
							economyPrice += 99.99;
							economyTickets++;
						}
					}//end if
					else
					{
						cout << "I'm sorry, that is an invalid seat section. Please try again." << endl;
						i--;
					}//end else
				}//end for loop
				break;
			}//end case3
			default:
			{
				break;
			}//end default
		}//end switch

		 //this asks if the user would like to change anything else. If they would like to, then the code loops again. If not, 
		 //the program prints out the final receipt.
		cout << "Do you want to change anything else? "
			<< "(Enter Y/y for Yes or N/n for No): ";
		cin >> check2;
		if (check2 == 'N' || check2 == 'n')
		{
			selectionChange = true;
			displayLayout();
			cout << "Receipt after changes: " << endl;
			cout << fixed << showpoint << setprecision(2)
				<< "First Class Tickets:    x" << firstClassTickets << " ......... $" << setw(10) << right << firstClassPrice << endl
				<< "Business Class Tickets: x" << businessTickets << " ......... $" << setw(10) << right << businessPrice << endl
				<< "Economy Class Tickets:  x" << economyTickets << " ......... $" << setw(10) << right << economyPrice << endl;
		}//end if
		else if(check2 == 'Y' || check2 == 'y')
		{
			cout << "Which section would you like to change? "
				<< "\n(Select 1 for First Class, 2 for Business, 3 for Economy, or 99 to Exit): ";
			cin >> section;
			while ((section != 1 && section != 2 && section != 3 && section != 99))
			{
				cout << "That was not a valid option! Please enter a valid option: ";
				cin.clear();
				cin.ignore();
				cin >> section;
			}//end while
		}
		else
		{
			while (check2 != 'Y' && check2 != 'y' && check2 != 'N' && check2 != 'n')
			{
				cout << "That was not a valid option! Please enter a valid option: ";
				cin.clear();
				cin.ignore();
				cin >> check2;
			}//end while
		}
	} while (selectionChange == false);

}