#include <stdio.h>

int main(void)
{
	long long int hurt_finger,hf_num;
	long long int num=0;

	scanf("%lld",&hurt_finger);
	scanf("%lld",&hf_num);

	switch(hurt_finger)
	{
		case 1:
			num = hf_num*8;
			break;
		case 2:
			num = (hf_num/2)*8 + 1 + (hf_num%2)*6;
			break;
		case 3:
			num = (hf_num/2)*8 + 2 + (hf_num%2)*4;
			break;
		case 4:
			num = (hf_num/2)*8 + 3 + (hf_num%2)*2;
			break;
		case 5:
			num = hf_num*8 + 4;
			break;
	}
	printf("%lld",num);
    return 0;
}
