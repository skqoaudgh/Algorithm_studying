#include <iostream>
using namespace std;

int N;
char arr[101][101];
bool visited[101][101];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

struct NODE {
	int x, y;
	char w;
	NODE(int X, int Y, char W) {x=X;y=Y;w=W;};
};

void func(NODE t, bool type)
{
	visited[t.x][t.y] = true;
	for(int i=0; i<4; i++)
	{
		int nx = t.x+dx[i];
		int ny = t.y+dy[i];
		if(nx<0 || ny<0 || nx>=N || ny>=N) continue;
		if(visited[nx][ny]) continue;
		if(type)
		{
			if(t.w == 'B' && t.w != arr[nx][ny]) continue;
			else if((t.w == 'R' || t.w == 'G') && arr[nx][ny] == 'B') continue;
		}
		else
			if(t.w != arr[nx][ny]) continue;
		func(NODE(nx,ny,arr[nx][ny]),type);
	}
}

// »¡,ÃÊ ÆÄ 
int main()
{	
	cin >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> arr[i][j];
		
	int cnt_y = 0;	
	int cnt_n = 0;	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			if(!visited[i][j])
			{
				func(NODE(i,j,arr[i][j]),false);
				cnt_n ++;
			}			
		}
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			visited[i][j] = false;	

	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			if(!visited[i][j])
			{
				func(NODE(i,j,arr[i][j]),true);
				cnt_y ++;
			}			
		}
	
	cout << cnt_n << ' ' << cnt_y;	
	return 0;
}
