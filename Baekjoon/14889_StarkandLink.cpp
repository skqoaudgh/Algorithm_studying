#include <iostream>
#include <math.h>
using namespace std;

int arr[21][21];
bool visited[21];
int ans = 987654321;
int N;

void func(int index, int cnt)
{
	if(index >= N) return;
	if(cnt == N/2)
	{
		int sum = 0;
		int sum2 = 0;		
		for(int i=0; i<N; i++)
		{
			if(visited[i])
			{
				for(int j=0; j<N; j++)
					if(visited[j])
						sum += arr[i][j];			
			}
			else
				for(int j=0; j<N; j++)
					if(!visited[j])
						sum2 += arr[i][j];
		}
		int val = abs(sum-sum2);
		if(ans > val)
			ans = val;
		return;
	}
	visited[index] = true;
	func(index+1,cnt+1);
	visited[index] = false;
	func(index+1,cnt);
}

int main()
{
	cin >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> arr[i][j];
	
	func(0,0);
	cout << ans;
	return 0;
}
