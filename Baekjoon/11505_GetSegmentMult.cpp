#include <cstdio>

long long int arr[2100000];

void construct(int Size)
{
	for(int i=Size-1; i>0; i--)
	{
		arr[i] = (arr[i*2] * arr[i*2+1]) % 1000000007;
	}		
}

long long int mult(int L, int R, int nodeNum, int nodeL, int nodeR)
{
    if(R < nodeL || nodeR < L) return 1;
    if(L <= nodeL && nodeR <= R) return arr[nodeNum] % 1000000007;
    int mid = (nodeL + nodeR) / 2;
    return ( mult(L, R, nodeNum*2, nodeL, mid) % 1000000007 * mult(L, R, nodeNum*2+1, mid+1, nodeR) % 1000000007 ) % 1000000007;
}

void update(int i, int val, int size)
{
	i += size;
	arr[i] = val;
	while(i > 1)
	{
		i /= 2;
		arr[i] = (arr[i*2] * arr[i*2+1]) % 1000000007;
	}
}

int main() 
{
	int RN,N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	for(RN=1; RN<N; RN*=2);
	
	for(int i=0; i<=2*RN+1; i++)
		arr[i] = 1;
		
	for(int i=0; i<N; i++) 
		scanf("%lld",&arr[i+RN]);
				
	construct(RN);
	
	for(int i=0; i<M+K; i++)
	{
		long long int a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a == 1)
		{
			update(b-1,c,RN);						
		}
		else
		{
			printf("%lld\n",mult(b-1, c-1, 1, 0, RN-1));
		}
	}
	return 0;
}
