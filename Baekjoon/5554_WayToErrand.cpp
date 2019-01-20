#include <stdio.h>

int main()
{
	int time, sec=0, min=0;
	for(int i=0; i<4; i++)
	{
		scanf("%d",&time);
		sec += time;
		if(sec >= 60)
		{	
			while(sec >= 60)
			{
				sec -= 60;
				min ++;
			}
		}
	}
	printf("%d\n%d",min,sec);
	return 0;
}
