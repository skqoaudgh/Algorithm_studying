#include <cstdio>
#include <vector>
using namespace std;
 
long long int f[21];
bool check[21];

int main()
{
	int N,type;
	scanf("%d",&N);
	
	f[0] = 1;
	for(int i=1; i<21; i++)
		f[i] = f[i-1]*i;
	
	scanf("%d",&type);
	if(type == 2) // 순열 제시 
	{
		vector<int> arr(N);
		
		for(int i=0; i<N; i++)
			scanf("%d",&arr[i]);
		
		long long int ans = 0;
		for(int i=0; i<N; i++)
		{
			for(int j=1; j<arr[i]; j++)
			{
				if(!check[j])
					ans += f[N-i-1];
			}
			check[arr[i]] = true;
		}
		printf("%lld\n",ans+1);
	}
	else // K 제시 
	{
		long long int K;
		scanf("%lld",&K);
		vector<int> arr(N);
		for(int i=0; i<N; i++)
		{
			for(int j=1; j<=N; j++)
			{
				if(check[j]) continue;
				if(f[N-i-1] < K)
					K -= f[N-i-1];
				else
				{
					arr[i] = j;
					check[j] = true;
					break;
				}
			}
		}
		
		for(int i=0; i<N; i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
	return 0;
}
