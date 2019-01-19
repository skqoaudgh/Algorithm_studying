#include <stdio.h>
#include <set>
using namespace std;

int gcd(int a, int b)
{
	while(b!=0)
	{
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main()
{
	int arr[5];
	int arr2[10],idx=0,ans=987654321;
	for(int i=0; i<5; i++)
		scanf("%d",&arr[i]);
		
	for(int i=0; i<4; i++)
	{
		for(int j=i+1; j<5; j++)
		{
			arr2[idx++] = lcm(arr[i],arr[j]);
			for(int t=0; t<5; t++)
			{
				if(t == i || t == j) continue;
				{
					int temp = lcm(arr2[idx-1],arr[t]);
					if(ans > temp)
						ans = temp;
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
}
