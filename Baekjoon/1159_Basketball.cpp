#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	string str[151];
	int cnt[26] = {0,};
	bool flag = false;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		cin >> str[i];
		cnt[str[i][0]-'a'] ++;
	}
	
	for(int i=0; i<26; i++)
	{
		if(cnt[i] >= 5)
		{
			cout << char('a'+i);
			flag = true;
		}
					
	}
	if(!flag)
		cout << "PREDAJA";
	return 0;
}
