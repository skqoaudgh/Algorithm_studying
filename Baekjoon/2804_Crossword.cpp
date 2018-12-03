#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A,B;
	cin >> A >> B;
	
	bool flag = false;
	int row, column;
	for(int i=0; i<A.size(); i++)
	{
		for(int j=0; j<B.size(); j++)
		{
			if(A[i] == B[j])
			{
				row = j;
				column = i;
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	
	for(int i=0; i<B.size(); i++)
	{
		for(int j=0; j<A.size(); j++)
		{
			if(i == row)
				cout << A[j];
			else if(j == column)
				cout << B[i];
			else
				cout << '.';
		}
		cout << '\n';
	}
	return 0;
}
