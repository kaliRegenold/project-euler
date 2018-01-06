#include <iostream>

int main()
{
	unsigned long long squaredSum = 0;
	unsigned long long sumSquared = 0;

	for(int i = 1; i <= 100; i++)
	{
		sumSquared += i*i; // 1^2 + 2^2 + 3^2 ...
		squaredSum += i;   // 1 + 2 + 3 ...
	}
	
	squaredSum *= squaredSum;

	std::cout << squaredSum - sumSquared << std::endl;

	// Really, this one was just hard to say in my head

	return 0;
}
