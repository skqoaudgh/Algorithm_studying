#include <stdio.h>
using namespace std;

int main()
{
	int N;
	int arr[50];
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&arr[i]);
		
	int left = 1;
	int max_height = arr[0];
	for(int i=1; i<N; i++)
	{
		if(max_height < arr[i])
		{
			left ++;
			max_height = arr[i];	
		}	
	} 
	int right = 1;
	max_height = arr[N-1];
	for(int i=N-2; i>=0; i--)
	{
		if(max_height < arr[i])
		{
			right ++;
			max_height = arr[i];	
		}	
	} 
	printf("%d\n%d",left,right);	
	return 0;
}
