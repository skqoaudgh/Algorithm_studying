#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

bool check(int num)
{
	string str = to_string(num);
	for(int i=0; i<str.size()-2; i++)
	{
		if(str[i] == '6' && str[i+1] == '6' && str[i+2] == '6')
			return true;
	}
	return false;
}

int main()
{
	int N,cnt=0,num=666;
	scanf("%d",&N);
	while(1)
	{
		if(check(num))
		{
			cnt ++;
			if(cnt == N)
				break;
		}
		num++;
	}
	printf("%d",num);
	return 0;
}
