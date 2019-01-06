#include <stdio.h>
#include <algorithm>
using namespace std;
 
long long int arr[100002];

int binarySearch(int left, int right, long long int val)
{
	while(left < right)
	{
		int mid = (left+right)/2;
		if(arr[mid] < val)
			left = mid+1;
		else
			right = mid;
	}
	return right;
}

int main(void) 
{
	long long int N,M;
	scanf("%lld %lld",&N,&M);
	for(int i=0; i<N; i++)
		scanf("%lld",&arr[i]);
	sort(arr,arr+N);
	
	long long int min = 9876543210;
	for(int i=0; i<N; i++)
	{
		int index = binarySearch(0,N,arr[i]+M);
		for(int t=0; t<2; t++)
		{
			if(i == index-t || index-t >= N) continue;
			long long int val = abs(arr[index-t]-arr[i]);
			//printf("%lld %lld\n",arr[index-t], arr[i]);
			if(index-t >= 0 && min > val && val >= M)
				min = val;			
		}
	}
	printf("%lld",min);
    return 0;
}
