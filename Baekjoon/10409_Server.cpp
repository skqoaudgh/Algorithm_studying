#include <stdio.h>

int main()
{
	int n,T,sum=0,idx;
	int arr[50];
	scanf("%d %d",&n,&T);
	for(int i=0; i<n; i++)
		scanf("%d",&arr[i]);
	
	for(int i=0; i<n; i++)
	{
		sum += arr[i];
		idx = i;
		if(sum > T)
			break;
	}
	if(sum <= T)
		idx ++;
		
	printf("%d",idx);
	return 0;
}
