#include <cstdio>

int main()
{
	int A,B,C,D;
	double sum[4];
	scanf("%d %d %d %d",&A,&B,&C,&D);
	sum[0] = (double)A/C + (double)B/D;
	sum[1] = (double)C/D + (double)A/B;
	sum[2] = (double)D/B + (double)C/A;
	sum[3] = (double)B/A + (double)D/C;
	
	int max = sum[0];
	int idx = 0;
	for(int i=1; i<4; i++)
	{
		if(max < sum[i])
		{
			max = sum[i];
			idx = i;
		}
	}
	printf("%d",idx);
	return 0;
}
