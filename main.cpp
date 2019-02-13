#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

//function prototypes
void getData(ifstream& inp, vector<int>& iID, vector<string>& iName,
	vector<int>& pOrdered, vector<int>& pInStore,
	vector<int>& pSold, vector<double>& manufPrice,
	vector<double>& sPrice, vector<int>& backOrders);

void sortData(vector<int>& iID, vector<string>& iName,
	vector<int>& pOrdered, vector<int>& pInStore,
	vector<double>& manufPrice,
	vector<double>& sPrice);

int binSearch(vector<string> list, string searchItem);

void menu();

void printReport(const vector<int>& iID,
	const vector<string>& iName,
	const vector<int>& pOrdered,
	const vector<int>& pInStore,
	const vector<int>& pSold,
	const vector<double>& manufPrice,
	const vector<double>& sPrice,
	vector<int>& backOrders);

void makeSale(const vector<string>& iName, vector<int>& pInStore,
	vector<int>& pSold, const vector<double>& sPrice, vector<int>& backOrders);
void makeReverseSale(const vector<string>& iName, vector<int>& pInStore,
	vector<int>& pSold, const vector<double>& sPrice);

int main()
{
	//local vector lists
	vector<int> itemID;
	vector<string> itemName;
	vector<int> piecesOrdered;
	vector<int> piecesInStore;
	vector<int> piecesSold;
	vector<double> manufPrice;
	vector<double> sellingPrice;
	vector<int> backOrders;

	//local variables
	string name;
	int index;

	int choice;
	char ch;
	bool ifReturnable = false;
	int hold;

	ifstream infile;

	//open the input file
	infile.open("../BIN/HardwareInput.txt");

	if (!infile)
	{
		cout << "Input file does not exist." << endl;
		return 1;
	}

	//fetches data from input file and stores data in parameter variables
	getData(infile, itemID, itemName, piecesOrdered,
		piecesInStore, piecesSold, manufPrice,
		sellingPrice, backOrders);

	//sorts input file data alphabetically
	sortData(itemID, itemName, piecesOrdered,
		piecesInStore, manufPrice, sellingPrice);

	cout << fixed << showpoint << setprecision(2);

	//displays the menu
	menu();

	cin >> choice;
	cin.get(ch);
	cout << endl;

	while (choice != 9)
	{
		//switch runs through menu choices
		switch (choice)
		{
			//case 1 checks if entered item name is in stock
			case 1:
				cout << "Enter the name of the item: ";
				getline(cin, name);

				index = binSearch(itemName, name);
				if (index >= 0)
					if (piecesInStore[index] > 0)
						cout << name << " is in store." << endl << endl;
					else
						cout << name << " is currently out of stock."
						<< endl << endl;
				else
					cout << "Store does not carry " << name
					<< "." << endl << endl;
				break;
			//case 2 prompts user to buy an item from stock
			case 2:
				makeSale(itemName, piecesInStore,
					piecesSold, sellingPrice, backOrders);
				break;
			//case 3 checks the price of desired item
			case 3:
				cout << "Enter the name of the item: ";
				getline(cin, name);

				index = binSearch(itemName, name);
				if (index >= 0)
					cout << "The price of " << name << " = "
					<< sellingPrice[index] << "." << endl;
				else
					cout << "Store does not carry " << name
					<< "." << endl << endl;
				break;
			//case 4 prints out report of all items in store
			case 4:
				printReport(itemID, itemName, piecesOrdered,
					piecesInStore, piecesSold, manufPrice,
					sellingPrice, backOrders);
				break;
			//case 5 prompts user to return a bought item. Only runs if
			//user has bought an item
			case 5:
				for (int i = 0; i < piecesSold.size(); i++)
					if (piecesSold[i] != 0)
						ifReturnable = true;

				if (ifReturnable == true)
					makeReverseSale(itemName, piecesInStore,
						piecesSold, sellingPrice);
				else
					cout << "You have not bought anything yet. Go buy something, then try to return." << endl;
				break;
			//default choice for switch
			default:
				cout << "Invalid choice." << endl << endl;
		}

		//displays menu again
		menu();

		cin >> choice;
		cin.get(ch);
		cout << endl;
	}

	cin >> hold;
	return 0;
}

