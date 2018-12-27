#include <stdio.h>
#include <algorithm>
using namespace std;

int deck[500001];

bool binarySearch(int arr[], int size, int val)
{
	int left = 0;
	int right = size-1;
	int mid;
	while(left <= right)
	{
		mid = (left+right)/2;
		if(arr[mid] == val)
			return true;
		else if(arr[mid] > val)
			right = mid-1;
		else
			left = mid+1;
	}
	return false;
}

int main()
{

	int N,M;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&deck[i]);
	sort(deck,deck+N);
	scanf("%d",&M);
	for(int i=0; i<M; i++)
	{
		int a;
		scanf("%d",&a);
		bool flag = binarySearch(deck,N,a);
		if(flag)
			printf("1 ");
		else
			printf("0 ");
	}
	return 0;
}

