#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 100000
int main()
{
	int V,E;
	int Dist[400][400];
			
	scanf("%d %d",&V,&E);
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			Dist[i][j] = INF;

	for(int i=0; i<E; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		Dist[a-1][b-1] = c;
	}
	
	for(int k=0; k<V; k++)
		for(int i=0; i<V; i++)
			for(int j=0; j<V; j++)
				if(Dist[i][j] > Dist[i][k] + Dist[k][j])
					Dist[i][j] = Dist[i][k] + Dist[k][j];
							
	int min = INF;
	for(int i=0; i<V; i++)
	{
		if(min > Dist[i][i])
			min = Dist[i][i];
	}
	printf("%d",min!=INF?min:-1);	
	
	return 0;
}
