#include <iostream>
#include <string>
using namespace std;

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
	return pi[str.size()-1];
}

int main()
{
	int L;
	string str;
	cin >> L >> str;
	cout << L-getPI(str);
	return 0;
}
