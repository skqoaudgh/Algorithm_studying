#include <iostream>
#include <string>
#include <vector>
using namespace std;

int* getPI(string str)
{
	int len = str.size();
	int j = 0;
	int *pi = new int[len];
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

vector<int> KMP(string target, string find, int* pi)
{
	vector<int> v;
	int all_len = target.size();
	int find_len = find.size();
	int j = 0;
	for(int i=0; i<all_len; i++)
	{
		while(j>0 && target[i] != find[j])
			j = pi[j-1];
		if(target[i] == find[j])
		{
			if(j == find_len-1)
			{
				v.push_back(i-find_len+2);
				j = pi[j];
			}
			else 
				j ++;
		}
	}
	return v;
}

int main()
{
	string target_string;
	string find_string;
	getline(cin, target_string);
	getline(cin, find_string);
	
	vector<int> ans;
	int *pi = getPI(find_string);
	
	ans = KMP(target_string,find_string,pi);
	
	cout << ans.size() << endl;
	for(int i=0; i<ans.size(); i++)
		cout << ans[i] << ' ';
	return 0; 
}
