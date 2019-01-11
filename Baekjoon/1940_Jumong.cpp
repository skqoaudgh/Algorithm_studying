#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[10000000];
int visited[10000000];
int search(int left, int right, int val)
{
	while(left < right)
	{
		int mid = (left+right)/2;
		if(arr[mid] <  val)
			left = mid+1;
		else if(arr[mid] >= val)
			right = mid;	
	}
	return right;
}

int main()
{
	int N,M,ans=0;
	scanf("%d %d",&N,&M);
	for(int i=0; i<N; i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+N);
	
	for(int i=0; i<N; i++)
	{
		int index = search(0,N-1,M-arr[i]);
		if(arr[i] + arr[index] == M && !visited[index] && i != index)
		{
			ans ++;
			visited[index] = true;
			visited[i] = true;
		}
	}
	printf("%d",ans);
	return 0;
}
