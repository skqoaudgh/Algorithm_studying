#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	for(int i=0;i <str.size(); i++)
	{
		if(str[i] == 'A')
			str[i] = 'X';
		else if(str[i] == 'B')
			str[i] = 'Y';
		else if(str[i] == 'C')
			str[i] = 'Z';
		else
			str[i] -=3;
	}
		
	cout << str;
	return 0;
}
