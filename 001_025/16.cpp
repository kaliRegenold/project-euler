#include <iostream>

void shift(int arr[350])
{
    int carry = 0;
    for(int i = 350-1; i >=0; i--)
    {
        arr[i] += carry;
        if(arr[i] > 9)
        {
            carry = arr[i]/10;
            arr[i] %= 10;
        }
        else
            carry = 0;
    }
}



int main()
{
    int size = 350;
    int * array = new int[size];
    int sum = 0;
    array[size-1] = 2;

       
    for(int i = 0; i < 999; i++)
    {
        for(int j = 0; j < size; j++)
        {
            array[j] *= 2;
        }
        shift(array);
    }

    for(int i = 0; i < size; i++)
    {
        sum += array[i];
        std::cout << array[i] << "";
    }
    std::cout << std::endl; 
    
    std::cout << "SUM " << sum << std::endl;

    delete[] array;
    return 0;
}
