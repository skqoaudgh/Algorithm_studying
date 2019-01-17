#include <string>
#include <iostream>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int R,C;
string arr[10];

int func()
{
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
			if(arr[i][j] == '.')
			{
				int cnt = 0;
				for(int t=0; t<4; t++)
				{
					int nx = i+dx[t];
					int ny = j+dy[t];
					if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
					if(arr[nx][ny] == '.')
						cnt ++;						
				}
				if(cnt < 2)
					return 1;
			}
		}
	}
	return 0;
}

int main()
{	
	cin >> R >> C;
	for(int i=0; i<R; i++)
		cin >> arr[i];
	
	cout << func();
	return 0;
}
