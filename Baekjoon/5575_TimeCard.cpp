#include <cstdio>


int timeToSec(int a, int b, int c)
{
	return a*60*60 + 60*b + c;	
}

int main()
{
	int Time[3][6];
	for(int i=0; i<3; i++)
		for(int j=0; j<6; j++)
			scanf("%d",&Time[i][j]);
			
	int A1 = timeToSec(Time[0][0],Time[0][1],Time[0][2]);
	int A2 = timeToSec(Time[0][3],Time[0][4],Time[0][5]);
	int B1 = timeToSec(Time[1][0],Time[1][1],Time[1][2]);
	int B2 = timeToSec(Time[1][3],Time[1][4],Time[1][5]);
	int C1 = timeToSec(Time[2][0],Time[2][1],Time[2][2]);
	int C2 = timeToSec(Time[2][3],Time[2][4],Time[2][5]);		
				
	printf("%d %d %d\n",(A2-A1)/3600,((A2-A1)/60)%60,(A2-A1)%60);
	printf("%d %d %d\n",(B2-B1)/3600,((B2-B1)/60)%60,(B2-B1)%60);
	printf("%d %d %d\n",(C2-C1)/3600,((C2-C1)/60)%60,(C2-C1)%60);
	return 0;
}
