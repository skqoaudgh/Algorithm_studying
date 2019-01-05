#include <stdio.h>

int main()
{
	int N,K,cnt=0;
	bool checked[1001] = {false,};
	scanf("%d %d",&N,&K);
	
	for(int i=2; i<=N; i++)
	{
		for(int j=i; j<=N; j+=i)
		{
			if(!checked[j])
			{
				cnt ++;
				checked[j] = true;
				if(cnt == K)
				{
					printf("%d",j);
					return 0;
				}				
			}
		}
	}
	return 0;
}
