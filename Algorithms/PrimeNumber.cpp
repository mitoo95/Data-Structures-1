#include <iostream>

using namespace std;

void primeNumber();

int main() {

	primeNumber();

}

void primeNumber() {

	int inputNum, loopCounter;
	bool isPrime = true;

	cout << "Enter a positive integer: ";
	cin >> inputNum;

	for (loopCounter = 2; loopCounter <= inputNum / 2; ++loopCounter)
	{
		if (inputNum % loopCounter == 0)
		{
			isPrime = false;
			break;
		}
	}
	if (isPrime)
		cout << "This is a prime number";
	else
		cout << "This is not a prime number";

}