#include <stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a < b-c)
			printf("advertise\n");
		else if(a == b-c)
			printf("does not matter\n");
		else
			printf("do not advertise\n");
	}
	return 0;
}
