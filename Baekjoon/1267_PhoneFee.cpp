#include <stdio.h>

int arr[21];
int fee[2];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		scanf("%d",&arr[i]);
		fee[0] += (10 + arr[i]/30*10);
		fee[1] += (15 + arr[i]/60*15);
	}
	if(fee[0] > fee[1])
		printf("M %d",fee[1]);
	else if(fee[0] < fee[1])
		printf("Y %d",fee[0]);
	else
		printf("Y M %d",fee[0]);
	return 0;
}
