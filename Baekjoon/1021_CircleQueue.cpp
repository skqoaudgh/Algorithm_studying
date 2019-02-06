#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N,M,cnt=0;
	vector<int> arr;
	
	scanf("%d %d",&N,&M);
	for(int i=1; i<=N; i++)
		arr.push_back(i);
	
	for(int t=0; t<M; t++)
	{
		int num;
		scanf("%d",&num);
		for(int i=0; i<N; i++)
		{
			if(arr[i] == num)
			{
				cnt += min(i,N-i);
				rotate(arr.begin(), arr.begin() + i + 1, arr.end() - t);
				break;
			}
		}
		N --;	
	}
	printf("%d",cnt);
	return 0;
}
