#include <iostream>
#include <math.h>

unsigned long long countFactors(unsigned long long num)
{
	unsigned long long count = 0;
	unsigned long long square = sqrt(num);
	for(unsigned long long i = 1; i <= square; i++)
	{
		if(num%i == 0)
		{
			count+=2; //Count the number that was tested and its pair
		}
	}
	if(pow(square,2) == num)
		count--; //If the square root is a real number, we counted it twice
	return count;
}

int main()
{
	bool found = false;
	unsigned long long target = 1;
	unsigned long long increment = 2;

	while(!found)
	{
		if(countFactors(target) > 500)
			found = true;
		else
		{
			target += increment;
			increment++;
		}
	}

	std::cout << target << std::endl;

	return 0;
}
