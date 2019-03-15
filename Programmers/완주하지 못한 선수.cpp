#include <string>
#include <vector>
#include <map>
#include <string>

using namespace std;

// participant:참가자 목록,  completion:완주자 목록
// return:완주하지 못한 1인의 이름 
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
