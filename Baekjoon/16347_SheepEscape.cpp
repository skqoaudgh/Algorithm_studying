#include <cstdio>
#include <vector>
using namespace std;

long long int arr[123457],ans[123457];
vector<int> adj[123457];
bool visited[123457]; 
char type[123457];
long long int dfs(int parent)
{
	long long int  a = 0;
	for(int next: adj[parent])
		a += dfs(next);
		
	if(type[parent] == 'S')
		return a + arr[parent];
	else
		return (a-arr[parent]>=0)?a-arr[parent]:0;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=2; i<=N; i++)
	{
		int p;
		scanf(" %c %lld %d",&type[i],&arr[i],&p);
		adj[p].push_back(i);
	}
	
	printf("%lld",dfs(1));
	return 0;
}
