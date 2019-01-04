#include <stdio.h>
using namespace std;

int sum[100001];
int arr[100001];

int main()
{
	int N,M;
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
	{
		scanf("%d",&arr[i]);
		sum[i] += sum[i-1] + arr[i];	
	}
	scanf("%d",&M);
	for(int i=1; i<=M; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",sum[b]-sum[a-1]);
	}
	return 0;
} 
