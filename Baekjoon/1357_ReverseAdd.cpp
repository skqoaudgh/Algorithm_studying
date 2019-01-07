#include <stdio.h>
#include <string>
#include <math.h>
int rev(int val)
{
	int digit[4] = {0,};
	int temp = val;
	int idx = 0;
	while(temp > 0)
	{
		digit[idx++] = temp%10;
		temp /= 10;
	}
	int ans = 0;
	for(int i=idx-1; i>=0; i--)
		ans += digit[idx-1-i]*pow(10,i);	
	return ans;
}

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d",rev(rev(a)+rev(b)));
	return 0;
}
