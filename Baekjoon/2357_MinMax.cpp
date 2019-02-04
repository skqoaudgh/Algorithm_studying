#include <cstdio>
#include <algorithm>
using namespace std;

int min_arr[2100000];
int max_arr[2100000];

void construct(int Size)
{
	for(int i=Size-1; i>0; i--)
	{
		min_arr[i] = min(min_arr[i*2] ,min_arr[i*2+1]);
		max_arr[i] = max(max_arr[i*2] ,max_arr[i*2+1]);
	}		
}

int getmin(int L, int R, int nodeNum, int nodeL, int nodeR)
{
    if(R < nodeL || nodeR < L) return 1000000001;
    if(L <= nodeL && nodeR <= R) return min_arr[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return min(getmin(L, R, nodeNum*2, nodeL, mid),getmin(L, R, nodeNum*2+1, mid+1, nodeR));
}

int getmax(int L, int R, int nodeNum, int nodeL, int nodeR)
{
    if(R < nodeL || nodeR < L) return 0;
    if(L <= nodeL && nodeR <= R) return max_arr[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return max(getmax(L, R, nodeNum*2, nodeL, mid),getmax(L, R, nodeNum*2+1, mid+1, nodeR));
}

int main() 
{
	int RN,N,M;
	scanf("%d %d",&N,&M);
	for(RN=1; RN<N; RN*=2);
	
	for(int i=0; i<RN*2; i++)
	{
		min_arr[i] = 1000000001;
		max_arr[i] = 1;
	}
	
	for(int i=0; i<N; i++)
	{
		int a;
		scanf("%d",&a);
		min_arr[i+RN] = a;
		max_arr[i+RN] = a;
	}
	construct(RN);

	for(int i=0; i<M; i++)
	{
		int b,c;
		scanf("%d %d",&b,&c);
		printf("%d %d\n",getmin(b-1, c-1, 1, 0, RN-1),getmax(b-1, c-1, 1, 0, RN-1));
	}
	return 0;
}
