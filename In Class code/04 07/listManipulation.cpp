//This program demonstartes list manipulation using a list of integers
//Menu driven program

#include <iostream>
using namespace std;

//global constants
const int CAP = 100;

//function prototypes
void displayMenu();
char readOption();
void exeCmd(char option, int list[], int &size);
void addNum(int list[], int &size);
void delNum(int list[], int &size);
void editList(int list[], const int size);
void sortList(int list[], const int size);
void printList(int list[], const int size);


int main()
{
	int list[CAP] = { 0 }, size = 0;
	char option;
	do
	{
		displayMenu();
		option = readOption();
		exeCmd(option, list, size);
	} while (tolower(option) != 'q');
	
	return 0;
}

//displays the menu
void displayMenu()
{
		cout << "Welcome to the task menu" << endl << endl;
		cout << "Pick an option" << endl;
		cout << "[A-a]: Add" << endl;
		cout << "[D-d]: Delete" << endl;
		cout << "[E-e]: Edit" << endl;
		cout << "[S-s]: Sort" << endl;
		cout << "[L-l]: List" << endl;
		cout << "[Q-q]: Quit" << endl;
}

char readOption()
{
	char input;

	cin >> input;
	return input;
}

void exeCmd(char option, int list[], int &size)
{
	switch (tolower(option))
	{
	case 'a': 
		addNum(list, size);
		break;
	case 'd':
		delNum(list, size);
		break;
	case 'e':
		editList(list, size);
		break;
	case 's':
		sortList(list, size);
		break;
	case 'l':
		printList(list, size);
		break;
	case 'q':
		break;
	default:
		cout << "invalid input, please try again!!" << endl;
	}
}

//add a number to the list
void addNum(int list[], int &size)
{
	cout << "Enter a whole number: ";
	cin >> list[size++];
}

//sorts the list
void sortList(int list[], const int size)
{
	int minIndex = 0, temp = 0;
	for (int i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (list[minIndex] > list[j])
				minIndex = j;
		}
		//swap the numbers
		temp = list[minIndex];
		list[minIndex] = list[i];
		list[i] = temp;
	}
}

//prints the list
void printList(int list[], const int size)
{
	cout << "List" << endl << "---" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "List Item " << i << ": " << list[i] << endl;
	}
	cout << "---" << endl;
}

//delete a number
void delNum(int list[], int &size)
{
	int selection = 0;
	printList(list, size);
	cout << "Which List Item Do You Want to Delete Professor Falcon?: ";
	cin >> selection;
	for (int i = selection; i < size; i++)
	{
		list[i] = list[i + 1];
	}
	size--;
	printList(list, size);
	
}

//This lets the user edit the list
void editList(int list[], const int size)
{
	int selection = 0;
	printList(list, size);
	cout << "Which List Item Do You Want to Change Professor Falcon?: ";
	cin >> selection;
	cout << endl;
	cout << "Enter the new value: ";
	cin >> list[selection];
	printList(list, size);
}
