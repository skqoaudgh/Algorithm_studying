#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[500001];
int main(void) 
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+N);
	long long int sum = 0;
	for(int i=0; i<N; i++)
		sum += (long long int)abs(i+1-arr[i]);
	printf("%lld",sum);
    return 0;
}
