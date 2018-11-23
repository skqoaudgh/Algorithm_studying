#include <iostream>
#include <queue>
using namespace std;

int N;
char arr[51][51];
bool visited[51][51][2];
int B_tree[3][2];
int E_tree[3][2];
int rotate;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

struct NODE {
	int x, y, cnt,state;
	NODE(int _x, int _y, int _cnt, int _state) {x=_x;y=_y;cnt=_cnt;state=_state;};
};

int main()
{
	queue<NODE> q;
	cin >> N;
	int Bidx = 0;
	int Eidx = 0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 'B')
			{
				B_tree[Bidx][0] = i;
				B_tree[Bidx][1] = j;
				Bidx++;
			}
			else if(arr[i][j] == 'E')
			{
				E_tree[Eidx][0] = i;
				E_tree[Eidx][1] = j;
				Eidx++;
			}
		}
	}
	bool temp = 0;
	if(B_tree[0][1] == B_tree[1][1])
		temp = 1;
	if(E_tree[0][1] == E_tree[1][1])
		rotate = 1;

	int result = 987654321;
	q.push(NODE(B_tree[1][0],B_tree[1][1],0,temp)); // 0: 가로   1: 세로 
	while(!q.empty())
	{
		NODE t = q.front();
		q.pop();
		
		//cout << t.x << ' ' << t.y << ' ' << t.cnt << '\n';
		if(t.x == E_tree[1][0] && t.y == E_tree[1][1])
		{
			if(t.state == rotate)
			{
				if(result > t.cnt)
					result = t.cnt;
				continue;
			}			
		}

		for(int i=0; i<5; i++)
		{
			if(i < 4)
			{
				int nx = t.x+dx[i];
				int ny = t.y+dy[i];
				if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				if(arr[nx][ny] == '1') continue;
				if(visited[nx][ny][t.state]) continue;
				if(t.state == 0)
				{
					if(ny-1 < 0 || ny+1 >= N) continue;
					if(arr[nx][ny-1] == '1' || arr[nx][ny+1] == '1') continue;
				}
				else
				{
					if(nx-1 < 0 || nx+1 >= N) continue;
					if(arr[nx-1][ny] == '1' || arr[nx+1][ny] == '1') continue;
				}
				visited[nx][ny][t.state] = true;
				q.push(NODE(nx,ny,t.cnt+1,t.state));
			}
			else
			{
				int flag = false;
				for(int a=-1; a<2; a++)
				{
					for(int b=-1; b<2; b++)
					{
						if(t.x+a < 0 || t.y+b < 0 || t.x+a >= N || t.y+b >= N) 
						{
							flag = true;
							break;
						}
						if(arr[t.x+a][t.y+b] == '1')
						{
							flag = true;
							break;
						}
					}
					if(flag)
						break;					
				}
				int temp;
				if(t.state == 1)
					temp = 0;
				else
					temp = 1;				
				if(!flag && !visited[t.x][t.y][temp])
				{
					visited[t.x][t.y][temp] = true;
					q.push(NODE(t.x,t.y,t.cnt+1,temp));
				}		
			}
		}
	}
	if(result == 987654321)
		result = 0;
	cout << result;	
	return 0;
}
