#include <iostream>

using namespace std;

int arr[103][2]; 
bool isPossible[103][103]; // i -> j 까지 가는게 가능한지 => i->j 거리가 1000 이하인지

int abs(int num)
{
	if(num >= 0)
		return num;
	else
		return -num;	
}

void floyd(int n)
{
	bool flag = false;
	for(int k=0; k<n+2; k++)
		for(int i=0; i<n+2; i++)
		{
			for(int j=0; j<n+2; j++)
			{
				if(isPossible[i][j]) continue;
				if(isPossible[i][k] && isPossible[k][j])
					isPossible[i][j] = true;
			}
		}
}

int main()
{
	int t;
	cin >> t;
	for(int test_case=0; test_case<t; test_case++)
	{
		int n;
		cin >> n;
		cin >> arr[0][0] >> arr[0][1];
		for(int i=1; i<=n; i++)
			cin >> arr[i][0] >> arr[i][1];
		cin >> arr[n+1][0] >> arr[n+1][1];
		
		bool flag = false;
		
		
		for(int i=0; i<n+2; i++)
			for(int j=0; j<n+2; j++)
				isPossible[i][j] = false;
				
		for(int i=0; i<n+2; i++)
			for(int j=0; j<n+2; j++)
				if((abs(arr[i][0] - arr[j][0])+abs(arr[i][1] - arr[j][1])) <= 1000)
				{
					isPossible[i][j] = true;
					isPossible[j][i] = true;
				}
			
		floyd(n);
		
		if(!isPossible[0][n+1])
			cout << "sad\n";
		else
			cout << "happy\n";
	}
	return 0;
}
