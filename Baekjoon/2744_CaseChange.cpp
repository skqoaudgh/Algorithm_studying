#include <stdio.h>
#include <cstring>

int main()
{
	char str[101];
	scanf("%s",str);
	for(int i=0; i<strlen(str); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else
			str[i] += 32;
	}
	printf("%s",str);
	return 0;
}
