//This program demos data validation
#include <iostream>
using namespace std;

int main()
{
	int num1 = 0, num2 = 0;
	//read user input
	cout << "Enter an integer:";
	cin >> num1;
	//data validation
	while(!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input!! Please try again!!";
		cin >> num1;
	}
	cin.ignore(100, '\n');
	cout << "Enter another integer:";
	cin >> num2;
	//data validation
	while (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input!! Please try again!!";
		cin >> num2;
	}
	cin.ignore(100, '\n');
	cout << "You entered " << num1 << " and " << num2 << endl;
	return 0;
}

