#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getFirstNumber(int num)
{
    int ans;
    while(num > 0)
    {
        ans = num % 10;
        num /= 10;
    }
    return ans;
}

bool comp(string a, string b)
{
    string ab = a+b;
    string ba = b+a;
    return ab>ba;
}

string solution(vector<int> numbers) {
    string answer;
    vector<string> v;
    int zero_count = 0;
    for(int i=0; i<numbers.size(); i++)
    {
        if(numbers[i] == 0)
            zero_count ++;
        v.push_back(to_string(numbers[i]));
    }
    
    if(zero_count == numbers.size())
        return "0";
    
    sort(v.begin(),v.end(),comp);
    for(int i=0; i<v.size(); i++)
        answer += v[i];
    return answer;
}
