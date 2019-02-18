#include <cstdio>

int main()
{
	int N;
	scanf("%d",&N);
	int i;
	
	for (i=1; N>0; i++)
		N = N - i;
		
	if (i%2 == 1)
		printf("%d/%d",i+N-1,1-N);
	else if (i % 2 == 0)
		printf("%d/%d",1-N,i+N-1);
}
