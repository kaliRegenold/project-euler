// ./13 < 13.txt
#include <iostream>

int main()
{
	int * array = new int[52];
	char curr;
	
	//Add all digits in place
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 50; j++)
		{
			std::cin >> curr;		
			array[2+j] += (curr - '0');
		}
	}

	//Carry over as necessary
	int carry = 0;
	for(int i = 51; i >= 0; i--)
	{
		array[i] += carry;
		carry = array[i]/10;
		array[i] %= 10;		
	}

	for(int i = 0; i < 52; i++)
		std::cout << array[i];
	std::cout << std::endl;

	delete[] array;

	return 0;
}
