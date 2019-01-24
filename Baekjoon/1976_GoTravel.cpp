#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 200

int p[MAX];

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
	if(a == b) return;
	p[b] = a;
}

int main()
{
	int N,M,arr[1000];
	scanf("%d %d",&N,&M);
	
	for(int i=0; i<N; i++)
		p[i] = i;

	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			int a;
			scanf("%d",&a);
			if(a == 1)
				merge(i,j);			
		}
	}
	for(int i=0; i<M; i++)
		scanf("%d",&arr[i]);
	
	bool flag = false;
	int idx = find(arr[0]);
	for(int i=1; i<M; i++)
	{	
		if(idx != find(arr[i]))
		{
			flag = true;
			break;
		}
	}
	if(flag)
		printf("NO");
	else
		printf("YES");
	return 0;
}
