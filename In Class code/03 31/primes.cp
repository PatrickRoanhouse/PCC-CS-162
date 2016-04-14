//This program counts the number fo primes between 1 and 1000
#include <iostream>
using namespace std;

//function prototypes
bool isPrime(int num);
void primeCount(int start, int end);


int main()
{
	int start = 1, end = 1000, count = 0;
	for (int x = start; x <= 50; x++)
	{
		primeCount(start, end);
		start += 1000;
		end += 1000;
	}

	return 0;
}

//function to check if a number is prime
bool isPrime(int num)
{
	if (num == 1)
		return false;
	else if (num == 2)
		return true;
	else if (num % 2 == 0)
	{
		return false;
	}
	else
	{
		for (int i = 3; i <= num / 2; i += 2)
		{
			if (num % i == 0)
				return false;
		}
		return true;
	}
}

//function to count primes from start to end
void primeCount(int start, int end)
{
	int count = 0;
	for (int i = start; i <= end; i++)
	{
		if (isPrime(i))
		{
			count++;
		}
	}
	cout << "Primecount between " << start << " and " << end << " is " << count << endl;
}