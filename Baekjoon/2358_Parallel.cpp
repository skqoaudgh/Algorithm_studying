#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool compX(pair<int,int> a, pair<int,int> b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
bool compY(pair<int,int> a, pair<int,int> b)
{
	if(a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main(void) 
{
	vector< pair<int,int> > v;
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back(make_pair(a,b));
	}
	
	int cnt = 0;
	sort(v.begin(),v.end(),compX);
	bool flag = false;
	for(int i=1; i<n; i++)
	{
		if(i-1 >= 0)
		{
			int first = v[i-1].first;
			int second = v[i-1].second;		
			if(v[i].first == first && second <= v[i].second)
			{
				cnt ++;
				do{
					i++;
					flag = true;
				} while(i<n && v[i].first == first);
				i--;
			}
		}
	}

	flag = false;
	sort(v.begin(),v.end(),compY);
	for(int i=1; i<n; i++)
	{
		if(i-1 >= 0)
		{
			int first = v[i-1].first;
			int second = v[i-1].second;		
			if(v[i].first >= first && second == v[i].second)
			{
				cnt ++;
				do{
					i++;
					flag = true;
				} while(i<n && v[i].second == second);
				i--;
			}			
		}
	}
	printf("%d",cnt);
    return 0;
}
