#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
int n;
int op[51];
 
void dfs(int cnt,int pos,vector<bool> &v)
{
    if(cnt>n)
        return ;
 
    else if (cnt == n)
    {
        bool chk = true;
        for (int i = 0; i < n; i++)
        {
            if (op[i] == -1 || op[i]==0)
            {
                chk = false;
                return;
            }
        }
        if (chk)
        {
            for (int i = 0; i < n; i++)
            {
                cout << op[i] << " ";
            }
            cout << "\n";
            exit(0);
        }
    }
 
    string d = "";
    int dtoi;
    for (int i=pos; i<=pos+1; i++)
    {
        d += s[i];
        dtoi = stoi(d);
        if (dtoi <= n && !v[dtoi])
        {
            op[cnt] = dtoi;
            v[dtoi] = true;
            dfs(cnt+1, i+1, v);
            op[cnt] = -1;
            v[dtoi] = false;
        }
    }
}
 
int main()
{
    cin >> s;
    if (s.size() < 10)
        n = s.size();
    else
        n = 9 + (s.size() - 9) / 2;
        
    vector<bool> v(n + 1,false);
    dfs(0,0,v);
    return 0;
}

