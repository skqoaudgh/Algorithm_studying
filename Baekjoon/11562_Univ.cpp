#include <stdio.h>
using namespace std;

#define MAX 250
#define INF 987654321

int main()
{
	int n,m,k;
	int dist[MAX][MAX];
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			if(i == j)
				dist[i][j] = 0;
			else
				dist[i][j] = INF;
		}
			
			
	for(int i=0; i<m; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;
		b--;
		if(c == 0)
		{
			dist[a][b] = 0;
			dist[b][a] = 1;
		}
		else
		{
			dist[a][b] = 0;
			dist[b][a] = 0;
		}
	}

	for(int t=0; t<n; t++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(dist[i][j] > dist[i][t] + dist[t][j])
					dist[i][j] = dist[i][t] + dist[t][j];
							
	scanf("%d",&k);
	for(int i=0; i<k; i++)
	{
		int s,e;
		scanf("%d %d",&s,&e);
		printf("%d\n",dist[s-1][e-1]);
	}
	return 0;
}
