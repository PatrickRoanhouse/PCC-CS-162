//This program is very similar to Project 2
//Uses structs to model a movie in a VideoStore, and an array of structs to model the VideoStore
#include <iostream>
#include <fstream>

using namespace std;

//constants
const int CAP = 100;
const int MAXCHAR = 101;

//struct data type
struct Video
{
	char title[MAXCHAR];
	int qty;
	char genre[MAXCHAR];
};

//function prototypes
void openFile(ifstream &inFile);
void loadFile(ifstream &inFile, Video store[], int &size);
void writeFile(Video store[], int &size);
int readInt(char prompt[]);
void displayMenu();
char readOption();
void exeCmd(char option, Video store[], int &size);
void addMovie(Video store[], int &size);
void displayList(Video store[], const int size);
void findMovie(Video store[], const int size);
void delMovie(Video store[], int &size);
void sortList(Video store[], const int size);

//main
int main()
{
	//variables
	Video store[CAP];
	ifstream inFile;
	int size = 0;
	char option;
	//open the file
	openFile(inFile);
	loadFile(inFile, store, size);
	//display the menu
	do
	{
		displayMenu();
		option = readOption();
		exeCmd(option, store, size);
	} while (tolower(option) != 'q');

	return 0;
}

//openfile function
void openFile(ifstream &inFile)
{
	inFile.open("movies.txt");
	if (!inFile)
	{
		cout << "File not found! Program terminating!!" << endl;
		exit(0);
	}
}

//load data from file into our array
void loadFile(ifstream &inFile, Video store[], int &size)
{
	inFile.get(store[size].title, MAXCHAR, ';');
	while (!inFile.eof())
	{
		inFile.ignore(5, ';');
		inFile >> store[size].qty;
		inFile.ignore(5, ';');
		inFile.get(store[size].genre, MAXCHAR, '\n');
		inFile.ignore(5, '\n');
		size++;
		inFile.get(store[size].title, MAXCHAR, ';');
	}
	inFile.close();
}

//displays the menu
void displayMenu()
{
	cout << "Welcome to the VideoStore:" << endl << endl;
	cout << "Pick an option" << endl;
	cout << "[A-a]: Add a movie" << endl;
	cout << "[D-d]: Display the List" << endl;
	cout << "[F-f]: Find a movie" << endl;
	cout << "[R-r]: Delete a movie" << endl;
	cout << "[Q-q]: Quit" << endl;
}

//read the option from the user
char readOption()
{
	char input;
	cin >> input;
	cin.ignore(100, '\n');
	return input;
}

//execute the option
void exeCmd(char option, Video store[], int &size)
{
	switch (tolower(option))
	{
	case 'a':
		addMovie(store, size);
		break;
	case 'd':
		sortList(store, size);
		displayList(store, size);
		break;
	case 'r':
		delMovie(store, size);
		break;
	case 'f':
		findMovie(store, size);
		break;
	case 'q':
		writeFile(store, size);
		break;
	default:
		cout << "Invalid input, please try again!!" << endl;
	}
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

//add a movie from the user
void addMovie(Video store[], int &size)
{
	cout << "Enter a movie name:";
	cin.get(store[size].title, MAXCHAR, '\n');
	cin.ignore(100, '\n');
	store[size].qty = readInt("Enter quantity:");
	cout << "Enter movie genre:";
	cin.get(store[size].genre, MAXCHAR, '\n');
	cin.ignore(100, '\n');
	size++;
}

//display the list of movies
void displayList(Video store[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << i+1 << ": " << store[i].title << ';' << store[i].qty << ';' << store[i].genre << '\n';
	}
	cout << endl;
}

//find a movie
void findMovie(Video store[], const int size)
{
	char srchTitle[MAXCHAR];
	cout << "Enter the movie you are looking for:";
	cin.get(srchTitle, MAXCHAR, '\n');
	for (int i = 0; i < size; i++)
	{
		if (strstr(store[i].title, srchTitle))
		{
			cout << store[i].title << ';' << store[i].qty << ';' << store[i].genre << '\n';
		}
	}
	cout << endl;
}

//delete a movie from the list
//delete a number
void delMovie(Video store[], int &size)
{
	int selection = 0;
	displayList(store, size);
	cout << "Which movie would you like to delete?: ";
	cin >> selection;
	for (int i = selection-1; i < size; i++)
	{
		store[i] = store[i + 1];
	}
	size--;
	displayList(store, size);
}


//sorts the list
void sortList(Video store[], const int size)
{
	int minIndex = 0;
	Video tempVideo;
	for (int i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (strcmp(store[minIndex].title, store[j].title) > 0)
				minIndex = j;
		}
		//swap the array content - swap the videos
		tempVideo = store[minIndex];
		store[minIndex] = store[i];
		store[i] = tempVideo;
	}
}

//writes the data back to the file
void writeFile(Video store[], int &size)
{
	ofstream outFile;
	outFile.open("movies.txt");
	for (int i = 0; i < size; i++)
	{
		outFile << store[i].title << ';' << store[i].qty << ';' << store[i].genre << '\n';
	}
	outFile.close();
}