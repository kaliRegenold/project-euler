// ./11.cpp < 11.txt
#include <iostream>

int main()
{
	int array[20][20];
	int curr;
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
		{
			std::cin >> curr;
			array[i][j] = curr;
		}

	int product;

	//Across
	int across_max = 0;
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20-3; j++)
		{
			product = array[i][j+0] * array[i][j+1] * array[i][j+2] * array[i][j+3];
			if(product > across_max)
				across_max = product;
		}

	//Down
    int down_max = 0;
    for(int i = 0; i < 20-3; i++)
        for(int j = 0; j < 20; j++)
        {
            product = array[i+0][j] * array[i+1][j] * array[i+2][j] * array[i+3][j];
            if(product > down_max)
                down_max = product;
        }

	//Down Diagonal
    int dd_max = 0;
    for(int i = 0; i < 20-3; i++)
        for(int j = 0; j < 20-3; j++)
        {
            product = array[i+0][j+0] * array[i+1][j+1] * array[i+2][j+2] * array[i+3][j+3];
            if(product > dd_max)
                dd_max = product;
        }

	//Up Diagonal
    int ud_max = 0;
    for(int i = 3; i < 20; i++)
        for(int j = 0; j < 20-3; j++)
        {
            product = array[i-0][j+0] * array[i-1][j+1] * array[i-2][j+2] * array[i-3][j+3];
            if(product > ud_max)
                ud_max = product;
        }  

	std::cout << "across \t" << across_max << std::endl;
	std::cout << "down \t" << down_max << std::endl;
	std::cout << "DD \t" << dd_max << std::endl;
	std::cout << "UD \t" << ud_max << std::endl;

	int max = across_max;
	if(down_max > max) max = down_max;
	if(dd_max > max) max = dd_max;
	if(ud_max > max) max = ud_max;

	std::cout << "max \t" << max << std::endl;

	return 0;
}
