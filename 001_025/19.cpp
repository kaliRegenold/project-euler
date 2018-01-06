#include <iostream>

bool isLeapYear(int year)
{
	if((year%100 == 0 && year%400 != 0) || (year%4 != 0))
		return false;
	return true;
}

int main()
{
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int sum = 0;
	int day_count = 1;
	int year = 1901;

	while(year < 2001)
	{
		if(isLeapYear(year))
			days[1]++;

		for(int i = 0; i < 12; i++)
		{
			if(day_count%7 == 6)
			{
				sum++;
				day_count = 6;
			}
			day_count += days[i];
		}
		days[1] = 28;
		year++;
	}
	std::cout << sum << std::endl;
}