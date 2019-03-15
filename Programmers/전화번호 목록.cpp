#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// phone_book: ��ȭ��ȣ�ο� ����� ��ȣ ���
// return:�� ��ȣ�� �ٸ� ��ȣ�� ���ξ�� false, �ƴϸ� true 
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
