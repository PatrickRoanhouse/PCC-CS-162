//This program demos how to swap 2 numbers using reference parameters
#include <iostream>
using namespace std;

//function prototypes
void swap(int &a, int &b);

int main()
{
	int a = 10, b = 15;
	cout << "In main, before swap, a = " << a << ", and b = " << b << endl;
	swap(a, b);
	cout << "In main, after swap, a = " << a << ", and b = " << b << endl;
	cout << "Address of a = " << &a << endl;
	cout << "Address of b = " << &b << endl;

	return 0;
}

//function to swap 2 numbers using reference parameters
void swap(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}