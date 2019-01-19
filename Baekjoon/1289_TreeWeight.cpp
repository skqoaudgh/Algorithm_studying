#include<stdio.h>
#include<vector>
#define mod 1000000007
using namespace std;

typedef long long ll;
const int MAX_N = 1e5;
vector<pair<int, int> > adj[MAX_N + 1];
int n, res;

int dfs(int h, int p) 
{
    int s = 1, t;
    for (auto it : adj[h]) 
	{
        if (it.first == p) continue;
        t = (ll)dfs(it.first, h)*it.second%mod;
        res = (res + (ll)t*s) % mod;
        s = (s + t) % mod;
    }
    return s;
}

int main() 
{
    scanf("%d", &n);
    for (int i = 0, a, b, c; i < n - 1; i++) 
	{
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({ b,c });
        adj[b].push_back({ a,c });
    }
    dfs(1, -1);
    printf("%d", res);
    return 0;
}
