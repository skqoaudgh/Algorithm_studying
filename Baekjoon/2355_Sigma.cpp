#include <stdio.h>

int main() 
{
	long long a,b;
	scanf("%lld %lld",&a,&b);
	if(a>=b)
		printf("%lld",(a-b+1)*(a+b)/2);
	else
		printf("%lld",(b-a+1)*(a+b)/2);
    return 0;
}
