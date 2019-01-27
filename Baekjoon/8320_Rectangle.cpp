#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int n,ans=0;
	scanf("%d",&n);
	
	for(int i=1; i<=sqrt(n); i++)
	{
		int j = i;
		while(1)
		{
			if(i*j <= n)
			{
				ans ++;
			}
			else
				break;
			j++;
		}
	}
	printf("%d",ans);
	return 0;
}
