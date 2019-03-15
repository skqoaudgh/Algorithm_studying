#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// phone_book: 전화번호부에 저장된 번호 목록
// return:한 번호가 다른 번호의 접두어면 false, 아니면 true 
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++)
    {
        if(phone_book[i].size() < phone_book[i+1].size())
        {
            if(phone_book[i+1].find(phone_book[i]) != std::string::npos) return false;
        }
    }
    return true;
}
