#include <stdio.h>
 
long long int a, b, c;
int result = 0;
long long int func(long long int x, long long int m) 
{
    if (m == 0)
        return 1;
    else if (m == 1)
        return x;
    if (m % 2 > 0)
        return func(x, m - 1)*x;
    long long int half = func(x, m / 2)%c;
    return (half * half) % c;
}
 
int main() 
{
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld", func(a, b) % c);
    return 0;
}

