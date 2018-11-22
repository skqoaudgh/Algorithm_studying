#include <iostream>
#include <queue> 
using namespace std;

struct NODE {
	int x, y, d, k;
	NODE(int X, int Y, int D, int K) { x=X; y=Y; d=D; k=K; };
};
int arr[4001][4001];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() 
{
	int T;
	cin >> T;
	for(int Test_Case=0; Test_Case<T; Test_Case++)
	{
		queue<NODE> q;
		int N,idx;
		int ans = 0;
		cin >> N;
		for(int i=0; i<N; i++)
		{
			int x, y, dire, pow;
			cin >> x >> y >> dire >> pow;
			if(pow == 0) pow = 101;
			
			int rx = y+1000; int ry = x+1000;
			
			q.push(NODE(4000-rx*2,ry*2,dire,pow));
			arr[4000-rx*2][ry*2] = pow;
		}
		
		int CntZero = 0;
		int result = 0;
		while(!q.empty())
		{
			NODE t = q.front();
			q.pop();
			if(arr[t.x][t.y] > t.k) 
			{
				if(t.k == 101) result -=101;
				result += arr[t.x][t.y];
				arr[t.x][t.y] = 0;
				continue;
			}
			int nx = t.x + dx[t.d];
			int ny = t.y + dy[t.d];
			if(nx < 0 || ny < 0 || nx > 4000 || ny > 4000) 
			{
				arr[t.x][t.y] = 0;
				continue;
			}
			if(arr[nx][ny] != 0)
			{
				if(t.k == 101) CntZero ++;
				arr[nx][ny] += t.k;
				arr[t.x][t.y] = 0;
			}
			else
			{
				arr[nx][ny] = t.k;
				arr[t.x][t.y] = 0;
				q.push(NODE(nx,ny,t.d,t.k));
			}
		}
		result -= (CntZero*-101);
		
		cout << "#" << Test_Case+1 << " " << result << '\n';
	}
	return 0;
}

/*
 원자가 시간이 흘러 같은 위치에 이동하게 되면 충돌
 단, 두 원자의 거리가 1일시 0.5초 후에 반드시 충돌
  
충돌한 원자들은 움직일 필요 없음 -> 제외 
*/ 
 
