//This program demos enumerated data types
//We will create an enum called CATEGORY to hold food category for NutriCalc application
//CATEGORY:	FRUITS, MEAT, DAIRY, VEGETABLES, FAT, CARBS, ILLEGAL

#include <iostream>
#include <string>

using namespace std;

//enum data type
enum CATEGORY { FRUITS, MEAT, DAIRY, VEGETABLES, FAT, CARBS, ILLEGAL };

//function prototypes
void readCategory(char option, CATEGORY &myCat);
//could also be written as
//CATEGORY readCategory(char option);

void writeCategory(CATEGORY myCat, string &catDesc);

int main()
{
	//declare enum variable
	CATEGORY myCat;
	char option;
	string catDesc;
	cout << "Please enter the category: "
		<< " FRUITS(r), MEAT(m), DAIRY(d), VEGETABLES(v), FAT(f), CARBS(c)";
	cin >> option;
	//read input and assign to myCat
	readCategory(option, myCat);
	//output to the user
	writeCategory(myCat, catDesc);
	cout << "Your category is " << catDesc << endl;

	return 0;
}

//function to read the enum data type
void readCategory(char option, CATEGORY &myCat)
{
	switch (tolower(option))
	{
	case 'r':
		myCat = static_cast<CATEGORY>(0);
		break;
	case 'm':
		myCat = static_cast<CATEGORY>(1);
		break;
	case 'd':
		myCat = static_cast<CATEGORY>(2);
		break;
	case 'v':
		myCat = static_cast<CATEGORY>(3);
		break;
	case 'f':
		myCat = static_cast<CATEGORY>(4);
		break;
	case 'c':
		myCat = static_cast<CATEGORY>(5);
		break;
	default:
		myCat = static_cast<CATEGORY>(6);
	}
}

//output CATEGORY to user
void writeCategory(CATEGORY myCat, string &catDesc)
{
	switch (myCat)
	{
	case FRUITS:
		catDesc = "FRUITS";
		//cout << "You entered FRUITS!" << endl;
		break;
	case MEAT:
		catDesc = "MEAT";
		//cout << "You entered MEAT!" << endl;
		break;
	case DAIRY:
		catDesc = "DAIRY";
		//cout << "You entered DAIRY!" << endl;
		break;
	case VEGETABLES:
		catDesc = "VEGETABLES";
		//cout << "You entered VEGETABLES!" << endl;
		break;
	case FAT:
		catDesc = "FAT";
		//cout << "You entered FAT!" << endl;
		break;
	case CARBS:
		catDesc = "CARBS";
		//cout << "You entered CARBS!" << endl;
		break;
	default:
		catDesc = "ILLEGAL CATEGORY";
		//cout << "You entered ILLEGAL CATEGORY!" << endl;
	}
}