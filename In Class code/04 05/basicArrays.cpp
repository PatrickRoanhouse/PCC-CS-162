//This program demos basic arrays
#include <iostream>
using namespace std;

//global constants
const int CAP = 100;

int main()
{
	int list[CAP] = { -1 }, i = 0;
	list[6] = 7;
	//output the values
	for (i = 0; i < 7; i++)
	{
		list[i] = i + 4;
		cout << list[i] << " ";
	}
	cout << endl;
	//prints the address of the first and second elements
	cout << list << endl;
	cout << list+1 << endl;
	return 0;
}