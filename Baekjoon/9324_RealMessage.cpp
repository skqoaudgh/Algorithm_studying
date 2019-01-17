#include <iostream>
#include <string>
using namespace std;

int alpha[26];

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		for(int i=0; i<26; i++)
			alpha[i] = 0;
		bool check = false,ans = true;
		char prev;
		string str;
		cin >> str;
		for(int i=0; i<str.size(); i++)
		{
			if(check)
			{
				if(prev == str[i])
				{
					check = false;
					continue;
				}
				else
				{
					ans = false;
					break;
				}
			}
			else
			{
				alpha[str[i]-'A'] ++;
				if(alpha[str[i]-'A'] % 3 == 0)
				{
					check = true;
					prev = str[i];
				}
			}
		}
		if(ans && !check)
			printf("OK\n");
		else
			printf("FAKE\n");		
	}
	return 0;
}
