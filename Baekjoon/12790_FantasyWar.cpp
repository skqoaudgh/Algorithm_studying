#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int armed[8],sum=0;
		for(int i=0; i<8; i++)
		{
			scanf("%d",&armed[i]);
			if(i >= 4)
			{
				armed[i-4] += armed[i];
				if(i == 4 || i == 5)
					if(armed[i-4] < 1)
						armed[i-4] = 1;
				if(i == 6)
					if(armed[i-4] < 0)
						armed[i-4] = 0;
			}
		}
		sum = armed[0] + armed[1]*5 + armed[2]*2 + armed[3]*2;
		printf("%d\n",sum);
	}
	return 0;
}
