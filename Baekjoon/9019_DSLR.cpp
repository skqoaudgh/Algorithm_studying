#include <iostream>
#include <queue>
using namespace std;

struct NODE {
	int num,cnt;
	string order;
	NODE(int _num, string _order, int _cnt){num=_num;order=_order;cnt=_cnt;};
};
bool visited[10001];

int D(int num)
{
	int temp = num*2;
	if(temp > 9999)
		temp = temp%10000;
	return temp;
}

int S(int num)
{
	int tmp = num-1;
	if(tmp == -1)
		tmp = 9999;
	return tmp;
}

int L(int num)
{
	int temp = (num%1000) * 10;
	temp += num/1000;
	return temp;
}

int R(int num)
{
	int temp = num/10;
	temp += (num%10)*1000;
	return temp;
}

int main() 
{
	int T;
	cin >> T;
	for(int test_case=0; test_case<T; test_case++)
	{
		for(int i=0; i<10000; i++)
			visited[i] = false;
			
		int A,B;
		cin >> A >> B;
		
		queue<NODE> q;
		q.push(NODE(A,"",0));
		int num = 987654321;
		string ans;
		while(!q.empty())
		{
			NODE t = q.front();
			q.pop();
			if(t.num == B)
			{
				//cout << "sad";
				if(num > t.cnt)
				{
					num = t.cnt;
					ans = t.order;
				}
				break;
			}
					
			int temp;
			string str;
			for(int i=0; i<4; i++)
			{
				switch(i)
				{
					case 0:{
						temp = D(t.num);
						str = "D";
						break;
					}
					case 1:{
						temp = S(t.num);
						str = "S";
						break;
					}
					case 2:{
						temp = L(t.num);
						str = "L";
						break;
					}
					case 3:{
						temp = R(t.num);
						str = "R";
						break;
					}															
				}
				if(temp >= 10000) continue;
				if(visited[temp]) continue;
				visited[temp] = true;
				q.push(NODE(temp,t.order+str,t.cnt+1));
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
