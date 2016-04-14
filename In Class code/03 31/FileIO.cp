//This program demos how to read from a file and how to output the results to a file
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//global constants
const int MAXCHAR = 101;

int main()
{
	//variables
	char fname[MAXCHAR], lname[MAXCHAR];
	double basePay = 0, bonus = 0, totalPay = 0;
	ifstream inFile;
	ofstream outFile;
	//open the input file
	inFile.open("employees.txt");
	if (!inFile)
	{
		cout << "Input file not found! Program exiting!!" << endl;
		exit(0);
	}
	//open the output file
	outFile.open("employees.out");
	if (!outFile)
	{
		cout << "Output file not found! Program exiting!!" << endl;
		exit(0);
	}
	//read data from input file
	outFile << showpoint << fixed << setprecision(2);
	while (!inFile.eof())
	{
		inFile >> lname >> fname >> basePay >> bonus;
		totalPay = basePay + (basePay * bonus / 100);
		outFile << lname << " " << fname << " " << totalPay << endl;
	}
	inFile.close();
	outFile.close();

	return 0;
}