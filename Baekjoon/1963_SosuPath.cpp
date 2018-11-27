#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

bool visited[10000];
int isPrime[10000];

struct NODE {
	string num;
	int cnt;
	NODE(string N, int C) {num=N;cnt=C;};
};

void getAllPrime()
{
	isPrime[0] = 1;
	isPrime[1] = 1;
	for(int i=0; i<10000; i++)
	{
		if(isPrime[i] == 1) continue;
		for(int j=i*2; j<10000; j+=i)
			isPrime[j] = 1;
	}
}

bool checkPrime(string _num)
{
	int num = stoi(_num);
	if(isPrime[num] == 0)
		return true;
	return false;
}

int main()
{
	int t;
	string src_num, dest_num;
	cin >> t;
	getAllPrime();
	for(int test_case=0; test_case<t; test_case++)
	{
		for(int i=0; i<10000; i++)
			visited[i] = false;
		int ans = 987654321;
		cin >> src_num >> dest_num;
		queue<NODE> q;
		q.push(NODE(src_num,0));
		while(!q.empty())
		{
			NODE t = q.front();
			q.pop();
			
			if(t.num == dest_num)
				if(ans > t.cnt)
					ans = t.cnt;
					
			string tmp = t.num;
			int tmp_num = stoi(tmp);
			if(tmp_num < 1000) continue;
			for(int i=0; i<4; i++)
			{
				for(int j=0; j<10; j++)
				{
					string tp = tmp;
					tp[i] = '0'+j;
					int tmp_num2 = stoi(tp);
					if(tmp_num2 >= 1000 && checkPrime(tp) && !visited[tmp_num2])
					{
						visited[stoi(tp)] = true;
						q.push(NODE(tp,t.cnt+1));
						//cout << tp << ' ';
					}
				}
			}
		}
		
		if(ans == 987654321)
			cout << "Impossible\n";
		else
			cout << ans << '\n';
	}
	return 0;
}
