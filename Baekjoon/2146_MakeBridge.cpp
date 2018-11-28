#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
bool visited[101][101];
int area[101][101];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

struct NODE {
	int val, x, y, cnt, area;
	NODE(int _val, int _x, int _y, int _cnt, int _area) { val = _val; x = _x; y = _y; cnt = _cnt; area = _area; };
};

int area_cnt = 1;
void dfs(int y, int x, int n, int cnt) 
{
	visited[y][x] = true;
	area[y][x] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;

		if (0 <= ny && ny < n && 0 <= nx && nx < n) {
			if (!visited[ny][nx] && arr[ny][nx] > 0) {
				dfs(ny, nx, n, cnt);
			}
		}
	}
}

void getArea(int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && arr[i][j] > 0) {
				dfs(i, j, N, area_cnt++);
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];


	getArea(N);
	int ans = 987654321;
	queue<NODE> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					visited[i][j] = false;

			if (arr[i][j] == 1 && !visited[i][j])
			{
				for (int t = 0; t < 4; t++)
				{
					int nx = i + dx[t];
					int ny = j + dy[t];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (arr[nx][ny] == 0)
					{
						q.push(NODE(1, i, j, 0,area[i][j]));
						break;
					}
				}
			}
			while (!q.empty())
			{
				NODE t = q.front();
				q.pop();

				if (t.val == 1 && t.cnt > 0)
					if (ans > t.cnt - 1)
					{
						ans = t.cnt - 1;
						//cout << t.x << ' ' << t.y << ' ' << t.cnt << '\n';
					}
						

				for (int p = 0; p < 4; p++)
				{
					int nx = t.x + dx[p];
					int ny = t.y + dy[p];
					if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if (visited[nx][ny]) continue;
					if (t.val == 1 && arr[nx][ny] == 1) continue;
					if (area[nx][ny] == t.area) continue;
					visited[nx][ny] = true;
					q.push(NODE(arr[nx][ny], nx, ny, t.cnt + 1, t.area));
				}
			}
		}
	}
	cout << ans;
	return 0;
}
