#include <iostream>
#include <math.h>

bool isPrime(long num)
{
	if(num == 1 || num == 2)
		return true;
	if(num%2 == 0)
		return false;
	for(long i = 3; i <= sqrt(num); i+=2)
	{
		if(num%i == 0)
			return false;
	}
	return true;
}


int main()
{
	long max = 0;
	long target = 600851475143;


	for(long i = 1; i < sqrt(target); i++)
	{
		if(target%i == 0 && isPrime(i))
			if(i>max)
				max = i;
	}
	std::cout << max << std:: endl;
	return 0;
}


