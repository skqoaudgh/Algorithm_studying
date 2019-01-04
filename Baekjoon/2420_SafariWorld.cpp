#include <stdio.h>
using namespace std;

long long int abs(long long int a)
{
	if(a < 0)
		return -a;
	return a;
}

int main()
{
	long long int N,M;
	scanf("%lld %lld",&N,&M);
	printf("%lld",abs(N-M));
	return 0;
} 
