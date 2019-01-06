#include <stdio.h>
#include <algorithm>
double arr[101];

bool desc(double a, double b)
{
	return a>b;
}

int main()
{
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			int a;
			double b;
			scanf("%d %lf",&a,&b);
			if(arr[a] < b)
				arr[a] = b;
		}
	}
	double ans = 0;
	std::sort(arr+1,arr+N+1,desc);
	for(int i=1; i<=K; i++)
		ans += arr[i];
		
	printf("%.1lf",ans);
}

