#include <iostream>

#define ARR_SIZE 200

void roll(unsigned long long * arr)
{
	unsigned long long carry;
	for(int i = 0; i < ARR_SIZE-1; i++)
	{
		carry = arr[i]/10;
		arr[i] %= 10;
		arr[i+1] += carry;
	}
}

// O(n^2) ish. Can be better

int main()
{
	unsigned long long * result = new unsigned long long[ARR_SIZE];	
	int sum = 0;

	result[0] = 1;

	for(int i = 1; i <= 100; i++)
	{
		for(int j = 0; j < ARR_SIZE; j++)
		{
			result[j] *= i;
		}
		roll(result);
	}

	for(int i = ARR_SIZE-1; i >= 0; i--)
	{
		sum += result[i];
	}

	std::cout << sum << std::endl;

	delete result;
}