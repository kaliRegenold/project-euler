#include <iostream>

bool isTriple(int a, int b, int c)
{
	if((a*a) + (b*b) == (c*c))
		return true;
	return false;
}

int main()
{
	for(int i = 1; i < 1000; i++)
		for(int j = 1; j < 1000; j++)
			for(int k = 1; k < 1000; k++)
				if(isTriple(i,j,k) && i+j+k == 1000)
				{
					std::cout << i << " " << j << " " << k << std::endl;
					std::cout << i*j*k << std::endl;
					i = 1000;
					j = 1000;
					k = 1000;
				}
	// I don't /really/ like how hacky this is, but it works.
	return 0;
}
