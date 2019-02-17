#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000000];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+N);
	
	bool flag = false;
	int ans = 0;
	for(int i=N-1; i>=2; i--)
	{
		int p = i-1, q = i-2;

		
		//printf("debug: arr[%d]:%d = arr[%d]:%d + arr[%d]:%d\n",i,arr[i],p,arr[p],q,arr[q]);
		if(arr[i] < arr[p] + arr[q])
		{
			if(ans < arr[i]+arr[p]+arr[q])
				ans = arr[i]+arr[p]+arr[q];
			flag = true;
			break;
		}
	}
	if(!flag)
		printf("-1");
	else
		printf("%d",ans);
	return 0;
}
