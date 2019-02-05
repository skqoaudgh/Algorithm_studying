#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 1000001
bool isPrime[MAX];

void func(long long int min, long long int max)
{
	for(long long int i=2; i*i<=max; i++)
	{
		long long int squ = i*i;
		long long int start = min/squ;
		if(start*squ != min) start ++;
		for(long long int j=start; squ*j<=max; j++)
			isPrime[squ*j-min] = true;
	}
}
int main()
{
	long long int min,max,ans=0;
	scanf("%lld %lld",&min,&max);
	func(min,max);
	
	for(int i=0; i<max-min+1; i++)
		if(!isPrime[i])
			ans ++;
	printf("%lld",ans);
	return 0;
}
