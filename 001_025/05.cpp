#include <iostream>

int main()
{
	bool found = false, madeIt = true;
	int ans = 0;

	while(!found)
	{
		ans += 20;
		madeIt = true;
		for(int i = 1; i <= 20; i++) //Change to only necessary?
		{
			if(ans%i != 0)
				madeIt = false;
		}

		if(madeIt)
			found = true;
	}

	std::cout << ans << std::endl;

	return 0;
}
