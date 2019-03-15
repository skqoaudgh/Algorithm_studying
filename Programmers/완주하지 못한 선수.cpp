#include <string>
#include <vector>
#include <map>
#include <string>

using namespace std;

// participant:������ ���,  completion:������ ���
// return:�������� ���� 1���� �̸� 
string solution(vector<string> participant, vector<string> completion) {
    map<string, int> m;
    string answer;
    
    for(int i=0; i<participant.size(); i++)
        m[participant[i]] ++;
    for(int i=0; i<completion.size(); i++)
        m[completion[i]] --;
    
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        if(it->second == 1)
        {
            answer = it->first;
            break;
        }
    }
    return answer;
}
