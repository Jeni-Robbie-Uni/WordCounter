#include "NumUtils.h"

//Claculates next prime number, this code was from the link below.
// https://stackoverflow.com/questions/30052316/find-next-prime-number-algorithm

//checks if input is a prime number
bool NumUtils::IsPrime(int number)
{

	if (number == 2 || number == 3)
		return true;

	if (number % 2 == 0 || number % 3 == 0)
		return false;

	int divisor = 6;
	while (divisor * divisor - 2 * divisor + 1 <= number)
	{

		if (number % (divisor - 1) == 0)
			return false;

		if (number % (divisor + 1) == 0)
			return false;

		divisor += 6;

	}

	return true;

}
//calculates the next possible prime number from input
int NumUtils::NextPrime(int a)
{

	while (!IsPrime(++a))
	{
	}
	return a;
}