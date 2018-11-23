#include <iostream>
#include <queue>
#include <string>
using namespace std;

int dx[] = {-1, 1, 0 ,0};
int dy[] = {0, 0, -1, 1};

struct NODE {
	int x,y,cnt;
	NODE(int X, int Y, int CNT) {x=X;y=Y;cnt=CNT;};
};
int R,C,curr;
string ans;
char arr[52][52];
bool visited[52][52];
queue<NODE> q;
queue<NODE> w;
// . : 비어있음		* : 물		X : 돌 		D : 비버 	S : 고슴도치 

void SpreadWater()
{
	curr ++;
	int size = w.size();
	for(int q=0; q<size; q++)
	{
		NODE t = w.front();
		w.pop();
		for(int i=0; i<4; i++)
		{
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue; 	// 경계 밖
			if(arr[nx][ny] == '.')
			{
				arr[nx][ny] = '*';
				w.push(NODE(nx,ny,0));		
				//cout << nx << ' ' << ny << " water\n";
			}
		}
	}
}

int main()
{
	cin >> R >> C;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 'S')
				q.push(NODE(i,j,0));
			if(arr[i][j] == '*')
				w.push(NODE(i,j,0));
		}
			
	int result = 987654321;
	while(!q.empty())
	{
		NODE t = q.front();
		q.pop();
	
		if(t.cnt == curr)
			SpreadWater();
				
		visited[t.x][t.y] = true;
		for(int i=0; i<4; i++)
		{
			int nx = t.x + dx[i];
			int ny = t.y + dy[i];
			if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue; 	// 경계 밖
			if(visited[nx][ny]) continue;							// 방문한 곳 
			if(arr[nx][ny] == '*' || arr[nx][ny] == 'X') continue;	// 돌이나 물 
			if(arr[nx][ny] == 'D')
				if(result > t.cnt+1)
				{
					result = t.cnt+1;
					continue;
				}
			visited[nx][ny] = true;
			q.push(NODE(nx,ny,t.cnt+1));
		}	
	}
	if(result == 987654321)
		ans = "KAKTUS";
	else
		ans = to_string(result);
	cout << ans;
	return 0;
}
