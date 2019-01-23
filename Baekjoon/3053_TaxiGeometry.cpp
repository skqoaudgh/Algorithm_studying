#include <stdio.h>

#define M_PI 3.14159265358979323846 

int main()
{
	int R;
	scanf("%d",&R);
	printf("%.6f\n%.6f",R*R*M_PI,(double)R*R*2);
	return 0;
}
