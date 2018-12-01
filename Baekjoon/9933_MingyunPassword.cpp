#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[101];
string reverse_arr[101];
int N;

pair<int,char> func()
{
	for(int i=0; i<N-1; i++)
		for(int j=i; j<N; j++)
		{
			if(arr[i] == reverse_arr[j])
			{
				char ch = arr[i][arr[i].size()/2];
				return make_pair(i,ch);
			}
		}
}

int main() 
{
    cin >> N;
	for(int i=0; i<N; i++)
	{
		cin >> arr[i];
		reverse_arr[i] = arr[i];
		reverse(reverse_arr[i].begin(), reverse_arr[i].end());
	}

	pair<int,char> ans = func();
	cout << arr[ans.first].size() << ' ' << ans.second;	
    return 0;
}
