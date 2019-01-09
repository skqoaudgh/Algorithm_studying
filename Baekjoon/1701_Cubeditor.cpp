#include <iostream>
#include <string>
using namespace std;

string prefix[5001];

int getPI(string str)
{
	int len = str.size();
	int j = 0;
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
	
	int max = 0;
	for(int i=0; i<len; i++)
		if(max < pi[i] && pi[i] > 1)
			max = pi[i];
	return max;
}

int main()
{
	string str;
	cin >> str;
	int ans = 0;
	int len = str.size();
	for(int i=0; i<len; i++)
	{
		prefix[i] = str;
		str.erase(0,1);
		int temp = getPI(prefix[i]);
		if(temp > ans)
			ans = temp;
	}
	cout << ans;
	return 0;
}
