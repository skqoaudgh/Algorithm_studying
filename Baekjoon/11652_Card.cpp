#include <iostream>
#include <algorithm>
using namespace std;

long long int arr[1000001];

int main()
{
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> arr[i];
	sort(arr,arr+N);
	
	int cnt = 0;
	int max_cnt = 0;
	long long int ans = 0;
	for(int i=0; i<N; i++)
	{
		if(arr[i] != arr[i-1])
			cnt = 0;		
		cnt ++;
		if(max_cnt < cnt)
		{
			max_cnt = cnt;
			ans = arr[i];
		}
	}
	cout << ans;
	return 0;
}
