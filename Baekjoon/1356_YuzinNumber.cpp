#include <stdio.h>

int main()
{
	int N;
	scanf("%d",&N);
	
	int temp = N;
	int digit = 0;
	int number[10];
	while(temp > 0)
	{
		number[digit++] = temp%10;
		temp /= 10;
	}
	// 0: 1의자리. 1: 10의자리 - - - 
	bool flag = false;
	for(int i=0; i<digit-1; i++)
	{
		int num_a = 1;
		int num_b = 1;
		for(int j=0; j<=i; j++)
			num_a *= number[j];
		for(int j=i+1; j<digit; j++)
			num_b *= number[j];
		
		if(num_a == num_b)
			flag = true;
	}
	if(flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}
