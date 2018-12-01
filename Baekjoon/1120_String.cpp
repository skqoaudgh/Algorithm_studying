#include <iostream>
#include <string>
using namespace std;

int main() {
    string a,b;
    cin >> a >> b;
    int a_size = a.size();
    int b_size = b.size();
    int ans = a_size;
    for(int i=0; i<=b_size-a_size; i++) 
	{
        int k = 0;
        for(int j=0; j<a_size; j++) 
		{
            if(a[j] != b[i+j])
                k++;
        }
        if(ans > k)
            ans = k;
    }
    cout << ans;
    return 0;
}
