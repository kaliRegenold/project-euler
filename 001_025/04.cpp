#include <iostream>
#include <string>

bool isPalendrome(int num)
{
	int a[6];
	int temp;

	// Transfer int to array
	for(int i = 5; i >= 0; i--)
	{
		temp = num%10;
		a[i] = temp;
		num = num/10;
	}

	// Check Palendrome for 5 digit...
	if(a[0] == 0)
	{
		if(a[1]==a[5] && a[2]==a[4])
			return true;
	}
	// ...or 6 digit
	else
		if(a[0]==a[5] && a[1]==a[4] && a[2]==a[3])
			return true;
	return false;
}

int main()
{
	int max = 0;
	int product;

	for(int i = 100; i < 1000; i++)
		for(int j = i; j < 1000; j++)
		{
			product = i*j;
			if(isPalendrome(product) && (product) > max)
				max = product;
		}
	std::cout << max << std::endl;
	return 0;
}
