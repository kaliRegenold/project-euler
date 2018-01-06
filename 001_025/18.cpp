#include <iostream>

int main()
{
    int rows = 15;
    int ** triangle = new int*[rows];
    int * path = new int[rows]; 
    int sum = 0;
    

    // Read in triangle
    for(int r = 0; r < rows; r++)
    {
        triangle[r] = new int[r+1];
        for(int c = 0; c <= r; c++)
            std::cin >> triangle[r][c];
    }
    
    int left, right;

    // This is too damn simple.
    for(int i = rows-1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            left = triangle[i-1][j] + triangle[i][j];
            right = triangle[i-1][j] + triangle[i][j+1];
            triangle[i-1][j] = (left < right ? right : left);
        }
    }

    std::cout << triangle[0][0] << std::endl;

    for(int r = 0; r < rows; r++)
        delete[] triangle[r];
    delete[] triangle;
    delete[] path;
    return 0;
}
