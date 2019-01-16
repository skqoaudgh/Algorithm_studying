#include <stdio.h>
using namespace std;

int main()
{
	int N,K = 1,ans=0;
	scanf("%d",&N);
	while(N > 0)
	{
		if(N < K)
			K = 1;
		N -= K;
		K ++;
		ans ++;
	}
	printf("%d",ans);
	return 0;
}
