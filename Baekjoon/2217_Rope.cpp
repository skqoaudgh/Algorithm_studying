#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
	return a>b;
}

int main()
{
	int N;
	vector<int> v;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	int ans = 0;
	sort(v.begin(),v.end(),comp);
	for(int i=0; i<v.size(); i++)
	{
		if(ans < v[i]*(i+1))
			ans = v[i]*(i+1);
	}
	
	cout << ans;
	return 0;
}
