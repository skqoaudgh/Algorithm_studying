#include <iostream>
#include <vector>
using namespace std;

struct NODE {
	int x, y, cnt, broken;
	bool use;
	NODE(int X, int Y, int CNT, int Broken, bool USE) { x=X; y=Y; cnt=CNT; broken=Broken; use=USE; };
};
int map[9][9];
bool visited[9][9];
int result = 0;
int N,K;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(NODE t)
{
	if(t.cnt > result)
		result = t.cnt;
	visited[t.x][t.y] = true;
	for(int i=0; i<4; i++)
	{
		int nx = t.x+dx[i];
		int ny = t.y+dy[i];
		if(visited[nx][ny]) continue;
		if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
		if(map[t.x][t.y]-t.broken > map[nx][ny])
			dfs(NODE(nx,ny,t.cnt+1,0,t.use));
		else if(!t.use)
		{
			for(int j=1; j<=K; j++)
			{
				if(map[t.x][t.y] > map[nx][ny]-j)
				{
					dfs(NODE(nx,ny,t.cnt+1,j,true));
					break;					
				}

			}
		}
	}
	visited[t.x][t.y] = false;
}

int main()
{
	int t;
	cin >> t;
	for(int test_case=0; test_case<t; test_case++)
	{
		cin >> N >> K;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				cin >> map[i][j];
				
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				visited[i][j] = false;
						
		vector<NODE> v;
		int max = 0;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(map[i][j] > max)
					max = map[i][j];
					
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(map[i][j] == max)
					v.push_back(NODE(i,j,1,0,false));
					
		
		result = 0;
		for(int i=0; i<v.size(); i++)
			for(int j=0; j<4; j++)
				dfs(v[i]);
		
		
		cout << "#" << test_case+1 << " " << result << '\n';
	}
	return 0;
}


/*

1. 제일 높은 등산로를 선택하여 첫 스타트
2. 하산할 수 있는 방향으로 DFS로 이동.
3. 이 때, 불가능한 방향이 나오면 산을 깍아서 이동
4. 이 때, 깍을 1~K 까지 해보아야함 
5. 다음 칸으로 갔을 때, result와 cnt 비교 

*/
