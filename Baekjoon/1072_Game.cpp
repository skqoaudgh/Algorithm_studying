#include<algorithm>
#include<stdio.h>
 
#define INT 0x7fff0000
#define MAX_ 1000000001
 
using namespace std;
 
long long int x, y, z; 
long long int left, right;
 
int main() 
{
    while((scanf("%d %d",&x,&y)) != EOF) 
	{
        z = y * 100 / x;
        left = 0;  right = MAX_;
        int ans = z;
        while (left <= right) 
		{
            long long int mid = (left + right) >> 1;
            long long int per = (y + mid) * 100 / (x + mid);
            if (per > z)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (left >= MAX_)
           	printf("-1\n");
        else
            printf("%d\n",left);
    }
    return 0;
}
