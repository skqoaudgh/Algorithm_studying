#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b)
{
	if(a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main()
{
	int N;
	vector<string> v;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		string a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0; i<v.size(); i++)
	{
		if(i<v.size()-1 && v[i] == v[i+1]) continue;
		cout << v[i] << '\n';
	}
	return 0;
}
