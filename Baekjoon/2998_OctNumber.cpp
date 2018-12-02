#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	
	while(str.size() % 3 != 0)
		str.insert(0,"0");

	for(int i=str.size()-3; i>=0; i-=3)
	{
		string temp = str.substr(i,3);
		if(temp == "000") str.replace(i,3,"0");
		else if(temp == "001") str.replace(i,3,"1");
		else if(temp == "010") str.replace(i,3,"2");
		else if(temp == "011") str.replace(i,3,"3");
		else if(temp == "100") str.replace(i,3,"4");
		else if(temp == "101") str.replace(i,3,"5");
		else if(temp == "110") str.replace(i,3,"6");
		else str.replace(i,3,"7");
	}
	cout << str;
	return 0;
}
