#include <stdio.h>
using namespace std;

long long int arr[51];

int main()
{
	int N,G,P;
	int rank = 1;
	int array_count = 1;
	scanf("%d %d %d",&N,&G,&P);
	for(int i=0; i<N; i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i] > G) rank ++;
		if(arr[i] >= G) array_count ++;
	}
	if(rank > P)
		printf("-1");
	else if(array_count > P)
		printf("-1");
	else
		printf("%d",rank);
	return 0;
}
