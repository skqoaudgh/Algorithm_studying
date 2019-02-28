#include <cstdio>
using namespace std;

long long int gcd(long long int a, long long int  b)
{
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);	
}

int main()
{
	long long int a,b,s;
	scanf("%lld %lld %lld",&a,&b,&s);
	
	if(a+b == s)
		printf("YES\n");
	else if(a+b > s)
		printf("NO\n");
	else
	{
		bool flag = false;
		long long int na = a;
		long long int nb = b;
		while(a+b < s)
		{
			na += a;
			nb += b;
			//s -= (a+b);
			//printf("s:%d gcd:%d\n",s,gcd(na,nb));
			if(s%gcd(na,nb) == 0)
			{
				flag = true;
				break;
			}	
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO");
	}

	return 0;
}
