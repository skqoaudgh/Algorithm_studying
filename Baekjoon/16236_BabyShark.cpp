#include <stdio.h>
#include <math.h>
using namespace std;

int N;
int arr[21][21];
bool visited[21][21];

int ans = 0;
bool flag = false;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int sx, int sy, int size, int eat, int second)
{
	if(eat > 0 && flag && ans < second)
	{
		printf("%d %d 에서 ans 변경:%d->%d\n",sx,sy,ans,second);
		ans = second;
		flag = false;
	}
		
	for(int i=0; i<4; i++)
	{
		int nx = sx+dx[i];
		int ny = sy+dy[i];
		int neat = eat;
		if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if(visited[nx][ny]) continue;
		if(arr[nx][ny] > size) continue;
		printf("nx:%d ny:%d arr[nx][ny]:%d size:%d\n",nx,ny,arr[nx][ny],size);
		if(arr[nx][ny] > 0 && arr[ny][ny] < 9 && arr[nx][ny] < size)
		{
			arr[nx][ny] = 0;
			neat ++;
			flag = true;
			printf("new neat:%d size:%d\n",neat,size);
		}
		if(neat == size)
		{
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					visited[i][j] = false;
			printf("1dfs\n");
			visited[nx][ny] = true;
			dfs(nx,ny,size+1,0,second+1);
			visited[nx][ny] = false;
		}	
		else
		{
			printf("2dfs\n",neat);
			visited[nx][ny] = true;
			dfs(nx,ny,size,neat,second+1);
			visited[nx][ny] = false;
		}
			
	}
}

int main()
{
	int shark_pos[2];
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j] == 9)
			{
				shark_pos[0] = i;
				shark_pos[1] = j;
			}
		}
	}
	dfs(shark_pos[0],shark_pos[1],2,0,0);
	printf("%d",ans);
	return 0;
}
