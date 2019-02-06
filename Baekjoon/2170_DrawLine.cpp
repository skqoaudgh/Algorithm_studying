#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
P Line[1000000];

int main()
{
	int N;
	scanf("%d",&N);	
	for(int i=0; i<N; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		Line[i] = P(a,b);
	}
	sort(Line,Line+N);
	
	int result = 0;
	int left = -1000000001, right = -1000000001;
	for(int i=0; i<N; i++)
	{
		if(right < Line[i].first) // 현재 구간과 떨어져 있음
		{
			result += right-left;
			left = Line[i].first;
			right = Line[i].second;
		}
		else
			right = max(right,Line[i].second);
	}
	result += right-left;
	printf("%d",result);
	return 0;
}
