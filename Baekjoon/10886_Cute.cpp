#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int a = 0, b = 0, temp;
	for(int i=0; i<N; i++)
	{
		cin >> temp;
		if(temp == 0)
			a ++;
		else
			b ++;
	}
		
	if(a > b)
		cout << "Junhee is not cute!";
	else
		cout << "Junhee is cute!";
	return 0;
}
