#include <iostream>
#include <queue>

using namespace std;

int dest[2];
int src[2];
int I;
int dx[] = {-1, -1, -2, -2, 1, 1, 2, 2};
int dy[] = {-2, 2, -1, 1, -2, 2, -1, 1};
int ans;
bool visited[301][301];

struct NODE {
	int x, y, cnt;
	NODE(int _x, int _y, int _cnt) {x=_x;y=_y;cnt=_cnt;};	
};

int main()
{
	int t;
	cin >> t;
	for(int test_case=0; test_case<t; test_case++)
	{
		cin >> I;
		for(int i=0; i<2; i++)
			cin >> src[i];
		for(int i=0; i<2; i++)
			cin >> dest[i];
		for(int i=0; i<I; i++)
			for(int j=0; j<I; j++)
				visited[i][j] = false;
		
		if(src[0] == dest[0] && src[1] == dest[1])
			ans = 0;
		else 
		{
			ans = 987654321;
			queue<NODE> q;
			q.push(NODE(src[0],src[1],1));
			while(!q.empty())
			{
				NODE t = q.front();
				q.pop();
				
				for(int i=0; i<8; i++)
				{
				 	int nx = t.x + dx[i];
				 	int ny = t.y + dy[i];
				 	if(nx < 0 || ny < 0 || nx >= I || ny >= I) continue;
				 	if(visited[nx][ny]) continue;
				 	
				 	if(nx == dest[0] && ny == dest[1])
				 	{
				 		if(ans > t.cnt)
						 	ans = t.cnt;
					}
				 	else
				 	{
				 		visited[nx][ny] = true;
				 		q.push(NODE(nx,ny,t.cnt+1));
					}	
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
