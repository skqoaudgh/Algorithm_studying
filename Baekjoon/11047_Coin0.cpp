#include <iostream>
using namespace std;

int main()
{
	int N,K,arr[10];
	cin >> N >> K;
	for(int i=0; i<N; i++)
		cin >> arr[i];
		
	int ans = 0, j = N-1;
	while(K > 0)
	{
		if(K >= arr[j])
		{
			K -= arr[j];
			ans ++;
		}
		else
			j --;
	}
	
	cout << ans;
	return 0;
}
