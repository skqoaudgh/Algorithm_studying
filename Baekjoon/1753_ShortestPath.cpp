#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_V = 20000;
const int INF = 1000000000;
typedef pair<int, int> P;
 
int main(){
    int V, E, K;
    vector<P> adj[MAX_V]; // (�̾��� ���� ��ȣ, �Ÿ�)
    scanf("%d %d %d", &V, &E, &K);
    K--;
    for(int i=0; i<E; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u-1].push_back(P(v-1, w));
    }
 
    int dist[MAX_V];
    fill(dist, dist+MAX_V, INF);
    bool visited[MAX_V] = {0};
    priority_queue<P, vector<P>, greater<P>> PQ;
 
    // ���ͽ�Ʈ�� �˰���
    dist[K] = 0; // ������������ �Ÿ��� 0
    PQ.push(P(0, K)); // �������� PQ�� �ְ� ����
    while(!PQ.empty()){ // PQ�� ��� ����
        int curr;
        do{
            curr = PQ.top().second;
            PQ.pop();
        }while(!PQ.empty() && visited[curr]); // curr�� �湮�� �����̸� ����
        // �� �̻� �湮�� �� �ִ� ������ ������ ����
        if(visited[curr]) break;
 
        visited[curr] = true; // �湮
        for(auto &p: adj[curr]){
            int next = p.first, d = p.second;
            // �Ÿ��� ���ŵ� ��� PQ�� ���� ����
            if(dist[next] > dist[curr] + d){
                dist[next] = dist[curr] + d;
                PQ.push(P(dist[next], next));
            }
        }
    }
 
    // ���
    for(int i=0; i<V; i++){
        if(dist[i] == INF) puts("INF");
        else printf("%d\n", dist[i]);
    }
    return 0;
}


