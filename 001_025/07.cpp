#include <iostream>
#include <math.h>

bool isPrime(unsigned long long num)
{
	if(num == 1 || num == 2 || num == 3)
		return true;
	if(num%2 == 0)
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
	unsigned long long count = 0;
	unsigned long long num = 1;

	while(count < 10001)
	{
		num++;
		if(isPrime(num))
			count++;
	}

	std::cout << num << std::endl;

}
