#include <cstdio>
#include <cstring>
#include <cmath>

int tree[12][1025];
int arr[1025];
int depth_idx[11] = {0,};

void Building(int start, int end, int depth)
{
	if(start > end) return;
	int mid = (start+end)/2;
	tree[depth][depth_idx[depth]++] = arr[mid];
	Building(start,mid-1,depth+1);
	Building(mid+1,end,depth+1);
}

int main()
{
	int K,P=1;
	scanf("%d",&K);
	for(int i=0; i<K; i++)
		P *= 2;
		
	for(int i=0; i<P-1; i++)
		scanf("%d",&arr[i]);
	Building(0,P-1,0);
	
	for(int i=0; i<K; i++)
	{
		P = 1;
		for(int j=0; j<i; j++)
			P *= 2;
		for(int j=0; j<P; j++)
			printf("%d ",tree[i][j]);
		printf("\n");
	}
	
	return 0;
}
