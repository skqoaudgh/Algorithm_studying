#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> v;
	int N,K;
	scanf("%d %d",&N,&K);
	for(int i=0; i<N; i++)
	{
		int a;
		scanf("%d",&a);
		v.push_back(a);
	}
	sort(v.begin(),v.end());
	printf("%d",v[K-1]);
	return 0;
}
