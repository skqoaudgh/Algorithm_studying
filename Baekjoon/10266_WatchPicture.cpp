#include <iostream>
#include <string>
using namespace std;

int* getPI(string str)
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
	return pi;
}

int KMP(string all, string find, int* pi)
{
	int j = 0, ans = 0;
	int len = find.size();
	for(int i=0; i <all.size(); i++)
	{
		while(j > 0 && all[i] != find[j])
			j = pi[j-1];
		if(all[i] == find[j])
		{
			if(j == len-1)
			{
				j = pi[j];
				ans = 1;
			}
			else 
				j++;
		}
	}
	return ans;
}

int main()
{
	int N;
	cin >> N;
	
	string One_Str,Two_Str;
	
	for(int i=0; i<360000; i++)
	{
		One_Str += '0';
		Two_Str += '0';
	}

	for(int i=0; i<N; i++)
	{
		int temp;
		cin >> temp;
		One_Str[temp] = '1';
	}
	One_Str.append(One_Str);
	
	for(int i=0; i<N; i++)
	{
		int temp;
		cin >> temp;
		Two_Str[temp] = '1';
	}

	int ans = KMP(One_Str, Two_Str, getPI(Two_Str));
	if(ans == 1)
		cout << "possible";
	else
		cout << "impossible";

	return 0;
}
