#include <iostream>
#include <string>

using namespace std;

int main()
{
    string * words = new string[30];
    for(int i = 0; i < 30; i++)
        cin >> words[i];

    int sum = 0;

    string current_ten="", current_hundred="", current_one = "";

    // Hundreds loop
    for(int h = 0; h < 10; h++)
    {
        if(h != 0) // If we need to start counting hundreds
            current_hundred = words[h-1] + words[27]; //27=hundred
        // Tens loop
        for(int t = 0; t < 10; t++)
        {
            if(t != 0 && t != 1) // If we need to count on tens, OR not teens
                current_ten = words[19+t-2];
            else
                current_ten = "";
            // Ones loop
            for(int o = 0; o < 10; o++)
            {
                // Teen Case
                if(t == 1)
                    current_one = words[9+o];
                else
                {
                    if(o != 0)
                        current_one = words[o-1];
                    else
                        current_one = "";
                }

                if(t == 0 && o == 0)
                {
                    //cout <<  current_hundred << endl;
                    sum += current_hundred.length();
                }
                else if(h == 0)
                {
                    //cout << current_ten << current_one << endl;
                    sum += current_ten.length() + current_one.length();
                }
                else
                {
                    //cout << current_hundred << words[29] << current_ten << current_one << endl;
                    sum += current_hundred.length() + words[29].length() + current_ten.length() + current_one.length();
                }
            }
        }
    }

    //cout << words[0] << words[28] << endl;
    sum += words[0].length() + words[28].length();

    cout << sum << endl;

}




