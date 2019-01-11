#include <stdio.h>
#include <cstring>
#include <cmath>

int getNumber(const char* str)
{
	int num = 0;
	for(int i=0; i<strlen(str); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			num += (str[i]-'a'+1);
		else if(str[i] >= 'A' && str[i] <= 'Z')
			num += (str[i]-'A'+27);
	}
	return num;
}

int isPrime(int num)
{
	if(num == 1 || num == 2)
		return 1;
	for(int i=2; i<num; i++)
	{
		if(num%i == 0)
			return 0;
	}
	return 1;
}

int main()
{
	char str[21];
	scanf("%s",str);
	int ans = isPrime(getNumber(str));
	if(ans == 1)
		printf("It is a prime word.");
	else
		printf("It is not a prime word.");
	return 0;
}
