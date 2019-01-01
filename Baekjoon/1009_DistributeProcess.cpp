#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int test_case=0; test_case<t; test_case++)
	{
		int a,b;
		int ans;
		cin >> a >> b;
		
		ans = a%10;
		for(int i=1; i<b; i++)
			ans = (ans*a)%10;

		if(ans == 0)
			ans = 10;
		cout << ans << '\n';
	}
	return 0;
}
