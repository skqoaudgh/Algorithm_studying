#include <iostream>
#include <queue>

using namespace std;
struct NODE {
	int r, c, dir;
	NODE(int R, int C, int DIR) {r=R;c=C;dir=DIR;};
};

int arr[51][51];
bool visited[51][51];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int main()
{
	int N,M;
	cin >> N >> M;
	
	queue<NODE> q;
	int r,c,dir;
	cin >> r >> c >> dir;
	q.push(NODE(r,c,dir));
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			cin >> arr[i][j];
	
	int cnt = 0;
	while(!q.empty())
	{
		NODE t = q.front();
		q.pop();
		
		if(!visited[t.r][t.c])
		{
			cnt ++;
			visited[t.r][t.c] = true;
		}
			
		
		int flag = false; // true: 청소할 곳 있음 
		int nr,nc;
		int tempDir = t.dir;
		for(int i=0; i<4; i++)
		{
			tempDir --;
			if(tempDir == -1) tempDir = 3;
			
			nr = t.r+dr[tempDir];
			nc = t.c+dc[tempDir];
			if(!visited[nr][nc] && arr[nr][nc] == 0) {
				flag = true; 
				break;
			}
		}
		
		if(flag)
			q.push(NODE(nr,nc,tempDir));
		else
		{
			int ar, ac;
			switch(t.dir)
			{
				case 0: {
					ar = t.r+1;
					ac = t.c;
					break;
				}
				case 1: {
					ar = t.r;
					ac = t.c-1;
					break;
				}	
				case 2: {
					ar = t.r-1;
					ac = t.c;
					break;
				}
				case 3: {
					ar = t.r;
					ac = t.c+1;
					break;
				}
			}
			if(arr[ar][ac] == 1)
				break;
			else
				q.push(NODE(ar,ac,t.dir));
		}
	}
	cout << cnt;
	return 0;
}
