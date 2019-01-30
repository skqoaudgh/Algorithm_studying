#include <cstdio>

int dx[] = {-1,1,0,0,-1,-1,1,1};
int dy[] = {0,0,-1,1,-1,1,-1,1};

int w,h;
int arr[51][51];
bool visited[51][51];

void dfs(int i, int j)
{
	visited[i][j] = true;
	for(int t=0; t<8; t++)
	{
		int nx = i + dx[t];
		int ny = j + dy[t];
		if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
		if(arr[nx][ny] == 1 && !visited[nx][ny])
			dfs(nx,ny);
	}	
}

int main()
{
	while(1)
	{
		scanf("%d %d",&w,&h);
		if(w == 0 && h == 0) break;

		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
			{
				visited[i][j] = false;	
				arr[i][j] = 0;
			}
				
		int cnt = 0;
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				scanf("%d",&arr[i][j]);
				
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				if(arr[i][j] == 1 && !visited[i][j])
				{
					dfs(i,j);
					cnt ++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
