#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 300001

int p[MAX];
bool visited[MAX];

int find(int a)
{
	if(p[a] == a) return a;
	p[a] = find(p[a]);
	return p[a];	
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	p[a] = b;
	printf("LADICA\n");
}

int main()
{
	int N,L;
	scanf("%d %d",&N,&L);
	for(int i=1; i<=L; i++)
		p[i] = i;
	for(int i=1; i<=N; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		
		int rootA = find(p[a]);
		int rootB = find(p[b]);
		if(!visited[a])
		{
			visited[a] = true;
			merge(a,b);
		}
		else if(!visited[b])
		{
			visited[b] = true;
			merge(b,a);
		}
		else if(!visited[rootA])
		{
			visited[rootA] = true;
			merge(a,b);			
		}
		else if(!visited[rootB])
		{
			visited[rootB] = true;
			merge(b,a);
		}	
		else
			printf("SMECE\n");
	}
	return 0;
}
