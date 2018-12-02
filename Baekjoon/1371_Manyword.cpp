#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[30];
int max_cnt;
int main()
{
	vector<int> v;
	string temp, str;
	while(cin >> temp) {
		str += temp;
	}
	int cnt = 0;
	for(int i=0; i<str.length(); i++)
	{
		int index = (int)str[i]-'a';
		arr[index] ++;
	}
	for(int i=0; i<26; i++)
	{
		if(max_cnt < arr[i])
		{
			max_cnt = arr[i];
			v.clear();
			v.push_back(i);
		}
		else if(max_cnt == arr[i])
		{
			v.push_back(i);
		}
			
	}
	
	sort(v.begin(),v.end());
	
	for(int i=0; i<v.size(); i++)
		cout << (char)('a'+v[i]);
	return 0;
}
