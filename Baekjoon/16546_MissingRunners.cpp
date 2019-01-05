#include <stdio.h>
int arr[32769];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N-1; i++)
	{
		int a;
		scanf("%d",&a);
		arr[a]++;
	}
	for(int i=1; i<32769; i++)
		if(arr[i] == 0)
		{
			printf("%d",i);
			break;
		}		
	return 0;
}
