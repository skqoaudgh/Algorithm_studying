#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 100000
#define MAX	500
int main()
{
	int N,M;
	int Dist[MAX][MAX];
			
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			Dist[i][j] = INF;

	for(int i=0; i<M; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		Dist[a-1][b-1] = 1;
	}
	
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(Dist[i][j] > Dist[i][k] + Dist[k][j])
					Dist[i][j] = Dist[i][k] + Dist[k][j];
							
	int ans = 0;
	for(int i=0; i<N; i++)
	{
		int flag = false;
		for(int j=0; j<N; j++)	
		{
			if(i == j) continue;
			if(Dist[i][j] == INF && Dist[j][i] == INF) 
				flag = true;
		}
		if(!flag)
			ans ++;
	}
	printf("%d",ans);	
	return 0;
}
