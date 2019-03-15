#include <string>
#include <vector>
using namespace std;

bool visited[200];

void func(int n, vector<vector<int>> computers, int idx)
{
    visited[idx] = true;
    printf("%d ¹æ¹®\n",idx);
    for(int i=0; i<n; i++)
    {
        if(visited[i]) continue;
        if(computers[idx][i] == 1)
            func(n, computers, i);         
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {   
            func(n,computers,i);
            answer ++;
        }   
    }
    return answer;
}
