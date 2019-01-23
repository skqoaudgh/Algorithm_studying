#include <iostream>
#include <map>
#include <string>
using namespace std;

#define MAX 100
#define INF 987654321

string tye[] = {
	"Subway", "Bus", "Taxi", "Airplane", "KTX", "S-Train", "V-Train", "ITX-Saemaeul", "ITX-Cheongchun", "Mugunghwa"
};
int type[] = {0,0,0,0,0,2,2,1,1,1};

typedef pair<int, int> P;

int main()
{
	int idx=0;
	map<string,int> m2;
	for(int i=0; i<10; i++)
		m2[tye[i]] = idx++;
	//-----
	int N,R,M,K;
	int path[200];
	P distA[MAX][MAX];
	P distB[MAX][MAX];
	map<string,int> m;
	cin >> N >> R;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			distA[i][j] = P(0,INF);
			distB[i][j] = P(0,INF);				
		}		
	idx = 0;
	for(int i=0; i<N; i++)
	{
		string city;
		cin >> city;
		m[city] = idx++;
	}
	cin >> M;
	idx = 0;
	for(int i=0; i<M; i++)
	{
		string city;
		cin >> city;
		path[idx++] = m[city];
	}
	cin >> K;
	for(int i=0; i<K; i++)
	{
		string ty, S, E;
		int W;
		cin >> ty >> S >> E >> W;
		if(distA[m[S]][m[E]].second != INF)
		{
			if(distA[m[S]][m[E]].first == 1 || (distA[m[S]][m[E]].first == 2 && distA[m[S]][m[E]].second > W/2))
			{
				distA[m[S]][m[E]] = P(type[m2[ty]],W);
				distA[m[E]][m[S]] = P(type[m2[ty]],W);
			}
			if(distA[m[S]][m[E]].second > W)
			{
				distA[m[S]][m[E]] = P(type[m2[ty]],W);
				distA[m[E]][m[S]] = P(type[m2[ty]],W);				
			}
		}
		else
		{
			distA[m[S]][m[E]] = P(type[m2[ty]],W);
			distB[m[S]][m[E]] = P(type[m2[ty]],W);
			
			distA[m[E]][m[S]] = P(type[m2[ty]],W);
			distB[m[E]][m[S]] = P(type[m2[ty]],W);			
		}
	}
	
	// 내일로 적용 전 가격
	int sum_a = 0;
	for(int t=0; t<N; t++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(distA[i][j].second > distA[i][t].second+distA[t][j].second)
					distA[i][j].second = distA[i][t].second+distA[t][j].second;
	
	for(int i=0; i<M-1; i++)
		sum_a += distA[path[i]][path[i+1]].second;		
	
	// 내일로 적용 후 가격
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(distB[i][j].first == 1)
				distB[i][j].second = 0;			
			else if(distB[i][j].first == 2)
				distB[i][j].second /= 2;	
		}
	}

	int sum_b = 0;
	for(int t=0; t<N; t++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(distB[i][j].second > distB[i][t].second+distB[t][j].second)
					distB[i][j].second = distB[i][t].second+distB[t][j].second;

	for(int i=0; i<M-1; i++)
		sum_b += distB[path[i]][path[i+1]].second;	
				
	if(sum_a > sum_b + R)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
