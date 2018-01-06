// ./8 < 8.txt

#include <iostream>

int main()
{
	char array[1000];
	char curr;
	for(int i = 0; i < 1000; i++)
	{
		std::cin >> curr;
		array[i] = curr;
	}

	unsigned long long product = 1;
	unsigned long long max = 0;

	for(int i = 0; i < 1000 - 13; i++)
	{
		for(int j = 0; j < 13; j++)
			product *= array[i+j] - '0';
		if(product > max)
			max = product;
		product = 1;
	}

	std::cout << max << std::endl;

	return 0;
}
