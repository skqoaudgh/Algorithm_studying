#include <cstdio>

int E,S,M;

int func()
{
	int ans;
	int year = 1;
	while(1)
	{
		if((year-E)%15 == 0 && (year-S)%28 == 0 && (year-M)%19 == 0)
		{
			ans = year;
			break;	
		}	
		year ++;
	}	
	return ans;
}

int main()
{
	scanf("%d %d %d",&E,&S,&M);
	printf("%d",func()); 
	return 0;
}
