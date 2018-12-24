#include <iostream>
#include <string>
using namespace std;

int* GetPi(string str)
{
	int len = str.size(), j = 0;
	int* pi = new int[len];
	for(int i=0; i<len; i++)
		pi[i] = 0;
		
	for(int i=1; i<len; i++)
	{
		while(j>0 && str[i] != str[j])
			j = pi[j-1];
		if(str[i] == str[j])
			pi[i] = ++j;
	}
	return pi;
}

int KMP(string target, string find)
{
	int ans = 0, j = 0;
	int target_len = target.size();
	int find_len = find.size();
	int* pi = GetPi(find);
	
	for(int i=0; i<target_len; i++)
	{
		while(j>0 && target[i] != find[j])
			j = pi[j-1];
		if(target[i] == find[j])
		{
			if(j == find_len-1)
			{
				ans ++;
				j = pi[j];
			}
			else
				j ++;
		}
	}
	return ans;
}

int main()
{
	int N,M;
	string str, Pn;
	cin >> N >> M >> str;
	
	for(int i=1; i<=2*N+1; i++)
	{
		if(i%2 != 0)
			Pn += 'I';
		else
			Pn += 'O';
	}

	int cnt = KMP(str, Pn);
	cout << cnt;
	return 0;
}
