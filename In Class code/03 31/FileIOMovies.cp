//This program demos how to read from a file and how to output the results to a file
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//global constants
const int MAXCHAR = 101;

//enums
enum Category {ACTION, COMEDY, ROMANCE, FAMILY, ILLEGAL};

//function prototypes
void readCategory(char tempGenre[], Category &genre);
void writeCategory(Category genre,  char genreDesc[]);

int main()
{
	//variables
	char title[MAXCHAR], tempGenre[MAXCHAR], genreDesc[MAXCHAR];
	Category genre;
	int quantity = 0;
	ifstream inFile;
	ofstream outFile;
	//open the input file
	inFile.open("movies.txt");
	if (!inFile)
	{
		cout << "Input file not found! Program exiting!!" << endl;
		exit(0);
	}
	
	//read data from input file
	cout << "You have the following movies:" << endl;
	while (!inFile.eof())
	{
		inFile.get(title, MAXCHAR, ';');
		inFile.ignore(5, ';');
		inFile.get(tempGenre, MAXCHAR, ';');
		inFile.ignore(5, ';');
		readCategory(tempGenre, genre);
		inFile >> quantity;
		inFile.ignore(100, '\n');
		writeCategory(genre, genreDesc);
		cout << title << ";" << genreDesc << ';' << quantity << endl;
	}
	inFile.close();

	return 0;
}

//function to assign the enum data type
void readCategory(char tempGenre[], Category &genre)
{
	if (strcmp(tempGenre, "ACTION"))
		genre = ACTION;
	else if (strcmp(tempGenre, "COMEDY"))
		genre = COMEDY;
	else if (strcmp(tempGenre, "ROMANCE"))
		genre = ROMANCE;
	else if (strcmp(tempGenre, "FAMILY"))
		genre = FAMILY;
	else
		genre = ILLEGAL;
}

//output CATEGORY to user
void writeCategory(Category genre, char genreDesc[])
{
	switch (genre)
	{
	case ACTION:
		strcpy_s(genreDesc, MAXCHAR, "ACTION");
		break;
	case COMEDY:
		strcpy_s(genreDesc, MAXCHAR, "COMEDY");
		break;
	case ROMANCE:
		strcpy_s(genreDesc, MAXCHAR, "ROMANCE");
		break;
	case FAMILY:
		strcpy_s(genreDesc, MAXCHAR, "FAMILY");
		break;
	default:
		strcpy_s(genreDesc, MAXCHAR, "ILLEGAL");
	}
}