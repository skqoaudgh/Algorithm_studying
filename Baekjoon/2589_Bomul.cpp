#include <iostream>
#include <queue>
using namespace std;

int N,M;
char arr[51][51];
bool visited[51][51];
int areaNum[51][51];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

struct NODE {
	int x, y, cnt,area;
	NODE(int X, int Y, int CNT, int AREA) {x=X;y=Y;cnt=CNT; area=AREA;};
};

int main()
{	
	cin >> N >> M;
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> arr[i][j];
	
	queue<NODE> q;
	
	int cnt = 0;
	int ans = 0;
	int index = 1;
	
	// 영역 구허기 
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
		{
			if(arr[i][j] == 'L' && !visited[i][j])
			{
				q.push(NODE(i,j,0,index++));
				while(!q.empty())
				{
					NODE t = q.front();
					q.pop();
					for(int i=0; i<4; i++)
					{
						int nx = t.x+dx[i];
						int ny = t.y+dy[i];
						if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
						if(visited[nx][ny]) continue;
						if(arr[nx][ny] == 'W') continue;
						visited[nx][ny] = true;
						areaNum[nx][ny] = t.area;
						q.push(NODE(nx,ny,t.cnt+1,t.area));
					}	
				}					
			}
		}
	
	// 영역 갯수만큼 반복문 
	for(int i=1; i<=index-1; i++)
	{
		queue<NODE> Area_q;
		int area_max = 0;
		for(int p=0; p<N; p++)
		{
			for(int q=0; q<M; q++)
			{
				if(areaNum[p][q] == i)
				{
					Area_q.push(NODE(p,q,0,i));
					for(int p=0; p<N; p++)
						for(int q=0; q<M; q++)
							visited[p][q] = false;
					
					int count = 0;
					while(!Area_q.empty())	
					{
						NODE t = Area_q.front();
						Area_q.pop();
						for(int i=0; i<4; i++)
						{
							int nx = t.x+dx[i];
							int ny = t.y+dy[i];
							if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
							if(visited[nx][ny]) continue;
							if(arr[nx][ny] == 'W') continue;
							visited[nx][ny] = true;
							areaNum[nx][ny] = t.area;
							Area_q.push(NODE(nx,ny,t.cnt+1,t.area));
							count = t.cnt+1;
						}		
					}	
					if(area_max < count)
						area_max = count;						
				}
			}
		}	
		if(ans < area_max)
			ans = area_max;		
	}
	cout << ans;
	return 0;
}
