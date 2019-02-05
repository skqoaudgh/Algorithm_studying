#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000000
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
	while(1)
	{
		int K;		
		scanf("%d",&K);
		if(K == 0) break;
		
		for(int i=0; i<Prime.size(); i++)
		{
			if(isPrime[K-Prime[i]])
			{
				printf("%d = %d + %d\n",K,Prime[i],K-Prime[i]);
				break;
			}
		}
	}
	return 0;
}
