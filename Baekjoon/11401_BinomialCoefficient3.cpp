#include <cstdio>
#include <algorithm>
#define P 1000000007LL
typedef long long ll;
using namespace std;
ll fac[4000001], n, k, inv[4000001];//inv[x]의 정의는 x의inverse가 아닌 x!의 inverse
ll power(ll x, ll y) //분할 정복을 이용하여 x^y 구하기
{    
    ll ret = 1;
    while (y > 0) 
	{
        if (y % 2) 
		{
            ret *= x;
            ret %= P;
        }
        x *= x;
        x %= P;
        y /= 2;
    }
    return ret;
}
int main() 
{
    fac[1] = 1;
    for (int i = 2; i <= 4000000; i++)
        fac[i] = (fac[i - 1] * i) % P;            //factorial 전처리
    inv[4000000] = power(fac[4000000], P - 2);    //페르마의 소정리를 이용하여 fac(400만)의 inverse를 구함(이때 분할 정복을 이용하여 logP의 시간에 처리) 
    for (int i = 4000000 - 1; i > 0; i--) 
        inv[i] = (inv[i + 1] * (i + 1)) % P;    //inverse(fac(i))=inverse(fac(i+1))*(i+1)이라는 수식을 이용하여 전처리
    //총 O(N+logP)시간에 전처리를 끝냄 
    //전처리가 끝났기 때문에 어떤 쿼리가 들어와도 상수시간에 이항 계수를 계산 가능
    scanf("%lld%lld", &n, &k);
    if (n == k || !k) {
        puts("1");
        return 0;
    }
    ll r = (fac[n] * inv[n - k]) % P;
    r = (r*inv[k]) % P;
    printf("%lld\n", r);
    return 0;
}
