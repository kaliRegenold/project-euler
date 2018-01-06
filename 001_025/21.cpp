#include <iostream>
#include <math.h>

#define TABLE_SIZE 10000

int d(int n)
{
	int sum = 1;
	int limit = sqrt(n);
	for(int i = 2; i <= limit; i++)
	{
		if(n%i == 0)
		{
			sum+=i;
			sum+=n/i;
		}
	}
	if(limit*limit == n)
		sum-=limit;
	return sum;
}

int main()
{
	int * table = new int[TABLE_SIZE];
	int sum = 0;

	for(int i = 2; i < TABLE_SIZE; i++)
	{
		table[i] = d(i);
	}

	for(int i = 2; i < TABLE_SIZE; i++)
	{
		int t_i = table[i];
		int t_a = table[t_i];
		if(t_a == i && t_i != t_a)
		{
			sum+=t_a;
		}
	}

	std::cout << sum << std::endl;

	delete table;
}