#include <iostream>
#include <math.h>
using namespace std;

int arr[17][17];
bool visited[17];
int N;
int result;

void dfs(int index, int cnt)
{
	if(cnt > N/2) return;
	if(index >= N) return;
	if(cnt == N/2)
	{
		int sum_A = 0;
		int sum_B = 0;
		for(int i=0; i<N; i++)
		{
			if(visited[i])
			{
				for(int j=0; j<N; j++)
					if(visited[j])
						sum_A += arr[i][j];	
			}
			if(!visited[i])
			{
				for(int j=0; j<N; j++)
					if(!visited[j])
						sum_B += arr[i][j];	
			}
		}
		int val = abs(sum_A-sum_B);
		if(result > val)
			result = val;
		return;
	}
	
	visited[index] = true;
	dfs(index+1,cnt+1);
	visited[index] = false;
	dfs(index+1,cnt);
}

int main()
{
	int t;
	cin >> t;
	for(int test_case=0; test_case<t; test_case++)
	{
		cin >> N;
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				cin >> arr[i][j];
				
		result = 987654321;
		dfs(0,0);
		cout << "#" << test_case+1 << ' ' << result << '\n';
	}
	return 0;
}

/*
부분집합을 만들어 두 그룹을 만들어야 한다.

cnt가 N의 절반이 될 때 까지, 인덱스를 선택해나간다. 인덱스를 선택하지 않을 시 당연하게 cnt를 +1 하지 않는다.

선택된 인덱스는 visited를 통해 나타낸다.

이중 for문을 통하여 arr[i][j]의 값을 각각의 sum에 더한다. 이 때, i==j일 때는 arr이 0이므로 고려하지 않아도 된다. 
*/
