#include <stdio.h>
using namespace std;

int main()
{
	int arr[5];
	for(int i=0; i<5; i++)
		scanf("%d",&arr[i]);
	
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<4; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				for(int t=0; t<5; t++)
					printf("%d ",arr[t]);
				printf("\n");
			}
		}
	}
	return 0;
}
