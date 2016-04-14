//This program demos data validation
#include <iostream>
using namespace std;

//function prototypes
int readInt();

int main()
{
	int num1 = 0, num2 = 0;
	//read user input
	cout << "Enter an integer:";
	num1 = readInt();
	cout << "Enter another integer:";
	num2 = readInt();
	cout << "You entered " << num1 << " and " << num2 << endl;
	return 0;
}

//Name: readInt (reads and validates an integer)
//input: none
//output: error message
//return: int
int readInt()
{
	int temp = 0;
	
	cin >> temp;
	//data validation
	while (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Invalid input!! Please try again!!";
		cin >> temp;
	}
	cin.ignore(100, '\n');

	return temp;
}