//uses input file to store data in parameter variables.
void getData(ifstream& inp, vector<int>& iID, vector<string>& iName,
	vector<int>& pOrdered, vector<int>& pInStore,
	vector<int>& pSold, vector<double>& manufPrice,
	vector<double>& sPrice, vector<int>& backOrders)
{
	int id;
	string name;
	int itemsOrdered;
	double mPrice;
	double sellPrice;

	char ch;

	inp >> id;
	inp.get(ch);
	getline(inp, name);
	inp >> itemsOrdered >> mPrice >> sellPrice;

	//while there is still data to be read in file, 
	//program adds extra data to respective vectors
	while (inp)
	{
		iID.push_back(id);
		iName.push_back(name);
		pOrdered.push_back(itemsOrdered);
		pInStore.push_back(itemsOrdered);
		pSold.push_back(0);
		manufPrice.push_back(mPrice);
		sPrice.push_back(sellPrice);
		backOrders.push_back(0);
		inp >> id;
		inp.get(ch);
		getline(inp, name);
		inp >> itemsOrdered >> mPrice >> sellPrice;
	}
}

//function to sort data alphabetically
void sortData(vector<int>& iID, vector<string>& iName,
	vector<int>& pOrdered, vector<int>& pInStore,
	vector<double>& manufPrice,
	vector<double>& sPrice)
{
	int smallestIndex;
	string temp;

	int temp1;
	double temp2;

	int length = static_cast<int>(iName.size());

	for (int index = 0; index < length - 1; index++)
	{

		smallestIndex = index;

		for (int minIndex = index + 1; minIndex < length; minIndex++)
			if (iName[minIndex] < iName[smallestIndex])
				smallestIndex = minIndex;

		temp1 = iID[smallestIndex];
		iID[smallestIndex] = iID[index];
		iID[index] = temp1;

		iName[smallestIndex].swap(iName[index]);

		temp1 = pOrdered[smallestIndex];
		pOrdered[smallestIndex] = pOrdered[index];
		pOrdered[index] = temp1;

		temp1 = pInStore[smallestIndex];
		pInStore[smallestIndex] = pInStore[index];
		pInStore[index] = temp1;

		temp2 = manufPrice[smallestIndex];
		manufPrice[smallestIndex] = manufPrice[index];
		manufPrice[index] = temp2;

		temp2 = sPrice[smallestIndex];
		sPrice[smallestIndex] = sPrice[index];
		sPrice[index] = temp2;
	}
}

//searches a certain vector for a desired item. Returns 1 if 
//item is found, -1 else
int binSearch(vector<string> list, string searchItem)
{
	int first = 0;
	int last = static_cast<int>(list.size()) - 1;
	int mid;

	bool found = false;

	while (first <= last && !found)
	{
		mid = (first + last) / 2;

		if (list[mid] == searchItem)
			found = true;
		else if (list[mid] > searchItem)
			last = mid - 1;
		else
			first = mid + 1;
	}

	if (found)
		return mid;
	else
		return -1;
}//end binarySearch

//displays options for user to choose from
void menu()
{
	cout << "Welcome to the Bubba\'s Hardware Store!" << endl;
	cout << "Choose among the following options." << endl;
	cout << "1: To see if an item is in the store." << endl;
	cout << "2: To buy an item." << endl;
	cout << "3. To check the price of an item." << endl;
	cout << "4: To print the inventory." << endl;
	cout << "5: To return an item." << endl;
	cout << "9: To end the program." << endl;
}

//prints all the data for each item
void printReport(const vector<int>& iID,
	const vector<string>& iName,
	const vector<int>& pOrdered,
	const vector<int>& pInStore,
	const vector<int>& pSold,
	const vector<double>& manufPrice,
	const vector<double>& sPrice,
	vector<int>& backOrders)
{
	int noOfItems = static_cast<int>(iName.size());

	double totalInventory = 0;
	int totalNumberOfPieces = 0;
	double profit = 0;

	//displays titles for each column
	cout << endl;
	cout << "                      Bubba\'s Hardware Store"
		<< endl << endl;
	cout << left << setw(7) << "itemID " << setw(14) << "itemName "
		<< setw(9) << " pOrdered" << setw(9) << " pInStore"
		<< setw(6) << " pSold" << setw(11) << " manufPrice"
		<< setw(13) << " sellingPrice" << " BackOrders " << "    markUp%" << endl;

	//prints out all data in a single row, for loop prints every row.
	for (int i = 0; i < noOfItems; i++)
	{
		cout << left << setw(7) << iID[i] << setw(14) << iName[i]
			<< right << setw(9) << pOrdered[i] << setw(9) << pInStore[i]
			<< setw(6) << pSold[i] << setw(11) << manufPrice[i]
			<< setw(12) << sPrice[i] << setw(10) << backOrders[i]
			<< setw(13) << (sPrice[i] / manufPrice[i]) * 100 << "%" << endl;

		totalInventory += pInStore[i] * sPrice[i];
		totalNumberOfPieces += pInStore[i];
		profit += (pSold[i] * (sPrice[i] - manufPrice[i]));
	}

	//totals of some data printed above.
	cout << endl;
	cout << "Total Inventory: $" << totalInventory << endl;
	cout << "Total number of items in the store: "
		<< totalNumberOfPieces << endl;
	cout << "Profit on Sales: $" << profit << "\n\n\n";
}

