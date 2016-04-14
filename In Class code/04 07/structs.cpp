//This program demos simple structs
#include <iostream>
using namespace std;

//global constants
const int MAXCHAR = 101;

//define our own struct
struct StudentType
{
	char lname[MAXCHAR];
	char fname[MAXCHAR];
	char id[MAXCHAR];
	double score[5];
	double gpa;
};

//main
int main()
{
	StudentType pccStd;
	//read values
	cout << "Enter student's first name:";
	cin.get(pccStd.fname, MAXCHAR);
	cin.ignore(100, '\n');
	cout << "Enter student's last name:";
	cin.get(pccStd.lname, MAXCHAR);
	cin.ignore(100, '\n');
	cout << "Enter student's id:";
	cin.get(pccStd.id, MAXCHAR);
	cin.ignore(100, '\n');
	cout << "Enter 5 scores:";
	for (int i = 0; i < 5; i++)
	{
		cin >> pccStd.score[i];
	}
	cout << "Enter student's gpa:";
	cin >> pccStd.gpa;
	cin.ignore(100, '\n');
	//output all the information to the user
	cout << "Your student's information:" << endl;
	cout << pccStd.fname << " " << pccStd.lname << endl;
	cout << pccStd.id << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << pccStd.score[i] << " ";
	}
	cout << endl;

	return 0;
}