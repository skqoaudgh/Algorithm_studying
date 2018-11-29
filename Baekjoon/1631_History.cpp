#include <iostream>
#include <vector>
using namespace std;

int n,k,s;
int arr[402][402];
vector< pair<int,int> > v;

int main()
{
	cin >> n >> k;
	
	for(int i=0; i<k; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = -1;
		arr[b][a] = 1;
	}
	cin >> s;
	for(int i=0; i<s; i++)
	{
		int c,d;
		cin >> c >> d;
		v.push_back(make_pair(c,d));
	}

	for(int p=1; p<=n; p++)
		for(int x=1; x<=n; x++)
			for(int y=1; y<=n; y++)
			{
				if(p==x || x==y || p==y) continue;
				if(arr[x][p] == -1 && arr[p][y] == -1)
					arr[x][y] = -1;
				else if(arr[x][p] == 1 && arr[p][y] == 1)
					arr[x][y] = 1;
			}

					
	for(int i=0; i<v.size(); i++)
		cout << arr[v[i].first][v[i].second] << '\n';
	
	return 0;
}
