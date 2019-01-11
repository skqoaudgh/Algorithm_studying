#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int arr[3];
	int dist[2];
	scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
	
	sort(arr,arr+3);
	dist[0] = arr[1]-arr[0];
	dist[1] = arr[2]-arr[1];
	
	if(dist[0] == dist[1])
		printf("%d",arr[2]+dist[0]);
	else if(dist[0] > dist[1])
		printf("%d",arr[0]+dist[1]);
	else
		printf("%d",arr[1]+dist[0]);
	return 0;
}
