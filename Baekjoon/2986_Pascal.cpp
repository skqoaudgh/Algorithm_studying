#include <cstdio>

int main()
{
	int N,k=1,sum=0;
	scanf("%d",&N);
	
	for(int i=2; i*i<=N; i++)
	{
		if(N % i == 0)
		{
			k = N/i;
			break;
		}	
	}
	printf("%d",N-k);
	return 0;
}
