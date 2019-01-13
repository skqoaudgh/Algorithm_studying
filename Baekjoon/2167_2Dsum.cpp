#include <stdio.h>

int arr[301][301];

int main()
{
	int N,M,K;
	scanf("%d %d",&N,&M);
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			scanf("%d",&arr[i][j]);
		
	scanf("%d",&K);	
	for(int t=0; t<K; t++)
	{
		int i,j,x,y;
		int sum = 0;
		scanf("%d %d %d %d",&i,&j,&x,&y);
		for(int p=i; p<=x; p++)
			for(int q=j; q<=y; q++)
				sum += arr[p][q];
		printf("%d\n",sum);
	}
	return 0;
}
