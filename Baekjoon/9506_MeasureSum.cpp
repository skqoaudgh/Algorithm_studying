#include <cstdio>
#include <vector>

int main()
{
	while(1)
	{
		std::vector<int> v;
		int N, ans=0;
		scanf("%d",&N);
		if(N == -1)
			break;
		for(int i=1; i<N; i++)
		{
			if(N%i == 0)
			{
				ans += i;
				v.push_back(i);
			}
				
		}
		if(N == ans)
		{
			printf("%d = ",N);
			for(int i=0; i<v.size(); i++)
			{
				printf("%d ",v[i]);
				if(i != v.size()-1)
					printf("+ ");
			}
			printf("\n");			
		}
		else
			printf("%d is NOT perfect.\n",N);
		v.clear();
	}
	return 0;
}
