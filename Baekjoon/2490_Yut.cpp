#include <cstdio>

int main()
{
	for(int t=0; t<3; t++)
	{
		int cnt = 0;
		for(int i=0; i<4; i++)
		{
			int a;
			scanf("%d",&a);
			if(a == 0)
				cnt ++;
		}
		switch(cnt)
		{
			case 0: printf("E\n"); break;
			case 1: printf("A\n"); break;
			case 2: printf("B\n"); break;
			case 3: printf("C\n"); break;
			case 4: printf("D\n"); break;
		}
	}	 
	return 0;
}
