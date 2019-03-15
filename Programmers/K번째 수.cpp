#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int t=0; t<commands.size(); t++)
    {
        vector<int> arr;
        for(int i=commands[t][0]-1; i<commands[t][1]; i++)
            arr.push_back(array[i]);
        sort(arr.begin(),arr.end());
        answer.push_back(arr[commands[t][2]-1]);
    }
    return answer;
}
