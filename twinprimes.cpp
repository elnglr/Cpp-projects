
///COSC-1436 Spring 
//Assignment no:6, twin primes 
//hlnglr, 3339004

#include <iostream>
using namespace std;

void primeNumbers(long int start, long int end);
void twinPrimes(long int start, long int end);

int main()
{
	long int startNum;
	long int endNum;

	cout << "Please enter two numbers you would like to check the primes and twin primes in between" << endl;
	cout << "Starting Number: ";
	cin >> startNum;
	cout << endl << "Ending Number: ";
	cin >> endNum;

	cout << endl << endl;
	cout << "Prime Numbers: ";
	primeNumbers(startNum, endNum);

	cout << endl << endl << "Twin Primes: ";
	twinPrimes(startNum, endNum);
	return 0;
}

void primeNumbers(long int start, long int end)
{
	long int n = 3;
	long int sum = 0;
	long int totalPrimes = 0;
	bool isPrime = true;

	for (int i = start; i <= end; i++)
	{
		n = 3;
		if (i % 2 != 0 && i != 1)
		{
			bool isPrime = true;
			while (n <= (i / 2))
			{
				if (i % n == 0)
				{
					isPrime = false;
					break;
				}
				else
				{
					n++;
				}
			}
			if (isPrime)
			{
				cout << i << " ";
				totalPrimes++;
				sum += i;
			}
		}
	}

	cout << endl << endl << "Total Primes: " << totalPrimes << endl << "Sum of Primes " << sum;

}

void twinPrimes(long int start, long int end)
{

	long int lastPrime = 0;
	long int n = 3;
	long int sum = 0;
	long int totalTwins = 0;
	bool isPrime = true;

	for (int i = start; i <= end; i++)
	{
		n = 3;
		if (i % 2 != 0 && i != 1)
		{
			bool isPrime = true;
			while (n <= (i / 2))
			{
				if (i % n == 0)
				{
					isPrime = false;
					break;
				}
				else
				{
					n++;
				}
			}
			if (isPrime)
			{
				if (lastPrime != 0)
				{
					if ((i - lastPrime) == 1 || (i - lastPrime) == 2)
					{
						cout << " [" << lastPrime << " , " << i << "]";
						totalTwins++;
						lastPrime = i;
					}
				}
				else
				{
					lastPrime = i;
				}
				lastPrime = i;
			}
		}
	}

	cout << endl << "Total Twins: " << totalTwins << endl;


}