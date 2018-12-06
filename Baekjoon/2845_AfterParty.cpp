#include <iostream>
using namespace std;

int main()
{
	int L,P;
	int arr[5];
	cin >> L >> P;
	for(int i=0; i<5; i++)
		cin >> arr[i];
		
	for(int i=0; i<5; i++)
		cout << arr[i] - L*P << ' ';
	return 0;
}
