#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int main()
{
	int N;
	vector<P> arr;
	
	scanf("%d",&N);
	for(int i=1; i<=N; i++)
	{
		int num;
		scanf("%d",&num);
		arr.push_back(P(i,num)); // i��° ǳ�� �ȿ��� num�� ��������. 
	}

	while(!arr.empty())
	{
		printf("%d ",arr.front().first);
		int idx = arr.front().second;
		arr.erase(arr.begin());
		
		if(idx < 0)
		{
			for(int i=0; i<abs(idx); i++)
			{
				arr.insert(arr.begin(),arr.back());
				arr.erase(arr.end());
			}
		}
		else
		{
			for(int i=0; i<idx-1; i++)
			{
				arr.push_back(arr.front());
				arr.erase(arr.begin());
			}
		}		
	}
	return 0;
}
