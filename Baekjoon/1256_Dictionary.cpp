#include<stdio.h>
#include<algorithm>
using namespace std;

int N,M,K,dp[201][201];

int main() 
{
	dp[0][0] = 1;
    for (int i=0; i<=200; i++) 
	{
        dp[i][0] = 1;
        for (int j=1; j<=i; j++)
            dp[i][j] = min(dp[i-1][j-1] + dp[i-1][j], (int)1e9); // nPr = n-1Pr-1 + n-1Pr 
    }
    scanf("%d %d %d", &N, &M, &K);
    int len = N+M;
    if(K > dp[len][N]) 
		puts("-1");
    else 
	{
        for (int i=0; i<len; i++) 
		{
            if (K > dp[N + M - 1][M]) 
			{
                printf("z");
                K -= dp[N + M - 1][M];
                M--;
            }
            else 
			{
                printf("a");
                N--;
            }
        }
    }
    return 0;
}
