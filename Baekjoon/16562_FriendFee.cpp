#include <cstdio>
#include <algorithm>
using namespace std;

#define INF	987654321
#define MAX 10001

int p[MAX];
int A[MAX];
int minz[MAX];
bool visited[MAX];
int find(int a)
{
	if(p[a] < 1) return a;
	p[a] = find(p[a]);
	return p[a];	
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a == b) return;
	if(minz[a] > minz[b])
	{
		p[a] = b;
		minz[a] = INF;
	}
	else
	{
		p[b] = a;
		minz[b] = INF;
	}
}

int main()
{
	int N,M,K;
	long long int ans=0;
	scanf("%d %d %d",&N,&M,&K);
	fill(p,p+MAX,0);
	fill(minz,minz+MAX,INF);
	for(int i=1; i<=N; i++)
		scanf("%d",&A[i]);
	for(int i=0; i<M; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		visited[a] = true;
		visited[b] = true;
		merge(a,b);
		
		int min_idx = A[a] < A[b] ? a : b;
		int root = find(min_idx);
		if(minz[root] > A[min_idx])
		{
			minz[root] = A[min_idx];
			//printf("debug: %d번의 최소값이 %d로 바낌\n",root, A[min_idx]);
		}
	}

	for(int i=1; i<=N; i++)
	{
		if(minz[i] != INF)
		{
			ans += minz[i];
			//printf("debug: %d의 최소값 더함\n",i);
		}
		if(!visited[i])
			ans += A[i];
	}
			
	if(ans <= K)
		printf("%lld",ans);
	else
		printf("Oh no");
	return 0;
}
