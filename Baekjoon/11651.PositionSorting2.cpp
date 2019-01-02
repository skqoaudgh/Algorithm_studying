#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
	if(a.second == b.second)
		return a.first<b.first;
	return a.second<b.second;
}

int main()
{
	vector< pair<int,int> > v;
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0; i<v.size(); i++)
		printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}
