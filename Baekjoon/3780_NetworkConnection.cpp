#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 20001
typedef pair<int,int> P;

int p[MAX];
int dist[MAX];

P find(int a)
{
	if(p[a] == a) return P(a,a);
	P get = find(p[a]);
	
	int root = get.first;
	int parent = get.second;
	
	dist[a] += dist[parent]; // 과거 루트까지의 거리 + 내 부모와 루트까지의 거리 
	p[a] = root;
	
	return P(root,a);	
}

void merge(int a, int b)
{
	p[a] = b;
	dist[a] = abs(a-b)%1000;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		scanf("%d",&N);
		for(int i=1; i<=N; i++)
			p[i] = i;
		fill(dist,dist+N,0);
		while(1)
		{
			char oper;
			scanf("%c",&oper);
			if(oper == 'E')
			{
				int a;
				scanf("%d",&a);
				find(a);
				printf("%d\n",dist[a]);
			}
			else if(oper == 'I')
			{
				int a,b;
				scanf("%d %d",&a,&b);
				merge(a,b);
			}
			else if(oper == 'O')
				break;
		}
	}
	return 0;
}
