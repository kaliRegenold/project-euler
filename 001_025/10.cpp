#include <iostream>
#include <math.h>

bool isPrime(unsigned long long num)
{
	if(num == 2 || num == 3)
		return true;
	if(num%2 == 0 || num == 1)
		return false;
	for(unsigned long long i = 3; i <= sqrt(num); i+=2)
	{
		if(num%i == 0)
			return false;
	}
	return true;
}

int main()
{
	unsigned long long sum = 0;
	
	for(unsigned long long i = 2; i < 2000000; i++)
	{
		if(isPrime(i))
			sum+=i;
	}
	
	std::cout << sum << std::endl;

	return 0;
}
