#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A,B;
	getline(cin,A);
	getline(cin,B);
	
	int findIndex = 0;
	int cnt = 0;
	while((findIndex=A.find(B,findIndex)) != -1)
	{
		cnt ++;
		findIndex += B.size();
	}
	cout << cnt;
	return 0;
}
