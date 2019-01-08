#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int test_case=0; test_case<T; test_case++)
	{
		int N,M;
		scanf("%d %d",&N,&M);
		int ans = 2*M-N;
		printf("%d %d\n",ans,M-ans);
	}
	return 0;
}
