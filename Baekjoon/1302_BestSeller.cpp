#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
	map<string,int> m;
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		string str;
		cin >> str;
		m[str] ++;
	}
	int max = 0;
	string ans;
 	map<string,int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
    {
    	if(max < iter->second)
    	{
    		max = iter->second;
    		ans = iter->first;
		}
		if(max == iter->second && iter->first.compare(ans) < 0)
			ans = iter->first;
	}
	cout << ans;
	return 0;
}
