#include <cstdio>
#include <map>
using namespace std;

map<long long, long long> visited;

int main()
{
	int N;
	scanf("%d",&N);
	if(N == 1)
	{
		printf("1\n");
		return 0;
	}
	long long sum = 0;
	visited[1] = 1;
	sum += visited[1];
	for(long long i=2; i<=N; i++)
	{
		visited[i] = 1 + visited[i-visited[visited[i-1]]];
		sum += visited[i];
		
		if(sum >= N)
		{
			printf("%d\n",i);
			break;
		}
	}
    return 0;
}


