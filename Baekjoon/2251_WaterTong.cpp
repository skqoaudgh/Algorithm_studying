#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int max_num[3];
bool visited[201][201][201];

struct NODE {
	int amount[3];
	NODE(int _a, int _b, int _c){amount[0]=_a;amount[1]=_b;amount[2]=_c;};
};

NODE GiveAmount(int start, int next, NODE t)
{
	int temp = t.amount[start];
	
	t.amount[start] = t.amount[next] + t.amount[start] - max_num[next];
	if(t.amount[start] < 0) t.amount[start] = 0;
	t.amount[next] += (temp - t.amount[start]);
	return t;
}

int main()
{
	cin >> max_num[0] >> max_num[1] >> max_num[2];
	
	vector<int> v;
	queue<NODE> q;

	visited[0][0][max_num[2]] = true;
	q.push(NODE(0,0,max_num[2]));
	while(!q.empty())
	{
		NODE t = q.front();
		q.pop();
		
		if(t.amount[0] == 0)
			v.push_back(t.amount[2]);
		for(int i=0; i<3; i++)
		{
			for(int j=1; j<=2; j++)
			{
				int next = (i+j)%3;
				NODE newT = GiveAmount(i,next,t);
				if(visited[newT.amount[0]][newT.amount[1]][newT.amount[2]]) continue;
				visited[newT.amount[0]][newT.amount[1]][newT.amount[2]] = true; 
				q.push(newT);
			}
		}
	}
	
	sort(v.begin(),v.end());
	for(int i=0; i<v.size(); i++)
		cout << v[i] << ' ';	
	return 0;
}
