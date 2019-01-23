#include <stdio.h>
#include <math.h>

int main()
{
	int N,W,H;
	scanf("%d %d %d",&N,&W,&H);
	int max = sqrt(W*W+H*H);
	for(int i=0; i<N; i++)
	{
		int a;
		scanf("%d",&a);
		if(a<=max)
			printf("DA\n");
		else
			printf("NE\n");
	}
	return 0;
}
