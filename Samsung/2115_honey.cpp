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
�κ������� ����� �� �׷��� ������ �Ѵ�.

cnt�� N�� ������ �� �� ����, �ε����� �����س�����. �ε����� �������� ���� �� �翬�ϰ� cnt�� +1 ���� �ʴ´�.

���õ� �ε����� visited�� ���� ��Ÿ����.

���� for���� ���Ͽ� arr[i][j]�� ���� ������ sum�� ���Ѵ�. �� ��, i==j�� ���� arr�� 0�̹Ƿ� ������� �ʾƵ� �ȴ�. 
*/
