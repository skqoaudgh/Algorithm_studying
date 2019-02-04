#include <cstdio>

long long int arr[2100000];

void construct(int Size)
{
	for(int i=Size-1; i>0; i--)
	{
		arr[i] = arr[i*2] + arr[i*2+1];
	}		
}

long long int mult(int L, int R, int nodeNum, int nodeL, int nodeR)
{
    if(R < nodeL || nodeR < L) return 0;
    if(L <= nodeL && nodeR <= R) return arr[nodeNum];
    int mid = (nodeL + nodeR) / 2;
    return mult(L, R, nodeNum*2, nodeL, mid) + mult(L, R, nodeNum*2+1, mid+1, nodeR);
}

void update(int i, int val, int size)
{
	i += size;
	arr[i] = val;
	while(i > 1)
	{
		i /= 2;
		arr[i] = arr[i*2] + arr[i*2+1];
	}
}

int main() 
{
	int RN,N,Q;
	scanf("%d %d",&N,&Q);
	for(RN=1; RN<N; RN*=2);

	for(int i=0; i<Q; i++)
	{
		long long int a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(a == 1)
		{
			update(b-1,c,RN);
		}
		else
		{
			if(b > c)
			{
				long long int temp = b;
				b = c;
				c = temp;
			}
			printf("%lld\n",mult(b-1, c-1, 1, 0, RN-1));
		}
	}
	return 0;
}
