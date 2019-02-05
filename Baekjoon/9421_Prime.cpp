#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define MAX 1000000
bool isPrime[MAX];

int func(int num)
{
	int result = 0;
	int temp = num;
	while(temp > 0)
	{
		result += (temp%10)*(temp%10);
		temp /= 10;
	}
	//printf("num:%d res:%d\n",num,result);
	return result;
}

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
	int n,idx,len=Prime.size();
	scanf("%d",&n);
	for(int i=0; i<len; i++)
	{
		if(n < Prime[i]) break;
		idx = i;
	}
	
	for(int i=0; i<=idx; i++)
	{
		int num = Prime[i];
		set<int> Set;
		pair<set<int>::iterator, bool> pr;
		bool flag = false;
		//printf("new prime\n");
		while(!flag)
		{
			num = func(num);
			if(num == 1)
			{
				printf("%d\n",Prime[i]);
				break;
			}
			pr = Set.insert(num);
			if(pr.second == false)
				flag = true;
		}
	}
	return 0;
}
