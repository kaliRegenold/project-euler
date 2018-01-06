#include <iostream>
#include <list>
#include <cmath>
#include <chrono>

#define TARGET 28123

using namespace std;

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

bool isAbundant(int num)
{
	return d(num) > num;
}

// 4179871
int main()
{
	int massive_sum = (TARGET * (TARGET + 1)) / 2;
	int * abundant_nums = new int[TARGET];
	int counter = 0;


	for(int i = 1; i <= TARGET; i++)
	{
		if(isAbundant(i))
		{
			abundant_nums[counter] = i;
			counter++;
		}
	}

	int ab_sum_size = (counter * (counter + 1)) / 2;
	int * abundant_sums = new int[ab_sum_size];
	int ab_sum_index = 0;
	int a, b;

	for(int i = 0; i < counter; i++) 
	{
		for(int j = i; j < counter; j++)
		{
			a = abundant_nums[i];
			b = abundant_nums[j];
			if(a+b <= TARGET)
			{				
				abundant_sums[ab_sum_index] = a + b;
				ab_sum_index++;
			}
		}
	}

	list<int> unique_ab_sums(abundant_sums, abundant_sums + ab_sum_index);
	unique_ab_sums.sort();
	unique_ab_sums.unique();

	int unique_size = unique_ab_sums.size();


	while(!unique_ab_sums.empty())
	{
		massive_sum -= unique_ab_sums.back();
		unique_ab_sums.pop_back();
	}

	cout << massive_sum << endl;

	delete abundant_sums;
	delete abundant_nums;
}