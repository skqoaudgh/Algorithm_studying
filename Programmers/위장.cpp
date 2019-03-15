#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

// clothes:�������� (�ǻ� �̸�, �ǻ� ����) 2���� �迭 
// return:�������� �� �ִ� �ǻ� ��Ʈ�� �� 
int solution(vector<vector<string>> clothes) {
    int answer = 1, count = 0;
    map<string, int> m;
    //-----
    for(int i=0; i<clothes.size(); i++)
    {
        m[clothes[i][1]] ++;
        if(m[clothes[i][1]] == 1)
            count ++;
    } 

    for(auto it=m.begin(); it!=m.end(); it++)
        answer *= (it->second+1);
    answer --;  

    return answer;
}
