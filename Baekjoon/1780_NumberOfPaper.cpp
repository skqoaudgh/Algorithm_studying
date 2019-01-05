#include <stdio.h>

int arr[2188][2188];
int ans[3];
int N;

int check(int x, int y, int depth)
{
	int initial_value = arr[x][y];
	for(int i=0; i<depth; i++)
	{
		for(int j=0; j<depth; j++)
		{
			int nx = x+i;
			int ny = y+j;
			if(arr[nx][ny] != initial_value)
			{
				for(int p=x; p<x+depth; p+=depth/3)
					for(int q=y; q<y+depth; q+=depth/3)
						check(p,q,depth/3);
				return 1;
			}
			else if(nx==x+depth-1 && ny==y+depth-1 && arr[nx][ny] == initial_value)
			{
				if(initial_value == -1)
					ans[0] ++;	
				else if(initial_value == 0)
					ans[1] ++;	
				else
					ans[2] ++;	
			}
		}
	}
}

int main()
{
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d",&arr[i][j]);
	
	check(0,0,N);
	printf("%d\n%d\n%d",ans[0],ans[1],ans[2]);
	return 0;
}
