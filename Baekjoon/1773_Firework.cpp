#include <cstdio>
using namespace std;

int main()
{
	int N,C,cnt=0;
	int arr[100];
	scanf("%d %d",&N,&C);
	for(int i=0; i<N; i++)
		scanf("%d",&arr[i]);
	
	for(int i=1; i<=C; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(i % arr[j] == 0)
			{
				cnt ++;
				break;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
