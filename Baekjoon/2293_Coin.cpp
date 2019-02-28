#include <cstdio>

int main()
{
	int n,k;
	int arr[101];
	int dp[10001] = {0};
	
	scanf("%d %d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",&arr[i]);
		
	dp[0] = 1;
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=k; j++)
		{
			if(j >= arr[i])
				dp[j] += dp[j-arr[i]];
		}
	}
	printf("%d\n",dp[k]);
	return 0;
}
