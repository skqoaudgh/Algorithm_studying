#include <iostream>
using namespace std;

int main()
{
	int arr[3];
	char order[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	cin >> order[0] >> order[1] >> order[2];
	
	for(int i=0; i<2; i++)
		for(int j=1; j<3; j++)
			if(arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
	
	for(int i=0; i<3; i++)
		cout << arr[order[i]-'A'] << ' ';
	return 0;
}
