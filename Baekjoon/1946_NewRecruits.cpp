#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first<b.first;
}

int main()
{
	int T;
	cin >> T;
	for(int test_case=0; test_case<T; test_case++)
	{
		int N,a,b;
		vector< pair<int,int> >v;
		cin >> N;
		for(int i=0; i<N; i++)
		{
			cin >> a >> b;
			v.push_back(make_pair(a,b));
		}
		sort(v.begin(),v.end());
		
		int idx = 0;
		int ans = 1;
		for(int i=1; i<N; i++)
		{
			if(v[idx].second > v[i].second)
			{
				ans ++;
				idx = i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
