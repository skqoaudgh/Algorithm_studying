#include <stdio.h>

int main()
{
	long long int A,B,C;
	scanf("%lld %lld %lld",&A,&B,&C);
	
	long long int ans = 0;
	
	if(A == 0)
	{
		if(B < C)
			ans = 1;
		else
			ans = -1;
	}
	else
	{
		if(B < C)
		{
			ans = A/(C-B)+1;		
		}
		else
		{
			ans = -1;
		}
	}
	printf("%lld",ans);
	return 0;
}
