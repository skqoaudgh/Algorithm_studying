#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, ans = 0;
	string pattern_all, pattern[2], str[101];
	
	cin >> N >> pattern_all;
	
	int idx = pattern_all.find("*");
	pattern[0] = pattern_all.substr(0,idx);
	pattern[1] = pattern_all.substr(idx+1,pattern_all.size());
	
	for(int i=0; i<N; i++)
	{
		ans = 0;
		cin >> str[i];
		if(str[i].find(pattern[0]) == 0)
			ans ++;
			
		
		int index = str[i].size()-pattern[1].size();
		if(index <= pattern[0].size())
			index = pattern[0].size();
		if(str[i].find(pattern[1],index) == index)
			ans ++;
			
		if(ans == 2)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
	return 0;
}
