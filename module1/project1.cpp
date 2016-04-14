/* 

Name: Patrick Roanhouse
PCC CS 162

Project 1


*/

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

using namespace std;

char menu(double total);


int main()
{
	
	double price = 0;
	double total = 0;
	string item = "";
	char menuOption = 'M';
	bool quit = 0;
	
	cout << "Welcome to\n";
	
	while(quit != 1)
	{
		
		switch (menuOption)
		{
			case 'A':
				cout << "Enter item name: ";
				getline(cin.ignore(100, '\n'), item);
				
				cout << "Enter Price: ";
				cin >> price;
			
				total = total + price;
				
				cout << endl << left << setw(40) << "-------------------------------------------------------";
				cout.setf(ios::fixed, ios::floatfield);cout.setf(ios::showpoint);  cout.precision(2);
				cout << endl << item << " $" << price << endl;
				cout << endl << right << setw(50) << fixed << setprecision(2) << "Running Total $"<< total << endl;
				cout << endl << left << setw(40) << "-------------------------------------------------------";
				cout << endl;
				// system( "read -n 1 -s -p \"Press any key to continue...\"" );
				cout << endl;
				menuOption = menu(total);
				break;
			case 'T':
				cout.setf(ios::fixed, ios::floatfield);cout.setf(ios::showpoint);  cout.precision(2);
				cout << endl << right << setw(50) << fixed << setprecision(2) << "Running Total $"<< total << endl;
				cout << endl << left << setw(40) << "-------------------------------------------------------";
				// system( "read -n 1 -s -p \"Press any key to continue...\"" );
				cout << endl;
				menuOption = menu(total);
				break;
			case 'Q':
				cout.setf(ios::fixed, ios::floatfield);cout.setf(ios::showpoint);  cout.precision(2);
				cout << endl << right << setw(50) << fixed << setprecision(2) << "Running Total $"<< total << endl;
				cout << endl << left << setw(40) << "-------------------------------------------------------";
				cout << endl;
				quit = 1;
				break;
			case 'M':
				menuOption = menu(total);
				break;
			default:
				cout << endl << left << setw(50) << "--- Invalid option ----";
				cout << endl << left << setw(40) << "-------------------------------------------------------";
				cout << endl;
				// system( "read -n 1 -s -p \"Press any key to continue...\"" );
				cout << endl;
				
				menuOption = menu(total);
				
			
			
			}
	
	
	}
		
	return 0;
	
}

char menu(double total)
{
	char menuOption = 'M';
	
	
	cout << endl << left << setw(40) << "Roanhouse Shopping Cart";
	cout << endl << left << setw(40) << "------------------------------------------------------";
	cout << endl;
	cout << endl << left << setw(40) << "(A) Add an item to the cart";
	cout << endl << left << setw(40) << "(T) Running total";
	cout << endl << left << setw(40) << "(Q) Quit";
	cout << endl;
	// cout << endl << right << setw(50) << fixed << setprecision(2) << "Running Total $"<< total;
	cout << endl << left << setw(40) << "-------------------------------------------------------";
	cout << endl;
	cout << "Enter a option: ";
	cin >> menuOption;
	
	menuOption = toupper(menuOption);
	
	cout << endl << left << setw(40) << "-------------------------------------------------------";
	cout << endl;
	
	return menuOption;
}