#include <stdio.h>
using namespace std;

int count = 0;
long long int arr[500001];
long long int temp[500001];

long long int mergesort(int left, int right)
{
	if(left == right) return 0;
	int mid = (left+right)/2;
	long long int ans = mergesort(left,mid) + mergesort(mid+1,right);
	
	int i=left,j=mid+1,t=0;
	while(i<=mid || j<=right)
	{
		if(i <= mid && (j>right || arr[i] <= arr[j]))
			temp[t++] = arr[i++];
		else
		{
			ans += (long long)(mid-i+1);
			temp[t++] = arr[j++];
		}
			
	}
	for(int i=left; i<=right; i++)
		arr[i] = temp[i-left];
	return ans;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&arr[i]);
	
	long long int ans = mergesort(0,N-1);
	printf("%lld",ans);
	return 0;
}
