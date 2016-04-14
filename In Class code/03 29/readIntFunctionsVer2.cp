//This program demos data validation
#include <iostream>
using namespace std;

//global constant
const int MAXCHAR = 101;

//function prototypes
int readInt(char prompt[]);

int main()
{
	int num1 = 0, num2 = 0;
	char prompt[MAXCHAR];
	//read user input
	num1 = readInt("Enter number of adults:");
	strcpy_s(prompt, "Enter number of youth:");
	num2 = readInt(prompt);
	cout << "You entered " << num1 << " and " << num2 << endl;
	return 0;
}

//Name: readInt (reads and validates an integer)
//input: none
//output: error message
//return: int
int readInt(char prompt[])
{
	int temp = 0;
	cout << prompt;
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