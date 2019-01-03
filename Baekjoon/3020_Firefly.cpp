#include <stdio.h>
#include <algorithm>
using namespace std;

int up[100001];
int down[100001];
int N,H;

int binarysearch(int arr[], int val)
{
	int left = 0;
	int right = (N/2)-1;
	while(left <= right)
	{
		int mid = (left+right)/2;
		if(arr[mid] >= val) 
			right = mid-1;
		else
			left = mid+1;
	}
	return (N/2)-left;
}

int main()
{
	scanf("%d %d",&N,&H);
	for(int i=0; i<N/2; i++)
	{
		scanf("%d",&up[i]);
		scanf("%d",&down[i]);
	}
	sort(up,up+N/2);
	sort(down,down+N/2);
	int val = 987654321;
	int cnt = 1;
	for(int i=1; i<=H; i++)
	{
		int temp = binarysearch(up,i) + binarysearch(down,H-i+1);
		if(temp == val)
			cnt ++;
		else if (temp < val)
		{
			cnt = 1;
			val = temp;
		}
	}
	printf("%d %d",val,cnt);
}
