#include <stdio.h>

int arr[101];
int main()
{
	int T;
	scanf("%d",&T);
	for(int test_case=0; test_case<T; test_case++)
	{
		int N,K;
		scanf("%d %d",&N,&K);
		int ans = 0;
		for(int i=0; i<N; i++)
		{
			scanf("%d",&arr[i]);
			ans += arr[i] / K;
		}
		printf("%d\n",ans);
	}
	return 0;
}
