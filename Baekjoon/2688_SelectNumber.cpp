#include <iostream>
using namespace std;

int arr[101];
int visited[101];
int cnt = 0;

void dfs(int index)
{	
	if(visited[index] == 2)  {
		return;
	}
	visited[index] ++;
	dfs(arr[index]);
}

int main()
{
	int N;
	cin >> N;
	for(int i=1; i<=N; i++)
		cin >> arr[i];
		
	for(int i=1; i<=N; i++)
	{
		dfs(i);
		for(int j=1; j<=N; j++)
			if(visited[j] == 1)
				visited[j] = 0;
	}
		
	
	for(int i=1; i<=N; i++)
		if(visited[i] == 2)
			cnt ++;
			
	cout << cnt << '\n';
	for(int i=1; i<=N; i++)
		if(visited[i] == 2)
			cout << i << "\n";
	return 0;
}
