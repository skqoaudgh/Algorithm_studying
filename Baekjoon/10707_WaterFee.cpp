#include <cstdio>
using namespace std;

int main() 
{
	int X_Lfee;
	int Y_baseFee;
	int Y_upper;
	int Y_Lfee;
	int P;
	scanf("%d %d %d %d %d",&X_Lfee,&Y_baseFee,&Y_upper,&Y_Lfee,&P);
	
	int X_total = P*X_Lfee;
	int Y_rest = P - Y_upper;
	int Y_add = 0;
	if(Y_rest > 0)
		Y_add = Y_Lfee * Y_rest;
	int Y_total = Y_add + Y_baseFee;
	int result = (Y_total>X_total)?X_total:Y_total;
	printf("%d",result);
	return 0;
}
