#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int test_case=0; test_case<T; test_case++)
	{
		int N;
		int cnt = 0;
		float sum = 0;
		cin >> N;
		for(int i=0; i<N; i++)
		{
			int a;
			float b;
			cin >> a >> b;
			cnt += a;
			sum += a*b;
		}
		float res = sum/cnt;
		printf("%d %.1f\n",cnt,res);
	}
	return 0;
}
