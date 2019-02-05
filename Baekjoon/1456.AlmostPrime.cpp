#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define MAX 10000000
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
	long long int A,B,ans=0;
	scanf("%lld %lld",&A,&B);
	for(int i=0; i<Prime.size(); i++)
	{
		long long int num = Prime[i];
		while(Prime[i] <= B / num)
		{
            if(Prime[i] * num >= A)
            	ans++;
            num *= Prime[i];	
		}
	}
	printf("%d",ans);
	return 0;
}
