#include <iostream>
#include <fstream>

using namespace std;

const int MAX_CHAR = 101;

int main()
{
	float   itemCost;
	float   totalCost;
	char    response;

	cout << endl << "Welcome to your Ez Shopping Cart!" << endl;

	char    itemName[MAX_CHAR];

	//get item from user
	cout << "Please enter the item name: ";
	cin.get(itemName, MAX_CHAR, '\n');
	while (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << "Invalid input! Please try again: ";
		cin >> itemName;
	}
	cin.ignore(100, '\n');

	//get itemCost of item from user
	cout << "Please enter the cost of the item: (e.g. 12.34) ";
	cin >> itemCost;
	while (!cin) {
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << "You've entered an illegal item cost. Please try again: " << endl;
		cin >> itemCost;
	}

	
	//allow user to enter more items
	do
	{
		//get item from user
		cout << "Please enter the item name: ";
		cin.get(itemName, MAX_CHAR, '\n');
		while (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl << "Invalid input! Please try again: ";
			cin >> itemName;
		}
		cin.ignore(100, '\n');

		//get itemCost of item from user
		cout << "Please enter the cost of the item: (e.g. 12.34) ";
		cin >> itemCost;
		while (!cin) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl << "You've entered an illegal item cost. Please try again: " << endl;
			cin >> itemCost;
		}
		//calculate total cost and display it
		totalCost += itemCost;

		//update loop control variable "response"
		cout << endl << "Want to add another item? (Y/N) ";
		cin >> response;
		cin.ignore(100, '\n');
		response = tolower(response);
	} while (response == 'y');
	
	//if user is done adding items to cart - calculate grand total:
	do
	{
		//calculate total cost and display it
		totalCost += itemCost;

		cout.setf(ios::fixed, ios::floatfield);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << endl << "Total Cost: " << totalCost << endl;

		//update loop control variable "response"
		cout << endl << "Ready to calculate grand total? (Y/N) ";
		cin >> response;
		cin.ignore(100, '\n');
		response = tolower(response);
	} while (response == 'y');

	cout << endl << "Thank you for using Ez Shopping Cart!" << endl;

	return 0;
}