#include <iostream>
#include <cstdlib>
using namespace std;
 
const int MAX_LUCKY_COUNT = 51;
int lucky[MAX_LUCKY_COUNT] = {0};
int compare(const void *pd1, const void *pd2) 
{
    typedef const int *cip;
    cip p1 = (cip)pd1, p2 = (cip)pd2;
    return *p1 - *p2;
}
 
int main(void) {
    int l;
     
    cin>>l;
    for (int i=1; i<=l; ++i) 
        cin >> lucky[i];
    qsort(lucky, l+1, sizeof(int), compare);
     
    int n;
    cin>>n;
    int prev, last;
    for (int i=1; i<=l; ++i) 
	{
        if (n <= lucky[i]) 
		{
            last = lucky[i];
            prev = lucky[i-1];
            break;
        }
    }
	if (n <= prev || last <= n) 
	{
    	cout << 0;
    	return 0;
    }
    int result = (n - prev) * (last - n) - 1;
    cout << result;
    return 0;
}
