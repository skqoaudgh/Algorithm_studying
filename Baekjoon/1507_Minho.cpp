#include <stdio.h>
using namespace std;

#define MAX 20
int main()
{
	int N;
	int dist[MAX][MAX];
	bool cut[MAX][MAX]={false};
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d",&dist[i][j]);

	int ans = 0;
	bool flag = false;
	for(int t=0; t<N; t++)
		for(int i=0; i<N; i++)
			for(int j=i+1; j<N; j++)
			{
				if(i == t || j == t) continue;
				if(dist[i][j] > dist[i][t] + dist[t][j])
					flag = true;
				if(dist[i][j] == dist[i][t] + dist[t][j])
					cut[i][j] = true;		
			}

	if(flag)
		printf("-1");
	else
	{
		for(int i=0; i<N; i++)
			for(int j=i+1; j<N; j++)
				if(!cut[i][j])
					ans += dist[i][j];	
		printf("%d",ans);
	}
	return 0;
}
