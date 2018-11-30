#include <iostream>
using namespace std;

int arr[101][101];
int main()
{
	int N,M;
	cin >> N >> M;
			
	for(int i=0; i<M; i++)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b] = 1; // a가 b보다 무겁다.	
	}
			
	for(int k=1; k<=N; k++)
		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				if(arr[i][k] == 1 && arr[k][j] == 1)
					arr[i][j] = 1;
			
	for(int i=1; i<=N; i++)
	{
		int cnt = 0;
		for(int j=1; j<=N; j++)
		{
			if(i==j)  continue;
			if(arr[i][j] == 0 && arr[j][i] == 0)
				cnt ++;
		}
		cout << cnt << '\n';
	}
    return 0;
}
