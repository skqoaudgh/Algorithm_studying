#include <cstdio>

int main()
{
	int N,arr[50][50];
	scanf("%d",&N);
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			if(i != j)
				arr[i][j] = 987654321;
			else
				arr[i][j] = 0;
		}
			
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			char ch;
			scanf(" %c",&ch);
			if(ch == 'Y')
				arr[i][j] = 1;
		}
	
	for(int t=0; t<N; t++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
			{
				if(arr[i][j] > arr[i][t] + arr[t][j])
					arr[i][j] = arr[i][t] + arr[t][j];
			}

	int max = 0;
	for(int i=0; i<N; i++)
	{
		int cnt = 0;
		for(int j=0; j<N; j++)
		{
			if(i == j) continue;
			if(arr[i][j] == 1 || arr[i][j] == 2)
				cnt ++;				
		}
		if(max < cnt)
			max = cnt;
	}
	printf("%d\n",max);
	return 0;
}
