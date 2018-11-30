#include <iostream>
using namespace std;

int arr[1001][1001];

int main()
{
			
	int N,M,X;
	scanf("%d %d %d",&N,&M,&X);
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			arr[i][j] = (i==j)?0:987654321;
			
	for(int i=0; i<M; i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		arr[a][b] = c;
	}

	for(int k=1; k<=N; k++)
		for(int i=1; i<=N; i++)
		{
			if(arr[i][k] != 987654321)
			{
				for(int j=1; j<=N; j++)
				{
					if(i==j||i==k||j==k) continue;
					if(arr[i][k] == 987654321 || arr[k][j] == 987654321) continue;
					if(arr[i][j] > arr[i][k] + arr[k][j])
						arr[i][j] = arr[i][k] + arr[k][j];
				}				
			}
		}
			
						
	int ans = 0;
	for(int i=1; i<=N; i++)
		if(ans < arr[i][X]+arr[X][i])
			ans = arr[i][X]+arr[X][i];

						
	printf("%d",ans);
	return 0;
}