//function that asks user for what item they want to buy, and how many of that item they want.
void makeSale(const vector<string>& iName, vector<int>& pInStore,
	vector<int>& pSold, const vector<double>& sPrice, vector<int>& backOrders)
{
	int noOfPiecesToBeSold;
	string name;

	cout << "Enter the name of the item: ";
	getline(cin, name);

	//function that checks if inputted item is in stock.
	int index = binSearch(iName, name);

	char response;

	//if item is in stock
	if (index >= 0)
	{
		//if there are no more items in stock, asks user if they want to back order
		//this item.
		if (pInStore[index] == 0)
		{
			cout << "How many items would you like to back order? ";
			cin >> backOrders[index];
			cout << endl;
		}
		//if the item is in stock
		else
		{
			//user inputs how many they want.
			cout << "Enter the number of pieces: ";
			cin >> noOfPiecesToBeSold;
			cout << endl;
			//if the user inputs a value that is less than what is in stock,
			//subtract from stock, add to sold, then print out amount due.
			if (pInStore[index] >= noOfPiecesToBeSold)
			{
				pInStore[index] -= noOfPiecesToBeSold;
				pSold[index] += noOfPiecesToBeSold;
				cout << "Amount Due = $"
					<< noOfPiecesToBeSold * sPrice[index] << endl;
			}
			//else if the user inputs a value that is more than what is
			//in stock, ask the user if they would like to buy the item out
			//then back order the rest of what you bought.
			else if (pInStore[index] < noOfPiecesToBeSold)
			{
				cout << "Currently the store has only "
					<< pInStore[index] << " " << name << endl;
				cout << "Would you like to buy only these many, and back order the rest? (y,Y/n,N)."
					<< endl;
				cin >> response;
				cout << endl;

				if (response == 'Y' || response == 'y')
				{
					pSold[index] += pInStore[index];
					backOrders[index] += (noOfPiecesToBeSold - pInStore[index]);
					cout << "Amount Due = $"
						<< (pInStore[index] * sPrice[index]) + (backOrders[index] * sPrice[index])
						<< endl;
					pInStore[index] = 0;
				}
				else
					cout << "Please check with the manager for assistence." << endl;
			}
		}
	}
	else
		cout << "The store does not carry " << name << "." << endl;
}

//makeReverseSale is the return function, if the user
//would like to return any of the items they have bought. 
void makeReverseSale(const vector<string>& iName, vector<int>& pInStore,
	vector<int>& pSold, const vector<double>& sPrice)
{
	int noOfPiecesToNotBeSold;
	string name;

	cout << "Enter the name of the item to be RETURNED: ";
	getline(cin, name);

	int index = binSearch(iName, name);
	//if the user tries to return an item they have not bought, 
	//loops until they enter an item that they have bought.
	while (pSold[index] == 0)
	{
		cout << "Dude. Only try to return something you actually have. ";
		getline(cin, name);
		int index = binSearch(iName, name);
	}

	char response;

	//if the item is in stock
	if (index >= 0)
	{
		cout << "Enter the number of pieces to be RETURNED: ";
		cin >> noOfPiecesToNotBeSold;
		cout << endl;

		//if the user inputs a value that is less than what they have,
		//subtract from stock, add to sold, then print out amount due.
		if (pSold[index] >= noOfPiecesToNotBeSold)
		{
			pInStore[index] += noOfPiecesToNotBeSold;
			pSold[index] -= noOfPiecesToNotBeSold;
			cout << "Amount Returned = $"
				<< noOfPiecesToNotBeSold * sPrice[index] << endl;
		}
		//else if the user inputs a value that is more than what the user has,
		//asks the user if they want to just return everything they have.
		else if (pSold[index] < noOfPiecesToNotBeSold)
		{
			cout << "You dumb butt. You can only return something you have. Would you like to "
				<< "return all of those items? (y,Y/n,N)." << endl;
			cin >> response;
			cout << endl;

			if (response == 'Y' || response == 'y')
			{
				pSold[index] -= pInStore[index];
				cout << "Amount Due = $"
					<< pInStore[index] * sPrice[index]
					<< endl;
				pInStore[index] = 0;
			}
			else
				cout << "Please check with the manager "
				<< "for assistence." << endl;
		}
	}
	else
		cout << "The store does not reverse carry " << name << "." << endl;
}