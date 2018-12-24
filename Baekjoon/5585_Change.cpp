#include <iostream>
using namespace std;

int main()
{
	int N, i=0,cnt=0;
	cin >> N;
	N = 1000-N;
	int arr[6] = {500,100,50,10,5,1};
	while(N > 0)
	{
		if(N >= arr[i])
		{
			N -= arr[i];
			cnt ++;
		}
		else
			i ++;
	}
	cout << cnt;
	return 0;
}
