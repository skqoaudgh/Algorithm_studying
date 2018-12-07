#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int test_case=0; test_case<T; test_case++)
	{
		int N;
		cin >> N;
		int temp = N;
		int cnt = 0;
		while(temp>0)
		{
			if(temp%2 == 1)
				cout << cnt << ' ';
			temp /= 2;	
			cnt ++;
		}
	}
	return 0;
}
