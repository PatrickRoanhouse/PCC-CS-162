#include <iostream>

using namespace std;

void print (int numberOfRows, int numberOfCols, char text);

int main()
{
/*	int numberOfRows = 0;
	int numberOfCols = 0;

	cout << "Enter in numberOfRows: ";
	cin >> numberOfRows;
	cout << "Enter in numberOfCols: ";
	cin >> numberOfCols;
*/
	print(3, 4, '*'); 
}

void print (int numberOfRows, int numberOfCols, char text)
{
	int count = 0;
	for (int i = 0; i < numberOfRows; i++ )
	{
		for(int j = 0; j < numberOfCols; j++)
		{
			count++;
			if (count%3 == 0)
			{
				cout << "3";
			}
			else 
			{
				cout << text;
			}

		}
		cout << endl;
	}	
}
