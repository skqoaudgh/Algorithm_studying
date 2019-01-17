#include <iostream>
#include <string>
using namespace std;

int main()
{
	int H,W;
	string arr[100];
	int ans[100][100];
	cin >> H >> W;
	for(int i=0; i<H; i++)
		cin >> arr[i];
	
	for(int i=0; i<H; i++)
	{
		bool flag = false;
		int cnt = 1;
		for(int j=0; j<W; j++)
		{
			if(arr[i][j] == 'c')
			{
				ans[i][j] = 0;
				cnt = 1;
				flag = true;
			}
			else if(arr[i][j] == '.')
			{
				if(!flag)
					ans[i][j] = -1;
				else
					ans[i][j] = cnt++;		
			}
		}
	}
	for(int i=0; i<H; i++)
	{
		for(int j=0; j<W; j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
