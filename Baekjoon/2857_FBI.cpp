#include <iostream>
#include <string>
using namespace std;

int main()
{
	string arr[5];
	for(int i=0; i<5; i++)
		cin >> arr[i];
		
	bool flag = false;
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<=arr[i].size()-3; j++)
		{
			if(arr[i].substr(j,3) == "FBI")
			{
				flag = true;
				cout << i+1 << ' ';
				break;
			}
		}
	}
	if(!flag)
		cout << "HE GOT AWAY!" << '\n';
	return 0;
}
