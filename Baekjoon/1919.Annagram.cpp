#include <iostream>
#include <string>
using namespace std;

string A,B;
bool visited[1001];

int main()
{
	cin >> A >> B;
	int a_size = A.size();
	int b_size = B.size();
	int cnt = 0;
	
	for(int i=0; i<a_size; i++)
	{
		for(int j=0; j<b_size; j++)
		{
			if(visited[j]) continue;
			if(A[i] == B[j])
			{
				visited[j] = true;
				cnt ++;
				break;
			}
		}
	}
	
	cout << a_size + b_size - 2*cnt;
	return 0;
}
