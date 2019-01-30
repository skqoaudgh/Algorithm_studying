#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comp(string a, string b)
{
	int alen = a.size(), blen = b.size();
	int asum = 0, bsum = 0;
	for(int i=0; i<alen; i++)
		if(a[i] >= '0' && a[i] <= '9')
			asum += (a[i]-'0');
	for(int i=0; i<blen; i++)
		if(b[i] >= '0' && b[i] <= '9')
			bsum += (b[i]-'0');		
			
	if(alen == blen)
	{
		if(asum == bsum)
			return a < b;
		else if(asum > bsum)
			return false;
		else
			return true;
	}		
	return alen < blen;
}

int main()
{
	int N;
	string arr[1000];
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> arr[i];
	
	sort(arr,arr+N,comp);
	
	for(int i=0; i<N; i++)
		cout << arr[i] << '\n';
	return 0;
}
