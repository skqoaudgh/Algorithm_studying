#include <cstdio>
using namespace std;

int main()
{
	int n,m,max=0;
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++)
	{
		int in, out;
		scanf("%d %d",&in,&out);
		m += (in-out);
		if(m > max)
			max = m;
		if(m < 0)
		{
			max = 0;
			break;
		}
	}
	printf("%d",max);
	return 0;
}
