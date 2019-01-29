#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int N,arr[200][3],sum[200];
	scanf("%d",&N);
	fill(sum,sum+N,0);
	
	for(int i=0; i<N; i++)
		for(int j=0; j<3; j++)
			scanf("%d",&arr[i][j]);
	

	for(int i=1; i<=100; i++)
	{
		for(int t=0; t<3; t++)
		{		
			int target = -1;
			int cnt = 0;
			for(int j=0; j<N; j++)
			{
				if(i == arr[j][t])
				{
					cnt ++;
					target = j;
				}
			}
			if(cnt == 1)
				sum[target] += arr[target][t];
		}
	}
	
	for(int i=0; i<N; i++)
		printf("%d\n",sum[i]);
	return 0;
}
