#include <iostream>
#include <string>
using namespace std;

int main()
{
	while(1)
	{
		string str;
		getline(cin,str);
		if(str == "END") break;
		
		for(int i=0; i<str.size(); i++)
			cout << str[str.size()-i-1];
		cout << '\n';
	}
	return 0;
}
