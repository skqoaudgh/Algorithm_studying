#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
    return a > b;
}

bool isCanDivided(string num)
{
	int len = num.size();
	int sum = 0;
	for(int i=0; i<len; i++)
		sum += (int)(num[i]-'0');
	if(sum % 3 == 0)
		return true;
	return false;
}

bool zeroCheck(string num)
{
	int len = num.size();
	for(int i=0; i<len; i++)
	{
		if(num[i] == '0')
			return true;		
	}
	return false;	
}

int main()
{
	string str;
	cin >> str;
	sort(str.begin(),str.end(),comp);
	if(!zeroCheck(str)) cout << "-1";
	else
	{
		if(!isCanDivided(str)) cout << "-1";
		else
		{
			cout << str;
		}
	}
	return 0;
}
