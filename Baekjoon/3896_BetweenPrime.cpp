#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1299709
bool isPrime[MAX];
int main()
{
	vector<int> Prime;
	fill(isPrime+2,isPrime+MAX,true);
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i=2; i<MAX; i++)
	{
		if(isPrime[i])
		{
			Prime.push_back(i);
			for(int j=i*2; j<MAX; j+=i)
				isPrime[j] = false;			
		}
	}
	//-----
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int K;		
		scanf("%d",&K);
		if(!isPrime[K])
		{
			int min_idx,max_idx;
			for(int i=0; i<Prime.size(); i++)
			{
				if(K < Prime[i]) break;
				min_idx = i;
			}
			for(int i=Prime.size()-1; i>=0; i--)
			{
				if(K > Prime[i]) break;
				max_idx = i;
			}
						
			printf("%d\n",Prime[max_idx]-Prime[min_idx]);	
		}
		else
			printf("0\n");
	}
	return 0;
}
