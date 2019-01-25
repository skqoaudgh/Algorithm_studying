#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
struct cd {
    int x, y;
};
cd start;
vector<cd> key_list;
 
struct edge {
    int weight, from, to;
};
bool cmp(const edge& e1, const edge& e2) {
    return e1.weight < e2.weight;
}
vector<edge> E;
 
int n, m, i, j, cx, cy, nx, ny, cnt, sum;
int key_cnt, key_num[51][51];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int dist[51][51];
bool visit[51][51];
char map[51][51];
 
int parent[251];
int find(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
}
 
int bfs(int x, int y, int mom) {
    memset(visit, 0, sizeof(visit));
    memset(dist, 0, sizeof(dist));
    key_cnt = 1;
 
    queue<cd> q;
    q.push({ x,y });
    visit[x][y] = true;
 
    while (!q.empty()) {
        cx = q.front().x;
        cy = q.front().y;
        q.pop();
 
        for (i = 0; i < 4; ++i) {
            nx = cx + dir[i][0];
            ny = cy + dir[i][1];
 
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (visit[nx][ny] || map[nx][ny] == '1')
                continue;
 
            dist[nx][ny] = dist[cx][cy] + 1;
            visit[nx][ny] = true;
 
            if (map[nx][ny] == 'K') {
                key_cnt++;
                E.push_back({ dist[nx][ny], mom, key_num[nx][ny] });
            }
 
            if (key_cnt == key_list.size())
                return key_cnt;
 
            q.push({ nx,ny });
        }
    }
    return key_cnt;
}
 
int main() {
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i) 
	{
        scanf("%s", map[i]);
        for (j = 0; j < n; ++j) 
		{
            if (map[i][j] == 'S') 
			{
                start = { i,j };
                map[i][j] = 'K';
            }
            if (map[i][j] == 'K') 
			{
                key_list.push_back({ i,j });
                key_num[i][j] = ++key_cnt;
            }
        }
    }
 
    for (auto key : key_list) 
	{
        if (bfs(key.x, key.y, key_num[key.x][key.y]) != key_list.size()) 
		{
            puts("-1");
            return 0;
        }
    }
 
    sort(E.begin(), E.end(), cmp);
 
    for (i = 0; i <= key_list.size(); ++i)
        parent[i] = i;
 
    i = 0;
    while (cnt != key_list.size() - 1) 
	{
        cx = find(E[i].from);
        cy = find(E[i].to);
 
        if (cx != cy) 
		{
            unite(cx, cy);
            sum += E[i].weight;
            cnt++;
        }
        i++;
    }
    printf("%d", sum);
    return 0;
}

