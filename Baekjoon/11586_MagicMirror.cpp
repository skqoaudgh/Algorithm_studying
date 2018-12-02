#include <iostream>
#include <string>
using namespace std;

string str[101];
int N,K;

int main()
{
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> str[i];
	cin >> K;
	
	if(K == 2)
	{
		for(int i=0; i<N; i++)
			for(int j=0; j<N/2; j++)
				swap(str[i][j],str[i][N-j-1]);
	}
	else if(K == 3)
	{
		for(int i=0; i<N/2; i++)
			for(int j=0; j<N; j++)
				swap(str[i][j],str[N-i-1][j]);			
	}
	
	for(int i=0; i<N; i++)
		cout << str[i] << '\n';
	
	return 0;
}
