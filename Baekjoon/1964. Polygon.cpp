#include <stdio.h>

long long int arr[10000001];

int main() 
{
	int N;
	scanf("%d",&N);
	
	arr[0] = 1;
	for(int i=1; i<=N; i++)
		arr[i] = arr[i-1]%45678+3*i+1;
	printf("%lld",arr[N]%45678);
    return 0;
}

