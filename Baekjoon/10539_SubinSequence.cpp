#include <cstdio>

int main()
{
	int N,arr[101] = {0};
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
	{
		scanf("%d",&arr[i]);
		arr[i] *= i;
	}

	for(int i=1; i<=N; i++)
		printf("%d ",arr[i]-arr[i-1]);
	return 0;
}
