//This program demos 2 dim arrays
#include <iostream>
using namespace std;

//global constants
const int STDS = 3;
const int QZS = 2;


//function prototypes
double readDouble();
void readInput(double scores[][QZS]);
void calcAverage(double scores[][QZS], double average[]);
void output(double scores[][QZS], double average[]);

int main()
{
	//declare 2 dim array
	double scores[STDS][QZS] = { 0 }, average[STDS];
	readInput(scores);
	calcAverage(scores, average);
	output(scores, average);
	
	return 0;
}

//Name: readDouble (reads and validates an integer)
//input: none
//output: error message
//return: double
double readDouble()
{
	double temp = 0;

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

//reads input from the user
void readInput(double scores[][QZS])
{
	for (int i = 0; i < STDS; i++)
	{
		cout << "Enter quiz scores for student " << i + 1 << ":";
		for (int j = 0; j < QZS; j++)
		{
			scores[i][j] = readDouble();
		}
	}
}

//calculate the average
void calcAverage(double scores[][QZS], double average[])
{
	double total = 0;
	//calculate quiz average for each student
	for (int i = 0; i < STDS; i++)
	{
		total = 0;
		for (int j = 0; j < QZS; j++)
		{
			total += scores[i][j];
		}
		average[i] = total / QZS;
	}
}

//output to the user
void output(double scores[][QZS], double average[])
{
	//output the scores and the average
	for (int i = 0; i < STDS; i++)
	{
		for (int j = 0; j < QZS; j++)
		{
			cout << scores[i][j] << " ";
		}
		cout << average[i] << endl;
	}
}