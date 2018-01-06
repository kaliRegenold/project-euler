#include <iostream>

int main()
{
    unsigned long long max_chain = 0;
    unsigned long long assoc_int;
    unsigned long long curr_chain = 0;
    unsigned long long curr_int;

    for(unsigned long long i = 999999; i > 1; i--)  //cycle through under 1 million
    {
        curr_int = i;
        while(curr_int > 1)                         //follow sequence until 1
        {
            if(curr_int%2==0)
                curr_int /= 2;
            else
                curr_int = (curr_int*3) + 1;
            curr_chain++;
        }
        if(curr_chain > max_chain)                  //compare largest chain and number to get there
        {
            assoc_int = i;
            max_chain = curr_chain;
        }
        curr_chain = 0;
    }
    std::cout << "Max Chain " << max_chain << "  Number to produce " << assoc_int << std::endl;
    
    return 0;
}
