#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		string a;
		int len;
		cin >> a;
		len = a.size();
		if(a[len-1] == '0' || a[len-1] == '2' || a[len-1] == '4' || a[len-1] == '6' || a[len-1] == '8')
			cout << "even\n";
		else
			cout << "odd\n";
	}
	return 0;
} 
