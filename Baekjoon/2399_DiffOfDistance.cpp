#include <stdio.h>
#include <algorithm>
using namespace std;

long long int arr[10001];
int main()
{
	long long int ans = 0;
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%lld",&arr[i]);
	sort(arr,arr+n);
	for(int i=0; i<n; i++)
	{
		ans += (arr[i]*i - arr[i]*(n-i-1));
	}
	
	printf("%lld",ans*2);
	return 0;
}
