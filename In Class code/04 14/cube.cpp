//this program defines a cube class and its memberfunctions
#include <iostream>

using namespace std;

class Cube
{
private:
	double side;
public:
	double area();
	double volume();
	void properties();
	bool equalCube(const Cube &aCube);
	//accessor functions
	double getSide();
	//mutator function
	void setSide(double s);
}

//function implementation
//accessor functions
double Cube::getSide()
{
	return side;
}

//mutator function
void Cube::setSide(double s)
{
	side = s;
}

//area and volume functions
double Cube::area()
{
	return (6 * side * side);
}
double Cube::volume()
{
	return (pow(side, 3));
}
void Cube::properties();
{
	cout << "Properties of the cube:" << endl;
	cout << "Side   = " << side << endl;
	cout << "Area   = " << area() << endl;
	cout << "Volume = " << volume() << endl;
}
//compares 2 cubes and returns true or false
bool Cube::equalCube(const Cube &aCube)
{
	return(side == aCube.side);
}

//driver program - main
int main (){
	Cube cube1, cube2;

	cube1.setSide(5);
	cube2.setSide(7.5);
	cube1 = cube 2
	cube1.properties();
	if (cube1.equalCube(cube2)
	{
		cout << "Cube1 and Cube2 are the same!" << endl;
	}
	else 
	{
		cout << "Cube1 and Cube2 are NOT the same!" << endl;
	}

	return 0;
}