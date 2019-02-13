/*
Name: Alex Fitzmaurice and Jonathan Warfield
Date: 10.29.2018
Description:
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

//global variables
const int NUMBEROFITEMS = 5;
int numOfCandy[NUMBEROFITEMS];
double finalTotal = 0.0;

//struct
struct candy
{
	string candyName;
	double price;
	int servingSize;
	double sugarAmount;
	double bill = 0.0;
};

//prototypes
void showMenu();
void getData(ifstream& inf, candy list[], int length);
void printNutritionInfo(candy list[], int itemNum);
int itemizeSelection();
void receipt(candy list[]);
void checkInput(char response);

ifstream inFile;

int main()
{
	//variables
	candy listOfCandy[NUMBEROFITEMS];
	string name = " ";
	double cost = 0.0;
	int serving = 0;
	double sugar = 0.0;
	double total = 0.0;

	bool whileCheck = true;

	int menuChoice;
	int hold;

	//opens input file. if the file is corrupted, program forces a restart
	inFile.open("C:/Users/afitzmaurice625/Desktop/CandyShopInFile.txt");
	if (!inFile)
	{
		cout << "Input file does not exist. Program terminates!";
		return 1;
	}//end if
	getData(inFile, listOfCandy, NUMBEROFITEMS);

	//do...while that loops user interaction
	do
	{
		system("CLS");
		cout << "Welcome to Warfield's Candy Shop! Please browse our delicious menu: ";
		cout << endl << endl;

		//prints out candy menu, then asks the user to input their selection from the menu.
		showMenu();
		cout << endl << "Select an option from our menu: ";
		cin >> menuChoice;
		//makes sure user has inputted correct data type
		while (!cin || (menuChoice != 1 && menuChoice != 2 && menuChoice != 3 && menuChoice != 4 && menuChoice != 5))
		{
			cout << "That is an invalid option! Please enter a valid option: ";
			cin.clear();
			cin.ignore();
			cin >> menuChoice;
		}//end while
		cout << endl;

		//switch that is based on what candy user has selected.
		char response;
		switch (menuChoice)
		{
			//case for Twix
			case 1:
			{
				printNutritionInfo(listOfCandy, menuChoice);
				cout << endl << "Are you sure you would like to select Twix as your candy of choice? "
					<< "(Enter Y/y for Yes or N/n for No): ";
				cin >> response;
				//function call to make sure user selects correct input
				checkInput(response);
				cout << endl;
				
				if (response == 'Y' || response == 'y')
				{
					//if the user would like to buy this item, program calls function to see how much candy they would like,
					//then increments all of the respective records in the candy struct. Finally, prints out the total amount
					//they have gotten from that specific item.
					int numOfItems = itemizeSelection();
					numOfCandy[0] += numOfItems;
					listOfCandy[menuChoice - 1].bill += (listOfCandy[menuChoice - 1].price * numOfItems);
					cout << "Item Total: $" << listOfCandy[menuChoice - 1].bill;
				}//end if
				break;
			}//end case1
			//case for Kit Kats. 
			case 2:
			{
				printNutritionInfo(listOfCandy, menuChoice);
				cout << endl << "Are you sure you would like to select Kit-Kats as your candy of choice? "
					<< "(Enter Y/y for Yes or N/n for No): ";
				cin >> response;
				checkInput(response);
				cout << endl;

				if (response == 'Y' || response == 'y')
				{
					//if the user would like to buy this item, program calls function to see how much candy they would like,
					//then increments all of the respective records in the candy struct. Finally, prints out the total amount
					//they have gotten from that specific item.
					int numOfItems = itemizeSelection();
					numOfCandy[1] += numOfItems;
					listOfCandy[menuChoice - 1].bill += (listOfCandy[menuChoice - 1].price * numOfItems);
					cout << "Item Total: $" << listOfCandy[menuChoice - 1].bill;
				}//end if
				break;
			}//end case 2
			case 3:
			{
				printNutritionInfo(listOfCandy, menuChoice);
				cout << endl << "Are you sure you would like to select Dum-Dums as your candy of choice? "
					<< "(Enter Y/y for Yes or N/n for No): ";
				cin >> response;
				checkInput(response);
				cout << endl;

				if (response == 'Y' || response == 'y')
				{
					//if the user would like to buy this item, program calls function to see how much candy they would like,
					//then increments all of the respective records in the candy struct. Finally, prints out the total amount
					//they have gotten from that specific item.
					int numOfItems = itemizeSelection();
					numOfCandy[2] += numOfItems;
					listOfCandy[menuChoice - 1].bill += (listOfCandy[menuChoice - 1].price * numOfItems);
					cout << "Item Total: $" << listOfCandy[menuChoice - 1].bill;
				}//end if
				break;
			}//end case 3
			case 4:
			{
				printNutritionInfo(listOfCandy, menuChoice);
				cout << endl << "Are you sure you would like to select Warhead Candy Spray as your candy of choice? "
					<< "(Enter Y/y for Yes or N/n for No): ";
				cin >> response;
				checkInput(response);
				cout << endl;

				if (response == 'Y' || response == 'y')
				{
					//if the user would like to buy this item, program calls function to see how much candy they would like,
					//then increments all of the respective records in the candy struct. Finally, prints out the total amount
					//they have gotten from that specific item.
					int numOfItems = itemizeSelection();
					numOfCandy[3] += numOfItems;
					listOfCandy[menuChoice - 1].bill += (listOfCandy[menuChoice - 1].price * numOfItems);
					cout << "Item Total: $" << listOfCandy[menuChoice - 1].bill;
				}//end if
				break;
			}//end case 4
			case 5:
			{
				//if the user would like to buy this item, program calls function to see how much candy they would like,
				//then increments all of the respective records in the candy struct. Finally, prints out the total amount
				//they have gotten from that specific item.
				printNutritionInfo(listOfCandy, menuChoice);
				cout << endl << "Are you sure you would like to select Hershey's as your candy of choice? "
					<< "(Enter Y/y for Yes or N/n for No): ";
				cin >> response;
				checkInput(response);
				cout << endl;

				if (response == 'Y' || response == 'y')
				{
					int numOfItems = itemizeSelection();
					numOfCandy[4] += numOfItems;
					listOfCandy[menuChoice - 1].bill += (listOfCandy[menuChoice - 1].price * numOfItems);
					cout << "Item Total: $" << listOfCandy[menuChoice - 1].bill;
				}//end if
				break;
			}//end case 5
			//default case, runs if user inputs something that isn't one of the predefined cases above
			default:
			{
				cout << "Invalid selection. Please select again." << endl;
				break;
			}//end default
		}//end switch

		//another check for the user, loops code again if necessary
		char makeAnotherSelection;
		cout << endl << "Would you like to make another candy selection? "
			<< "(Enter Y/y to keep selecting, or N/n to checkout): ";
		cin >> makeAnotherSelection;
		checkInput(makeAnotherSelection);
		cout << endl;
		if (makeAnotherSelection == 'N' || makeAnotherSelection == 'n')
		{
			//flips one-way flag, then adds all total bills for each item to a total bill variable.
			//Then it runs receipt function, which prints out an itemized receipt
			whileCheck = false;
			for (int i = 0; i < NUMBEROFITEMS; i++)
				finalTotal += listOfCandy[i].bill;
			receipt(listOfCandy);
		}//end if
	} while (whileCheck != false);//end do...while
	cout << endl;

	cin >> hold;
	return 0;
}//end main

///functions

//prints out candy menu
void showMenu()
{
	cout << "1. Twix                       $1.50" << endl
		<< "2. Kit-Kat                    $2.50" << endl
		<< "3. Dum-Dum                    $0.05" << endl
		<< "4. Warheads Candy Spray       $1.99" << endl
		<< "5. Hershey\'s Chocolate Bar    $0.75" << endl;
}//end showMenu function

//fetches data from the input file, then stores it in struct-type array
void getData(ifstream& inf, candy list[], int length)
{
	for (int i = 0; i < length; i++)
	{
		inf >> list[i].candyName >> list[i].price
			>> list[i].servingSize >> list[i].sugarAmount;
	}//end for
}//end getData function

//prints out all records attached to certain candy
void printNutritionInfo(candy list[], int itemNum)
{
	if (0 < itemNum)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "Candy Name: " << list[itemNum - 1].candyName << endl
			<< "Price: $" << list[itemNum - 1].price << endl
			<< "Serving Size: " << list[itemNum - 1].servingSize << " bars" << endl
			<< "Sugar Content: " << list[itemNum - 1].sugarAmount << " grams" << endl;
	}//end if
	else
		cout << "Invalid item number" << endl << endl;
}//end printNutritionInfo function

//function that asks user how many items they would like, then returns that number
int itemizeSelection()
{
	int numOfItems;
	cout << "Please enter how much candy you would like to buy: ";
	cin >> numOfItems;
	while (!cin || numOfItems < 0)
	{
		cout << "Invalid number. Please try again.";
		cin.clear();
		cin.ignore();
		cin >> numOfItems;
	}//end while
	cout << endl;
	return numOfItems;
}//end itemizeSelection function

//prints out reciept, which is itemized and has the decimals lined up
void receipt(candy list[])
{
	cout << "You have chosen to checkout. Here is your itemized receipt: " << endl << endl;
	cout << "*********************************************************************" << endl << endl;
	for (int i = 0; i < NUMBEROFITEMS; i++)
	{
		//if the user didn't buy a certain item, reciept does not include it
		if (numOfCandy[i] <= 0)
		{

		}//end if
		else
			cout << left << setw(20) << list[i].candyName << ": x" << setw(10) << numOfCandy[i] << setw(3) << "$" << right << setw(10) << list[i].bill << endl;
	}//end for

	cout << endl << left << setw(33) << "Subtotal: "  << "$" << right << setw(6) << finalTotal << endl;
	double tax = finalTotal * 0.4995;
	double totalAfterTax = finalTotal + tax;
	cout << left << setw(33) << "Tax: " << "$" << right << setw(6) << tax << endl;
	cout << left << setw(33) << "Total After Tax: " << "$" << right << setw(6) << totalAfterTax << endl;
	cout << "*********************************************************************" << endl;
}//end receipt function

//this function checks a user input and makes sure it is a correct input.
void checkInput(char response)
{
	while (!cin || (response != 'Y' && response != 'y' && response != 'N' && response != 'n'))
	{
		cout << "That is an invalid option! Please enter a valid option: ";
		cin.clear();
		cin.ignore();
		cin >> response;
	}//end while
}//end checkInput function

