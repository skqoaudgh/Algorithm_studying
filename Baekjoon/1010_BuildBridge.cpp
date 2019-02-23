#include <cstdio>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,M;
		scanf("%d %d",&N,&M);

		int dp[31][31];	
		for(int i=0; i<31; i++)
			for(int j=0; j<31; j++)
				dp[i][j] = 0;
		for(int i=0; i<31; i++)
			dp[1][i] = i;
		for(int i=2; i<31; i++)
			for(int j=i; j<31; j++)
				for(int k=i-1; k<=j-1; k++)
					dp[i][j] += dp[i-1][k];
					
		printf("%d\n",dp[N][M]);
	}
	return 0;
}
