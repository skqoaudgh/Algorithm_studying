#include <stdio.h>
using namespace std;

int main()
{
	long long int N, sum=0;
	scanf("%lld",&N);
	for(int i=1; i<N; i++)
		sum += (N*i + i);
	printf("%lld",sum);
	return 0;
} 
