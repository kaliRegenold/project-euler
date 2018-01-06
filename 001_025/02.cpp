#include <iostream>

int main()
{
	int a = 1, b = 1, temp;
	int sum = 0;
	
	while(b <= 4000000)
	{
		if(b%2 == 0)
			sum+=b;
		// Fibonacci: no recursion
		temp = b;
		b = a+b;
		a = temp;
	}
	std::cout << sum << std::endl;
	return 0;
}
