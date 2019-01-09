#include <iostream>
#include <string>
using namespace std;

string prefix[5001];

int getPI(string str)
{
	int len = str.size();
	int j = 0, max = 0;
	int* pi = new int[len];
	for(int i=0; i<len; i++)
		pi[i] = 0;
		
	for(int i=1; i<len; i++)
	{
		while(j > 0 && str[i] != str[j])
			j = pi[j-1];
		if(str[i] == str[j])
			pi[i] = ++j;		
	}
	return pi[len-1];
}

int main()
{
	while(1)
	{
		string str;
		cin >> str;
		if(str == ".")
			break;
		else
		{
			int len = str.size();
			int ans = getPI(str);
			if(ans == 0 || ans%(len-ans)!=0)
				cout << "1\n";
			else
				cout << len/(len-ans) << '\n';
		}
	}
	return 0;
}
