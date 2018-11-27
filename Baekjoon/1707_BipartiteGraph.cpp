#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> arr[20001];
int partition[20001];
int V, E;
int ans = 0;

bool isPartite(vector<int> *arr, int V)
{
	queue<int> q;
	for(int i=0; i<V; i++)
	{
		if(partition[i] != 0) continue;
		q.push(i);
		partition[i] = 1;
		while(!q.empty())
		{
			int t = q.front();
			q.pop();
			
			for(int j=0; j<arr[t].size(); j++)
			{
				int next = arr[t][j];
				if(partition[next] == 0) 
				{
					partition[next] = 3-partition[t];
					q.push(next);
				}
				else if(partition[next] == partition[t]) return false;
				
			}	
		}
	}
	return true;
}

int main() 
{
	int K;
	cin >> K;
	for(int test_case=0; test_case<K; test_case++)
	{
		ans = 0;
		int V, E;
		cin >> V >> E;
		
		for(int i=0; i<V; i++)
		{
			partition[i] = 0;
			arr[i].clear();
		}
				
        for (int i=0; i<E; i++) {
            int u, v;
            cin >> u >> v;
            arr[u-1].push_back(v-1);
            arr[v-1].push_back(u-1);
        }		
        
		if(isPartite(arr,V))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
