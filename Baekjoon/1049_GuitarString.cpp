#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N,M;
	vector< pair<int,int> > v;
	cin >> N >> M;
	for(int i=0; i<M; i++)
	{
		int a,b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	
	int ans = 0;
	int pack_min = 987654321;
	int single_min = 987654321;
	for(int i=0; i<M; i++)
	{
		if(v[i].first < pack_min)
			pack_min = v[i].first;
		if(v[i].second < single_min)
			single_min = v[i].second;		
	}
	
	ans = (N/6)*pack_min + (N%6)*single_min;
	if(ans > N*single_min)
		ans = N*single_min;
	if(ans > ((N/6)+1)*pack_min)
		ans = ((N/6)+1)*pack_min;
	cout << ans;
	return 0;
}
